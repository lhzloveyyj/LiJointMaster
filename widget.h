#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "serialmanager.h"   // 串口管理类
#include "plotmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

/**
 * @brief 主界面 Widget 类
 *
 * 提供串口控制、FOC 电机控制、数据打印和绘图功能。
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口指针
     */
    explicit Widget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数
     */
    ~Widget();

    /// 日志系统使用的单例指针
    static Widget *instance;

private slots:
    /** @name 串口操作 */
    ///@{
    void on_openserial_bt_clicked();  ///< 打开/关闭串口
    void on_connectMotor_bt_clicked();///< 连接电机
    void refreshSerialPortList();     ///< 刷新串口列表
    void handleParsedCommand(CMD_TypeDef cmd); ///< 处理接收到的串口命令
    ///@}

    /** @name 电机状态控制 */
    ///@{
    void on_mechanicalAngle_bt_clicked(bool checked); ///< 机械角打印开关
    void on_setPairs_bt_clicked();                    ///< 设置极对数
    void on_setDir_bt_clicked();                      ///< 设置编码器方向
    void on_zeroOffset_bt_clicked();                  ///< 零点位校准
    void onZeroCalibrationFinished();                ///< 零点校准完成槽
    void on_Uabc_bt_clicked(bool checked);           ///< Uabc 打印开关
    void on_setUq_bt_clicked();                      ///< 设置 Uq
    void on_adc_bt_clicked(bool checked);            ///< ADC 打印开关
    void on_dcBus_bt_clicked();                      ///< 获取母线电压
    void on_SVPWM_bt_clicked(bool checked);          ///< SVPWM 打印开关
    void on_Iabc_bt_clicked(bool checked);           ///< Iabc 打印开关
    void on_UAlpha_Beta_bt_clicked(bool checked);    ///< Uαβ 打印开关
    void on_IAlpha_Beta_bt_clicked(bool checked);    ///< Iαβ 打印开关
    void on_iq_id_bt_clicked(bool checked);          ///< Iq/Id 打印开关
    void on_setIQ_tb_clicked();                      ///< 设置 Iq
    void on_setID_tb_clicked();                      ///< 设置 Id
    void on_ctrolMode_ComboBox_currentIndexChanged(int index); ///< 控制模式切换
    void on_DevMsg_bt_clicked();                     ///< 打开设备信息对话框
    ///@}

    /** @name UI更新 */
    ///@{
    void updateMosTempUI();                          ///< MOS温度刷新
    void appendLogToUI(const QString &msg);          ///< 日志输出到界面
    void onNewLog(const QString &msg);               ///< 新日志槽
    ///@}

    void on_setUd_bt_clicked();

    void on_iqPID_kp_tb_clicked();

    void on_speed_bt_clicked(bool checked);

    void on_setSpeedDir_bt_clicked();

    void on_speedOut_bt_clicked(bool checked);

    void on_setSpeedTar_tb_clicked();

    void on_speedPID_kp_tb_clicked();

    void on_speedPID_ki_tb_clicked();

    void on_iqPID_ki_tb_clicked();

    void on_setLocalTar_tb_clicked();

    void on_local_bt_clicked(bool checked);

    void on_localOut_bt_clicked(bool checked);

private:
    Ui::Widget *ui;              ///< 界面对象

    /** @name 串口相关 */
    ///@{
    SerialManager *serialManager; ///< 串口管理对象
    QTimer *refreshTimer;          ///< 定时刷新串口列表
    QTimer *mosTimer;              ///< 定时刷新 MOS 温度
    ///@}

    /** @name 打印控制开关 */
    bool anglePrintingEnabled = false;     ///< 机械角打印开关
    bool uabcEnabled = false;              ///< Uabc 打印开关
    bool adcEnabled  = false;              ///< ADC 打印开关
    bool tabcEnabled = false;              ///< Tabc 打印开关
    bool IabcEnabled = false;              ///< Iabc 打印开关
    bool UAlpha_BetaEnabled = false;       ///< Uαβ 打印开关
    bool IAlpha_BetaEnabled = false;       ///< Iαβ 打印开关
    bool IQ_ID_Enabled = false;            ///< Iq/Id 打印开关
    bool mostemp_Enabled = false;          ///< MOS温度打印开关
    bool speed_Enabled = false;
    bool speedOut_Enabled = false;
    bool local_Enabled = false;
    bool localOut_Enabled = false;

    PlotManager *plotManager;               ///< 绘图管理对象
};

#endif // WIDGET_H
