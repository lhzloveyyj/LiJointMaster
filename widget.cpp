#include "widget.h"
#include "./ui_widget.h"
#include "serialmanager.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // --- 全局暗色 UI ---
    QString darkStyle =
        "QWidget { background-color: #2b2b2b; color: #dddddd; }"
        "QPushButton {"
        "   background-color: #3c3c3c;"
        "   border: 1px solid #4c4c4c;"
        "   padding: 5px;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #505050;"
        "}"
        "QLineEdit, QTextEdit, QPlainTextEdit {"
        "   background-color: #3a3a3a;"
        "   border: 1px solid #555555;"
        "   color: #eeeeee;"
        "}"
        "QLabel { color: #dddddd; }";
    qApp->setStyleSheet(darkStyle);

    //坐标轴
    // 设置整体背景为深灰色
    ui->plotWidget->setBackground(QBrush(QColor(30, 30, 30)));

    /* =================================== 坐标轴曲线 ==================================== */
    ui->plotWidget->xAxis->setBasePen(QPen(Qt::white));    // 坐标轴线颜色
    ui->plotWidget->yAxis->setBasePen(QPen(Qt::white));
    ui->plotWidget->xAxis->setTickPen(QPen(Qt::white));    // 刻度线颜色
    ui->plotWidget->yAxis->setTickPen(QPen(Qt::white));
    ui->plotWidget->xAxis->setSubTickPen(QPen(Qt::white)); // 子刻度线颜色
    ui->plotWidget->yAxis->setSubTickPen(QPen(Qt::white));

    // 坐标轴文字颜色
    ui->plotWidget->xAxis->setTickLabelColor(Qt::white);
    ui->plotWidget->yAxis->setTickLabelColor(Qt::white);

    // 坐标轴标题颜色（如果有）
    ui->plotWidget->xAxis->setLabelColor(Qt::white);
    ui->plotWidget->yAxis->setLabelColor(Qt::white);

    // 网格线颜色
    ui->plotWidget->xAxis->grid()->setPen(QPen(QColor(80, 80, 80)));
    ui->plotWidget->yAxis->grid()->setPen(QPen(QColor(80, 80, 80)));

    // 可选：启用鼠标拖动和滚轮缩放
    ui->plotWidget->setInteraction(QCP::iRangeDrag);
    ui->plotWidget->setInteraction(QCP::iRangeZoom);



    /* =================================== 初始化串口 ==================================== */
    serialManager = new SerialManager(this);

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

    //零点校准完成槽
    connect(serialManager, &SerialManager::zeroCalibrationFinished,
            this, &Widget::onZeroCalibrationFinished);
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

    // 延迟 100ms 更新 UI
    QTimer::singleShot(100, this, [=]() {
        ui->setPairs_te->setPlainText(QString::number(serialManager->getPairs));
        ui->setDir_te->setPlainText(QString::number(serialManager->dir));
        ui->zeroOffset_te->setPlainText(QString::number(serialManager->g_zeroOffset));
    });

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


void Widget::on_mechanicalAngle_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    anglePrintingEnabled = checked;
    if (anglePrintingEnabled) {
        qDebug() << "Angle printing enabled";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_MECHANICALANGLE, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_MECHANICALANGLE_CLOSE, 0.0);
        qDebug() << "Angle printing disabled";
    }
}


void Widget::on_setPairs_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setPairs_te->toPlainText().trimmed();
    bool ok = false;
    int value = text.toInt(&ok);
    float floatValue = static_cast<float>(value);
    qDebug() << "Sent value:" << floatValue;

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETPAIRS, floatValue);

}


void Widget::on_setDir_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setDir_te->toPlainText().trimmed();
    bool ok = false;
    int value = text.toInt(&ok);
    float floatValue = static_cast<float>(value);
    qDebug() << "Sent value:" << floatValue;

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETDIR, floatValue);
}


void Widget::on_zeroOffset_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_ZEROCALIBRATIO, 0.0f);
}

// 零点校准完成槽 onZeroCalibrationFinished
void Widget::onZeroCalibrationFinished()
{
    ui->zeroOffset_te->setPlainText(QString::number(serialManager->g_zeroOffset));
    ui->correctedElecAngle_te->setPlainText(QString::number(serialManager->g_correctedElecAngle));
}


void Widget::on_Uabc_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    uabcEnabled = checked;
    if (uabcEnabled) {
        qDebug() << "Uabc printing enabled";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UABC, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UABC_CLOSE, 0.0);
        qDebug() << "Uabc printing disabled";
    }

}

