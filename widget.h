#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "serialmanager.h"   // 引入新的串口管理类
#include "plotmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_openserial_bt_clicked();
    void on_connectMotor_bt_clicked();
    void refreshSerialPortList();
    void handleParsedCommand(CMD_TypeDef cmd);

    void on_mechanicalAngle_bt_clicked(bool checked);

    void on_setPairs_bt_clicked();

    void on_setDir_bt_clicked();

    void on_zeroOffset_bt_clicked();

    void onZeroCalibrationFinished();

    void on_Uabc_bt_clicked(bool checked);


    void on_setUq_bt_clicked();

    void on_adc_bt_clicked(bool checked);

    void on_dcBus_bt_clicked();

    void on_SVPWM_bt_clicked(bool checked);

    void on_Iabc_bt_clicked(bool checked);

    void on_UAlpha_Beta_bt_clicked(bool checked);

    void on_IAlpha_Beta_bt_clicked(bool checked);

    void on_iq_id_bt_clicked(bool checked);

    void on_setIQ_tb_clicked();

    void on_setID_tb_clicked();

    void on_ctrolMode_ComboBox_currentIndexChanged(int index);

    void on_DevMsg_bt_clicked();

    void updateMosTempUI();

private:
    Ui::Widget *ui;


    //串口
    SerialManager *serialManager;  // 串口管理对象
    QTimer *refreshTimer;          // 定时刷新串口列表
    QTimer *mosTimer;          // 定时刷新MOS温度
    bool anglePrintingEnabled = false;  // 控制角度
    bool uabcEnabled = false;           //控制Uabc打印
    bool adcEnabled  = false;
    bool tabcEnabled = false;
    bool IabcEnabled = false;
    bool UAlpha_BetaEnabled = false;
    bool IAlpha_BetaEnabled = false;
    bool IQ_ID_Enabled = false;
    bool mostemp_Enabled = false;

    PlotManager *plotManager;
};
#endif // WIDGET_H
