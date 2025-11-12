#include "serialmanager.h"

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

    for(int i=0; i<frame.size(); i++)
        qDebug("%02X ", static_cast<uint8_t>(frame[i]));

    serialPort->write(frame);
}

