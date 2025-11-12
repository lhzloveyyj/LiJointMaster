#pragma once
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "serialcommand.h"

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);
    ~SerialManager();

    QStringList availablePorts();           // 获取串口列表
    bool openPort(const QString &portName,  // 打开串口
                  qint32 baudRate,
                  QSerialPort::DataBits dataBits,
                  QSerialPort::StopBits stopBits,
                  QSerialPort::Parity parity);
    void closePort();                       // 关闭串口
    bool isOpen() const;                    // 判断是否打开
    void sendFloatCommand(CMD_TypeDef cmd, float value);

signals:
    void portOpened();                      // 串口打开信号
    void portClosed();                      // 串口关闭信号

private:
    QSerialPort *serialPort;
};
