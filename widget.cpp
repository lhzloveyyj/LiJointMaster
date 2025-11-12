#include "widget.h"
#include "./ui_widget.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList serialNamePort;

    serialPort = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        serialNamePort<<info.portName();
    }
    ui->ComPort_ComboBox->addItems(serialNamePort);

    // ---------- 初始化串口列表 ----------
    refreshSerialPortList();
    // ---------- 定时器，每 2 秒刷新一次 ----------
    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &Widget::refreshSerialPortList);
    refreshTimer->start(2000);  // 2000ms = 2秒
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_openserial_bt_clicked()
{
    if (serialPort->isOpen()) {
        // 串口已打开，关闭串口
        serialPort->close();

        // 切换按钮文字和状态图
        ui->openserial_bt->setText("打开串口");
        ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_down.png);");

        //QMessageBox::information(this, "Info", "Serial port closed.");
        return;
    }

    // ---------- 0. 设置串口名 ----------
    QString portName = ui->ComPort_ComboBox->currentText();
    serialPort->setPortName(portName);

    // ---------- 2. 波特率映射 ----------
    QString baudText = ui->BuadRate_ComboBox->currentText();
    QSerialPort::BaudRate baudRate = static_cast<QSerialPort::BaudRate>(baudText.toInt());
    serialPort->setBaudRate(baudRate);

    // ---------- 3. 数据位映射 ----------
    QString dataBitsText = ui->DataBits_comboBox->currentText();
    QSerialPort::DataBits dataBits = QSerialPort::Data8;
    if (dataBitsText == "5") dataBits = QSerialPort::Data5;
    else if (dataBitsText == "6") dataBits = QSerialPort::Data6;
    else if (dataBitsText == "7") dataBits = QSerialPort::Data7;
    else if (dataBitsText == "8") dataBits = QSerialPort::Data8;
    serialPort->setDataBits(dataBits);

    // ---------- 4. 停止位映射 ----------
    QString stopBitsText = ui->StopBits_ComboBox->currentText();
    QSerialPort::StopBits stopBits = QSerialPort::OneStop;
    if (stopBitsText == "1") stopBits = QSerialPort::OneStop;
    else if (stopBitsText == "1.5") stopBits = QSerialPort::OneAndHalfStop;
    else if (stopBitsText == "2") stopBits = QSerialPort::TwoStop;
    serialPort->setStopBits(stopBits);

    // ---------- 5. 校验位映射 ----------
    QString parityText = ui->Parity_ComboBox->currentText();
    QSerialPort::Parity parity = QSerialPort::NoParity;
    if (parityText == "None") parity = QSerialPort::NoParity;
    else if (parityText == "Odd") parity = QSerialPort::OddParity;
    else if (parityText == "Even") parity = QSerialPort::EvenParity;
    else if (parityText == "Mark") parity = QSerialPort::MarkParity;
    else if (parityText == "Space") parity = QSerialPort::SpaceParity;
    serialPort->setParity(parity);

    // ---------- 打开串口 ----------
    if (!serialPort->open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this, "Error", QString("Failed to open serial port %1!").arg(portName));
        return;
    }

    // 串口打开成功，切换按钮文字和状态图
    ui->openserial_bt->setText("关闭串口");
    ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_up.png);");
    //QMessageBox::information(this, "Info", QString("Serial port %1 opened successfully!").arg(portName));
}


void Widget::refreshSerialPortList()
{
    // 保存当前选中的串口
    QString currentPort = ui->ComPort_ComboBox->currentText();

    // 获取当前可用串口
    QStringList serialNamePort;
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        serialNamePort << info.portName();
    }

    // 更新 ComboBox
    ui->ComPort_ComboBox->clear();
    ui->ComPort_ComboBox->addItems(serialNamePort);

    // 尝试恢复之前选中的串口
    int index = ui->ComPort_ComboBox->findText(currentPort);
    if (index != -1) {
        ui->ComPort_ComboBox->setCurrentIndex(index);
    }
}

void Widget::on_connectMotor_bt_clicked()
{
    // 先检查串口是否打开
    if (!serialPort->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    // 发送固定命令 0x01
    QByteArray cmd;
    cmd.append(0x01);  // 打开电机
    serialPort->write(cmd);

}

