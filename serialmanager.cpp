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

    // 打印刚收到的原始数据
    //qDebug() << "Received bytes:";
    //for (int i = 0; i < data.size(); i++)
    //    qDebug("%02X ", static_cast<uint8_t>(data[i]));

    while (rxBuffer.size() >= 5) // 至少帧头 + CMD + LEN + 校验 + 帧尾
    {
        int headIndex = rxBuffer.indexOf(static_cast<char>(0xA5));
        if (headIndex < 0) {
            rxBuffer.clear();
            return;
        }

        if (rxBuffer.size() - headIndex < 5)
            return;

        uint8_t len = static_cast<uint8_t>(rxBuffer[headIndex + 2]);
        int frameSize = 5 + len;

        if (rxBuffer.size() - headIndex < frameSize)
            return;

        QByteArray frame = rxBuffer.mid(headIndex, frameSize);
        rxBuffer.remove(0, headIndex + frameSize);

        // 打印整帧数据
        // qDebug() << "Received frame:";
        // for (int i = 0; i < frame.size(); i++)
        //     qDebug("%02X ", static_cast<uint8_t>(frame[i]));

        uint8_t cmd = static_cast<uint8_t>(frame[1]);
        QByteArray dataBytes = frame.mid(3, len);

        // 打印 CMD 和数据
        // qDebug() << "CMD:" << cmd;
        // qDebug() << "Data bytes:";
        // for (int i = 0; i < dataBytes.size(); i++)
        //     qDebug("%02X ", static_cast<uint8_t>(dataBytes[i]));

        // ---------- case 解析 ----------
        switch (static_cast<CMD_TypeDef>(cmd)) {
        case CMD_TypeDef::CMD_CONNECT_MOTOR:
        {
            // CMD_CONNECT_MOTOR 可能返回多个 float
            int floatCount = len / 4;
            for (int i = 0; i < floatCount; i++) {
                float value = bytesToFloat(dataBytes, i * 4);
            //    qDebug() << "CMD_CONNECT_MOTOR float[" << i << "]:" << value;
            }
            emit commandParsed(CMD_TypeDef::CMD_CONNECT_MOTOR); // 发射信号
            break;
        }

        case CMD_TypeDef::CMD_NONE:
            qDebug() << "CMD_NONE received";
            break;

            // 以后拓展命令
            // case CMD_TypeDef::DISCONNECT_MOTOR:
            // {
            //     int floatCount = len / 4;
            //     for (int i = 0; i < floatCount; i++) {
            //         float value = bytesToFloat(dataBytes, i * 4);
            //         qDebug() << "DISCONNECT_MOTOR float[" << i << "]:" << value;
            //     }
            //     break;
            // }

        default:
            qDebug() << "Unknown CMD:" << cmd << "Data:" << dataBytes.toHex();
            break;
        }
    }
}

