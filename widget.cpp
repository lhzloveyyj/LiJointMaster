#include "widget.h"
#include "./ui_widget.h"
#include "serialmanager.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    serialManager = new SerialManager(this);

    // 初始化串口列表
    ui->ComPort_ComboBox->addItems(serialManager->availablePorts());

    // 串口打开/关闭信号绑定到 UI 更新
    connect(serialManager, &SerialManager::portOpened, this, [=]() {
        ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_up.png);");
        ui->openserial_bt->setText("关闭串口");
    });

    connect(serialManager, &SerialManager::portClosed, this, [=]() {
        ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_down.png);");
        ui->connet_motor_pic->setStyleSheet("border-image: url(:/picture/serial_down.png);");
        ui->openserial_bt->setText("打开串口");
    });

    // 定时刷新串口列表
    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &Widget::refreshSerialPortList);
    refreshTimer->start(2000);

    // 连接信号和槽
    connect(serialManager, &SerialManager::commandParsed,
            this, &Widget::handleParsedCommand);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openserial_bt_clicked()
{
    if (serialManager->isOpen()) {
        serialManager->closePort();
        return;
    }

    QString portName = ui->ComPort_ComboBox->currentText();
    qint32 baud = ui->BuadRate_ComboBox->currentText().toInt();
    auto dataBits = QSerialPort::Data8;
    auto stopBits = QSerialPort::OneStop;
    auto parity = QSerialPort::NoParity;

    if (!serialManager->openPort(portName, baud, dataBits, stopBits, parity)) {
        QMessageBox::critical(this, "Error", QString("Failed to open port %1!").arg(portName));
    }
}

void Widget::refreshSerialPortList()
{
    QString current = ui->ComPort_ComboBox->currentText();
    QStringList list = serialManager->availablePorts();

    ui->ComPort_ComboBox->clear();
    ui->ComPort_ComboBox->addItems(list);

    int index = ui->ComPort_ComboBox->findText(current);
    if (index != -1)
        ui->ComPort_ComboBox->setCurrentIndex(index);
}

void Widget::on_connectMotor_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_CONNECT_MOTOR, 0.12);
}

void Widget::handleParsedCommand(CMD_TypeDef cmd)
{
    qDebug() << "handleParsedCommand received cmd:" << static_cast<int>(cmd);

    switch (cmd) {
    case CMD_TypeDef::CMD_CONNECT_MOTOR:
    {
        ui->connet_motor_pic->setStyleSheet("border-image: url(:/picture/serial_up.png);");
        break;
    }
    default:
        break;
    }
}

