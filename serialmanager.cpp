#include "serialmanager.h"
#include <QDebug>

/**
 * @brief 构造函数
 * @param parent 父对象
 *
 * 初始化 QSerialPort。
 */
SerialManager::SerialManager(QObject *parent)
    : QObject(parent)
{
    serialPort = new QSerialPort(this);
}

/**
 * @brief 析构函数
 *
 * 如果串口还打开，则关闭。
 */
SerialManager::~SerialManager()
{
    if (serialPort->isOpen())
        serialPort->close();
}

/**
 * @brief 获取可用串口列表
 * @return QStringList 串口名称列表
 */
QStringList SerialManager::availablePorts()
{
    QStringList ports;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        ports << info.portName();
    return ports;
}

/**
 * @brief 打开串口
 * @param portName 串口名称
 * @param baudRate 波特率
 * @param dataBits 数据位
 * @param stopBits 停止位
 * @param parity 校验位
 * @return true 打开成功, false 打开失败
 */
bool SerialManager::openPort(const QString &portName,
                             qint32 baudRate,
                             QSerialPort::DataBits dataBits,
                             QSerialPort::StopBits stopBits,
                             QSerialPort::Parity parity)
{
    // 如果串口已打开，先关闭
    if (serialPort->isOpen())
        serialPort->close();

    // 设置串口参数
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(parity);

    // 打开串口
    if (!serialPort->open(QIODevice::ReadWrite))
        return false;

    // 连接 readyRead 信号，当串口有数据时触发 readSerialData
    connect(serialPort, &QSerialPort::readyRead,
            this, &SerialManager::readSerialData);

    emit portOpened(); // 发出串口已打开信号
    return true;
}

/**
 * @brief 关闭串口
 */
void SerialManager::closePort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        emit portClosed(); // 发出串口已关闭信号
    }
}

/**
 * @brief 判断串口是否已打开
 * @return true 已打开, false 未打开
 */
bool SerialManager::isOpen() const
{
    return serialPort->isOpen();
}

/**
 * @brief 发送浮点数命令
 * @param cmd 命令枚举
 * @param value 浮点数数据
 *
 * 将浮点数打包成自定义帧发送到串口。
 */
void SerialManager::sendFloatCommand(CMD_TypeDef cmd, float value)
{
    if (!serialPort || !serialPort->isOpen()) return;

    QByteArray frame;          // 串口发送帧
    uint8_t header = FRAME_HEAD;
    uint8_t tail   = FRAME_TAIL;

    // 1️⃣ 将 float 转为 4 字节
    QByteArray dataBytes;
    dataBytes.append(reinterpret_cast<const char*>(&value), sizeof(float));

    // 2️⃣ 校验和 = header + cmd + 数据字节
    uint8_t checksum = header + static_cast<uint8_t>(cmd) +
                       static_cast<uint8_t>(dataBytes[0]) +
                       static_cast<uint8_t>(dataBytes[1]) +
                       static_cast<uint8_t>(dataBytes[2]) +
                       static_cast<uint8_t>(dataBytes[3]);

    // 3️⃣ 组完整帧
    frame.append(static_cast<char>(header));
    frame.append(static_cast<char>(cmd));
    frame.append(dataBytes);
    frame.append(static_cast<char>(checksum));
    frame.append(static_cast<char>(tail));

    // 4️⃣ 发送到串口
    serialPort->write(frame);
}

/**
 * @brief 将 4 字节 QByteArray 转为 float
 * @param data 4 字节数据
 * @return float 转换后的浮点数
 */
float bytesToFloat(const QByteArray &data)
{
    if (data.size() != 4)
        return 0.0f;

    float value;
    uint8_t buf[4];
    buf[0] = static_cast<uint8_t>(data[0]);
    buf[1] = static_cast<uint8_t>(data[1]);
    buf[2] = static_cast<uint8_t>(data[2]);
    buf[3] = static_cast<uint8_t>(data[3]);

    memcpy(&value, buf, sizeof(float));
    return value;
}

/**
 * @brief 将 QByteArray 指定索引的 4 字节转为 float
 * @param data 数据数组
 * @param index 起始索引
 * @return float 转换后的浮点数
 */
float bytesToFloat(const QByteArray &data, int index)
{
    if (data.size() < index + 4)
        return 0.0f;

    float value;
    memcpy(&value, data.constData() + index, sizeof(float));
    return value;
}

/**
 * @brief 串口数据接收处理函数
 *
 * 解析自定义帧，提取命令和浮点数数据，并发射对应信号。
 */
