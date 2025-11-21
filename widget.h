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

private:
    Ui::Widget *ui;


    //串口
    SerialManager *serialManager;  // 串口管理对象
    QTimer *refreshTimer;          // 定时刷新串口列表
    bool anglePrintingEnabled = false;  // 控制角度
    bool uabcEnabled = false;           //控制Uabc打印

    PlotManager *plotManager;
};
#endif // WIDGET_H
