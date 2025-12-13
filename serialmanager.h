#pragma once
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "serialcommand.h"

/**
 * @brief 串口管理类
 *
 * 封装串口操作、命令发送与接收、数据解析功能。
 */
class SerialManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent 父对象
     */
    explicit SerialManager(QObject *parent = nullptr);

    /**
     * @brief 析构函数
     *        关闭串口并释放资源
     */
    ~SerialManager();

    /**
     * @brief 获取系统中可用的串口列表
     * @return QStringList 串口名称列表
     */
    QStringList availablePorts();

    /**
     * @brief 打开串口
     * @param portName 串口名
     * @param baudRate 波特率
     * @param dataBits 数据位
     * @param stopBits 停止位
     * @param parity 校验位
     * @return true 打开成功, false 打开失败
     */
    bool openPort(const QString &portName,
                  qint32 baudRate,
                  QSerialPort::DataBits dataBits,
                  QSerialPort::StopBits stopBits,
                  QSerialPort::Parity parity);

    /**
     * @brief 关闭串口
     */
    void closePort();

    /**
     * @brief 判断串口是否打开
     * @return true 已打开, false 未打开
     */
    bool isOpen() const;

    /**
     * @brief 发送浮点数命令到电机控制器
     * @param cmd 命令类型
     * @param value 浮点数值
     */
    void sendFloatCommand(CMD_TypeDef cmd, float value);

    /** @name 数据缓存变量 */
    ///@{
    int getPairs;                 ///< 电机极对数
    int dir;                      ///< 编码器方向
    float mechanicalAngle;        ///< 机械角
    float g_zeroOffset;           ///< 零点偏移
    float g_correctedElecAngle;  ///< 电角度修正值

    float Ua, Ub, Uc;            ///< 三相电压
    int ADC1, ADC2, ADC3;        ///< 三相ADC
    float Ta, Tb, Tc;            ///< 三相SVPWM占空比
    float Ia, Ib, Ic;            ///< 三相电流
    float Ualpha, Ubeta;         ///< αβ坐标系电压
    float Ialpha, Ibeta;         ///< αβ坐标系电流
    float Iq, Id;                ///< dq轴电流
    float dcVbus;                ///< 母线电压
    float mosTemp;               ///< MOS温度
    float iqPID_kp;               // 电流环kp
    float iqPID_ki;               // 电流环ki
    float speed;                  // 速度
    float speedDir;               // 速度方向
    float speedOut;               // 速度环输出
    float speedPID_kp;            // 速度环kp
    float speedPID_ki;            // 速度环ki
    float local;                  // 位置
    float localOut;               // 位置环输出
    float localPID_kp;            // 位置环KP
    float localPID_kd;            // 位置环KD
    float iqPID_outMax;           // 电流环输出限制
    float speedPID_outMax;        // 速度环输出限制
    float localPID_outMax;        // 位置环输出限制
    ///@}

signals:
    void portOpened();                      ///< 串口打开信号
    void portClosed();                      ///< 串口关闭信号
    void dataReceived(CMD_TypeDef cmd, QByteArray data); ///< 接收到原始数据
    void commandParsed(CMD_TypeDef cmd);    ///< 命令解析完成
    void zeroCalibrationFinished();         ///< 零点校准完成
    void newmechanicalAngle(float mechanicalAngle);
    void newADC(int ADC1, int ADC2, int ADC3); ///< 发射三相ADC数据
    void newUABC(float Ua, float Ub, float Uc); ///< 发射三相电压数据
    void newTABC(float Ta, float Tb, float Tc); ///< 发射三相SVPWM数据
    void newIABC(float Ia, float Ib, float Ic); ///< 发射三相电流数据
    void newUalpha_Ubeta(float Ualpha, float Ubeta); ///< 发射 αβ电压
    void newIalpha_Ibeta(float Ialpha, float Ibeta); ///< 发射 αβ电流
    void newIqId(float Iq, float Id);             ///< 发射 dq电流
    void newSpeed(float speed);             ///< 发射 速度
    void newSpeedOut(float speedOut);       // 发射速度环输出
    void newLocal(float local);          // 发射位置
    void newLocalOut(float localOut);       // 发射位置环输出

private slots:
    /**
     * @brief 串口接收槽
     *        负责读取串口数据、解析帧并发射信号
     */
    void readSerialData();

private:
    QSerialPort *serialPort;      ///< 串口对象
    QByteArray rxBuffer;          ///< 接收缓冲区
};