void SerialManager::readSerialData()
{
    QByteArray data = serialPort->readAll();
    if (data.isEmpty())
        return;

    rxBuffer.append(data);

    constexpr int MAX_PAYLOAD_LEN = 128;   // 最大 16 个 float，自行调整

    while (rxBuffer.size() >= 5)
    {
        // 1️⃣ 找帧头
        int headIndex = rxBuffer.indexOf(char(FRAME_HEAD));
        if (headIndex < 0) {
            // 只保留最后 1 个字节，防止帧头被截断
            rxBuffer.remove(0, rxBuffer.size() - 1);
            return;
        }

        // 2️⃣ 不够最小帧长度
        if (rxBuffer.size() - headIndex < 5)
            return;

        // 3️⃣ 读取长度
        uint8_t len = uint8_t(rxBuffer[headIndex + 2]);

        // 长度合法性校验
        if (len == 0 || len > MAX_PAYLOAD_LEN || (len % 4) != 0) {
            rxBuffer.remove(0, headIndex + 1);
            continue;
        }

        int frameSize = 5 + len;

        // 4️⃣ 缓冲区不够一整帧
        if (rxBuffer.size() - headIndex < frameSize)
            return;

        // 5️⃣ 取出完整帧
        QByteArray frame = rxBuffer.mid(headIndex, frameSize);

        // 6️⃣ 校验帧尾
        if (uint8_t(frame[frameSize - 1]) != FRAME_TAIL) {
            rxBuffer.remove(0, headIndex + 1);
            continue;
        }

        // 7️⃣ 校验和
        uint8_t checksum = 0;
        for (int i = 0; i < frameSize - 2; i++)
            checksum += uint8_t(frame[i]);

        if (checksum != uint8_t(frame[frameSize - 2])) {
            rxBuffer.remove(0, headIndex + 1);
            continue;
        }

        // ✅ 到这里，帧 100% 正确
        rxBuffer.remove(0, headIndex + frameSize);

        // ================== 解析数据 ==================

        uint8_t cmd = uint8_t(frame[1]);
        QByteArray dataBytes = frame.mid(3, len);

        int floatCount = len / 4;
        QVector<float> values;
        values.reserve(floatCount);

        for (int i = 0; i < floatCount; i++) {
            float v = bytesToFloat(dataBytes, i * 4);
            values.append(v);
        }

        // ================== 分发命令 ==================
        switch (CMD_TypeDef(cmd)) {

        case CMD_TypeDef::CMD_CONNECT_MOTOR:
            if (values.size() >= 9) {
                getPairs      = int(values[0]);
                dir           = int(values[1]);
                g_zeroOffset  = values[2];
                iqPID_kp      = values[3];
                iqPID_ki      = values[4];
                dcVbus        = values[5];
                speedDir      = values[6];
                speedPID_kp   = values[7];
                speedPID_ki   = values[8];
                localPID_kp   = values[9];
                localPID_kd   = values[10];
                iqPID_outMax  = values[11];
                speedPID_outMax = values[12];
                localPID_outMax = values[13];

                emit commandParsed(CMD_TypeDef::CMD_CONNECT_MOTOR);
            }
            break;

        case CMD_TypeDef::CMD_MECHANICALANGLE:
            if (values.size() >= 1) {
                mechanicalAngle = values[0];
                emit newmechanicalAngle(mechanicalAngle);
            }
            break;

        case CMD_TypeDef::CMD_ZEROCALIBRATIO_OVER:
            if (values.size() >= 2) {
                g_zeroOffset         = values[0];
                g_correctedElecAngle = values[1];
                emit zeroCalibrationFinished();
            }
            break;

        case CMD_TypeDef::CMD_UABC:
            if (values.size() >= 3) {
                Ua = values[0];
                Ub = values[1];
                Uc = values[2];
                emit newUABC(Ua, Ub, Uc);
            }
            break;

        case CMD_TypeDef::CMD_ADC:
            if (values.size() >= 3) {
                ADC1 = values[0];
                ADC2 = values[1];
                ADC3 = values[2];
                emit newADC(ADC1, ADC2, ADC3);
            }
            break;

        case CMD_TypeDef::CMD_DCVBUS:
            if (values.size() >= 1) {
                dcVbus = values[0];
            }
            break;

        case CMD_TypeDef::CMD_TABC:
            if (values.size() >= 3) {
                Ta = values[0];
                Tb = values[1];
                Tc = values[2];
                emit newTABC(Ta, Tb, Tc);
            }
            break;

        case CMD_TypeDef::CMD_IABC:
            if (values.size() >= 3) {
                Ia = values[0];
                Ib = values[1];
                Ic = values[2];
                emit newIABC(Ia, Ib, Ic);
            }
            break;

        case CMD_TypeDef::CMD_UALPHA_BETA:
            if (values.size() >= 2) {
                Ualpha = values[0];
                Ubeta  = values[1];
                emit newUalpha_Ubeta(Ualpha, Ubeta);
            }
            break;

        case CMD_TypeDef::CMD_IALPHA_BETA:
            if (values.size() >= 2) {
                Ialpha = values[0];
                Ibeta  = values[1];
                emit newIalpha_Ibeta(Ialpha, Ibeta);
            }
            break;

        case CMD_TypeDef::CMD_IQ_ID:
            if (values.size() >= 2) {
                Iq = values[0];
                Id = values[1];
                emit newIqId(Iq, Id);
            }
            break;

        case CMD_TypeDef::CMD_MOSTEMP:
            if (values.size() >= 1) {
                mosTemp = values[0];
            }
            break;

        case CMD_TypeDef::CMD_SPEED:
            if (values.size() >= 1) {
                speed = values[0];
                emit newSpeed(speed);
            }
            break;

        case CMD_TypeDef::CMD_SPEEDOUT:
            if (values.size() >= 1) {
                speedOut = values[0];
                emit newSpeedOut(speedOut);
            }
            break;

        case CMD_TypeDef::CMD_LOCAL:
            if (values.size() >= 1) {
                local = values[0];
                emit newLocal(local);
            }
            break;

        case CMD_TypeDef::CMD_LOCALOUT:
            if (values.size() >= 1) {
                localOut = values[0];
                emit newLocalOut(localOut);
            }
            break;

        default:
            qWarning() << "Unknown CMD:" << cmd;
            break;
        }
    }
}


