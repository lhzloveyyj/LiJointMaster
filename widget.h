#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QSerialPort *serialPort;  // 串口对象
    bool serialOpen;      // 串口状态，true=打开，false=关闭

     QTimer *refreshTimer;  // 定时刷新串口列表

private slots:

    void on_openserial_bt_clicked();
    void refreshSerialPortList();
    void on_connectMotor_bt_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
