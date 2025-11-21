#include "serialmanager.h"
#include <QDebug>


SerialManager::SerialManager(QObject *parent)
    : QObject(parent)
{
    serialPort = new QSerialPort(this);
}

SerialManager::~SerialManager()
{
    if (serialPort->isOpen())
        serialPort->close();
}

QStringList SerialManager::availablePorts()
{
    QStringList ports;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        ports << info.portName();
    return ports;
}

bool SerialManager::openPort(const QString &portName,
                             qint32 baudRate,
                             QSerialPort::DataBits dataBits,
                             QSerialPort::StopBits stopBits,
                             QSerialPort::Parity parity)
{
    if (serialPort->isOpen())
        serialPort->close();

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(parity);

    if (!serialPort->open(QIODevice::ReadWrite))
        return false;

    // ⚡ 在这里连接 readyRead 信号
    connect(serialPort, &QSerialPort::readyRead,
            this, &SerialManager::readSerialData);

    emit portOpened();
    return true;
}

void SerialManager::closePort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        emit portClosed();
    }
}

bool SerialManager::isOpen() const
{
    return serialPort->isOpen();
}


void SerialManager::sendFloatCommand(CMD_TypeDef cmd, float value)
{
    if (!serialPort || !serialPort->isOpen()) return;

    QByteArray frame;
    uint8_t header = FRAME_HEAD;
    uint8_t tail   = FRAME_TAIL;

    // 直接把 float 4 字节写入 QByteArray
    QByteArray dataBytes;
    dataBytes.append(reinterpret_cast<const char*>(&value), sizeof(float));

    // 校验 = 帧头 + CMD + 数据0~3
    uint8_t checksum = header + static_cast<uint8_t>(cmd) +
                       static_cast<uint8_t>(dataBytes[0]) +
                       static_cast<uint8_t>(dataBytes[1]) +
                       static_cast<uint8_t>(dataBytes[2]) +
                       static_cast<uint8_t>(dataBytes[3]);

    // 组完整帧
    frame.append(static_cast<char>(header));
    frame.append(static_cast<char>(cmd));
    frame.append(dataBytes);
    frame.append(static_cast<char>(checksum));
    frame.append(static_cast<char>(tail));

    // for(int i=0; i<frame.size(); i++)
    //     qDebug("%02X ", static_cast<uint8_t>(frame[i]));

    serialPort->write(frame);
}

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

float bytesToFloat(const QByteArray &data, int index = 0)
{
    if (data.size() < index + 4)
        return 0.0f;

    float value;
    memcpy(&value, data.constData() + index, sizeof(float));
    return value;
}

void SerialManager::readSerialData()
{
    QByteArray data = serialPort->readAll();
    rxBuffer.append(data);

    while (rxBuffer.size() >= 5)
    {
        int headIndex = rxBuffer.indexOf(char(0xA5));
        if (headIndex < 0) {
            rxBuffer.clear();
            return;
        }

        if (rxBuffer.size() - headIndex < 5)
            return;

        uint8_t len = uint8_t(rxBuffer[headIndex + 2]);
        int frameSize = 5 + len;

        if (rxBuffer.size() - headIndex < frameSize)
            return;

        QByteArray frame = rxBuffer.mid(headIndex, frameSize);
        rxBuffer.remove(0, headIndex + frameSize);

        uint8_t cmd = uint8_t(frame[1]);
        QByteArray dataBytes = frame.mid(3, len);

        int floatCount = len / 4;  // 一个 float 4 字节
        QVector<float> values;
        for (int i = 0; i < floatCount; i++) {
            float v = bytesToFloat(dataBytes, i * 4);
            values.append(v);
        }

        switch (CMD_TypeDef(cmd)) {

        case CMD_TypeDef::CMD_CONNECT_MOTOR:
            // 如果 CMD_CONNECT_MOTOR 可能返回多个 float
            // 保存第一个作为 getPairs 示例，也可以根据需求保存全部
            if (!values.isEmpty()) {
                getPairs = int(values[0]);
                dir      = int(values[1]);
                g_zeroOffset = values[2];
                qDebug() << "CMD_CONNECT_MOTOR getPairs =" << getPairs;
                qDebug() << "CMD_CONNECT_MOTOR dir =" << dir;
                qDebug() << "CMD_CONNECT_MOTOR g_zeroOffset =" << g_zeroOffset;
                emit commandParsed(CMD_TypeDef::CMD_CONNECT_MOTOR);
            }
            break;

        case CMD_TypeDef::CMD_MECHANICALANGLE:
            if (values.size() >= 1) {
                mechanicalAngle = values[0];
                qDebug() << "Mechanical Angle:" << mechanicalAngle;
            } else {
                qDebug() << "CMD_MECHANICALANGLE 数据为空";
            }
            break;

        case CMD_TypeDef::CMD_ZEROCALIBRATIO:

            break;

        case CMD_TypeDef::CMD_ZEROCALIBRATIO_OVER:
            if (!values.isEmpty()) {
                g_zeroOffset = values[0];
                g_correctedElecAngle      = values[1];
                qDebug() << "g_zeroOffset = " << g_zeroOffset;
                qDebug() << "g_correctedElecAngle =" << g_correctedElecAngle;
            }
            emit zeroCalibrationFinished();
            break;

        case CMD_TypeDef::CMD_UABC:
            if (!values.isEmpty()) {
                Ua = values[0];
                Ub = values[1];
                Uc = values[2];
                emit newUABC(Ua, Ub, Uc); //发射绘图
                //qDebug() << "Ua =" << Ua << ", Ub =" << Ub << ", Uc =" << Uc;

            }
            break;


        default:
            qDebug() << "Unknown CMD:" << cmd << "Values:" << values;
            break;
        }
    }
}

