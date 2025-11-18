#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "serialmanager.h"   // 引入新的串口管理类

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

private:
    Ui::Widget *ui;
    SerialManager *serialManager;  // 串口管理对象
    QTimer *refreshTimer;          // 定时刷新串口列表
    bool anglePrintingEnabled = false;  // 控制是否打印
};
#endif // WIDGET_H
