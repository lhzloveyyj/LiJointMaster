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
    rxBuffer.append(data); // 缓存数据

    while (rxBuffer.size() >= 5)
    {
        // 1️⃣ 查找帧头
        int headIndex = rxBuffer.indexOf(char(0xA5));
        if (headIndex < 0) {
            rxBuffer.clear();
            return;
        }

        // 2️⃣ 不够一个最小帧则等待
        if (rxBuffer.size() - headIndex < 5)
            return;

        // 3️⃣ 获取数据长度并计算帧总长度
        uint8_t len = uint8_t(rxBuffer[headIndex + 2]);
        int frameSize = 5 + len;

        // 4️⃣ 如果缓存不够完整帧，等待下一次
        if (rxBuffer.size() - headIndex < frameSize)
            return;

        // 5️⃣ 截取一帧数据
        QByteArray frame = rxBuffer.mid(headIndex, frameSize);
        rxBuffer.remove(0, headIndex + frameSize);

        uint8_t cmd = uint8_t(frame[1]);
        QByteArray dataBytes = frame.mid(3, len);

        // 6️⃣ 将数据按 float 拆分
        int floatCount = len / 4;
        QVector<float> values;
        for (int i = 0; i < floatCount; i++) {
            float v = bytesToFloat(dataBytes, i * 4);
            values.append(v);
        }

        // 7️⃣ 根据命令处理数据
        switch (CMD_TypeDef(cmd)) {

        case CMD_TypeDef::CMD_CONNECT_MOTOR:
            if (!values.isEmpty()) {
                getPairs      = int(values[0]);
                dir           = int(values[1]);
                g_zeroOffset  = values[2];
                qDebug() << "连接成功！";
                emit commandParsed(CMD_TypeDef::CMD_CONNECT_MOTOR);
            }
            break;

        case CMD_TypeDef::CMD_MECHANICALANGLE:
            if (!values.isEmpty()) {
                mechanicalAngle = values[0];
                qDebug() << "Mechanical Angle:" << mechanicalAngle;
            }
            break;

        case CMD_TypeDef::CMD_ZEROCALIBRATIO_OVER:
            if (!values.isEmpty()) {
                g_zeroOffset           = values[0];
                g_correctedElecAngle   = values[1];
                qDebug() << "校准结束";
            }
            emit zeroCalibrationFinished();
            break;

        case CMD_TypeDef::CMD_UABC:
            if (!values.isEmpty()) {
                Ua = values[0];
                Ub = values[1];
                Uc = values[2];
                emit newUABC(Ua, Ub, Uc);
            }
            break;

        case CMD_TypeDef::CMD_ADC:
            if (!values.isEmpty()) {
                ADC1 = values[0];
                ADC2 = values[1];
                ADC3 = values[2];
                emit newADC(ADC1, ADC2, ADC3);
            }
            break;

        case CMD_TypeDef::CMD_DCVBUS:
            if (!values.isEmpty()) {
                dcVbus = values[0];
            }
            break;

        case CMD_TypeDef::CMD_TABC:
            if (!values.isEmpty()) {
                Ta = values[0];
                Tb = values[1];
                Tc = values[2];
                emit newTABC(Ta, Tb, Tc);
            }
            break;

        case CMD_TypeDef::CMD_IABC:
            if (!values.isEmpty()) {
                Ia = values[0];
                Ib = values[1];
                Ic = values[2];
                emit newIABC(Ia, Ib, Ic);
            }
            break;

        case CMD_TypeDef::CMD_UALPHA_BETA:
            if (!values.isEmpty()) {
                Ualpha = values[0];
                Ubeta  = values[1];
                emit newUalpha_Ubeta(Ualpha, Ubeta);
            }
            break;

        case CMD_TypeDef::CMD_IALPHA_BETA:
            if (!values.isEmpty()) {
                Ialpha = values[0];
                Ibeta  = values[1];
                emit newIalpha_Ibeta(Ialpha, Ibeta);
            }
            break;

        case CMD_TypeDef::CMD_IQ_ID:
            if (!values.isEmpty()) {
                Iq = values[0];
                Id = values[1];
                emit newIqId(Iq, Id);
            }
            break;

        case CMD_TypeDef::CMD_MOSTEMP:
            if (!values.isEmpty()) {
                mosTemp = values[0];
            }
            break;

        default:
            qWarning() << "Unknown CMD:" << cmd << "Values:" << values;
            break;
        }
    }
}
