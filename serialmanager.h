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
    int getPairs;
    int dir;
    float mechanicalAngle;
    float g_zeroOffset ;
    float g_correctedElecAngle;

    float Ua;
    float Ub;
    float Uc;

    int ADC1;
    int ADC2;
    int ADC3;

    float Ta;
    float Tb;
    float Tc;

    float Ia;
    float Ib;
    float Ic;

    float Ualpha;
    float Ubeta;

    float Ialpha;
    float Ibeta;

    float Iq;
    float Id;

    float dcVbus;

    float mosTemp;

signals:
    void portOpened();                      // 串口打开信号
    void portClosed();                      // 串口关闭信号
    void dataReceived(CMD_TypeDef cmd, QByteArray data); // 接收到数据的信号
    void commandParsed(CMD_TypeDef cmd);
    void zeroCalibrationFinished();         // 零点校准完成
    void newADC(int ADC1, int ADC2, int ADC3);   // 发射三相电压绘图
    void newUABC(float Ua, float Ub, float Uc);    // 发射三相电压绘图
    void newTABC(float Ta, float Tb, float Tc);   // 发射三相SVPWM绘图
    void newIABC(float Ia, float Ib, float Ic);   // 发射三相电流绘图
    void newUalpha_Ubeta(float Ualpha, float Ubeta);   // 发射三相电流绘图
    void newIalpha_Ibeta(float Ialpha, float Ibeta);   // 发射三相电流绘图
    void newIqId(float Iq, float Id);   // 发射三相电流绘图

private slots:
    void readSerialData();                  // 串口接收槽

private:
    QSerialPort *serialPort;
    QByteArray rxBuffer;                    // 接收缓冲区
};
