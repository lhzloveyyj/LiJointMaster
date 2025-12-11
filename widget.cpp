#include "widget.h"
#include "./ui_widget.h"
#include "serialmanager.h"
#include <QMessageBox>
#include "dialog.h"      // 弹窗对话框类
#include "LogHelper.h"   // 日志管理

/**
 * @brief Widget 构造函数
 * @param parent 父窗口指针
 *
 * 初始化 UI，设置暗色主题，初始化串口管理器、
 * PlotManager、MOS温度刷新定时器、日志显示等。
 */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /* ============================= 全局暗色 UI ============================= */
    // 设置深色主题样式
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

    // 将样式应用到整个应用
    qApp->setStyleSheet(darkStyle);


    /* ============================= 绘图区域背景 ============================= */
    // 设置 PlotWidget 背景颜色为深灰
    ui->plotWidget->setBackground(QBrush(QColor(30, 30, 30)));


    /* ============================= 初始化串口管理器 ============================= */
    serialManager = new SerialManager(this);

    // 填充当前可用串口列表
    ui->ComPort_ComboBox->addItems(serialManager->availablePorts());

    // 串口成功打开 → 更新 UI 图标和按钮文字
    connect(serialManager, &SerialManager::portOpened, this, [=]() {
        ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_up.png);"); // 图标显示“已连接”
        ui->openserial_bt->setText("关闭串口"); // 按钮文字更新
    });

    // 串口关闭 → 还原图标
    connect(serialManager, &SerialManager::portClosed, this, [=]() {
        ui->serialStatus->setStyleSheet("border-image: url(:/picture/serial_down.png);"); // 图标显示“未连接”
        ui->connet_motor_pic->setStyleSheet("border-image: url(:/picture/serial_down.png);"); // 电机连接状态图标复位
        ui->openserial_bt->setText("打开串口"); // 按钮文字更新
    });

    // 自动刷新串口列表（2 秒一次）
    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &Widget::refreshSerialPortList);
    refreshTimer->start(2000);

    // 串口解析指令 → Widget 处理
    connect(serialManager, &SerialManager::commandParsed, this, &Widget::handleParsedCommand);

    // 零点校准结束信号
    connect(serialManager, &SerialManager::zeroCalibrationFinished, this, &Widget::onZeroCalibrationFinished);


    /* ============================= 初始化 PlotManager ============================= */
    // 创建绘图管理器，负责管理曲线及动态数据追加
    plotManager = new PlotManager(ui->plotWidget, this);

    // 添加机械角度曲线
    plotManager->addGraph("mechanicalAngle", Qt::red);

    // 添加三相电压曲线
    plotManager->addGraph("Ua", Qt::red);
    plotManager->addGraph("Ub", Qt::green);
    plotManager->addGraph("Uc", Qt::blue);

    // 添加三路 ADC 曲线
    plotManager->addGraph("ADC1", Qt::yellow);
    plotManager->addGraph("ADC2", Qt::cyan);
    plotManager->addGraph("ADC3", Qt::magenta);

    // 添加三相 SVPWM 占空比曲线
    plotManager->addGraph("Ta", Qt::yellow);
    plotManager->addGraph("Tb", Qt::cyan);
    plotManager->addGraph("Tc", Qt::magenta);

    // 添加三相电流曲线
    plotManager->addGraph("Ia", Qt::yellow);
    plotManager->addGraph("Ib", Qt::cyan);
    plotManager->addGraph("Ic", Qt::magenta);

    // αβ 坐标系电压曲线
    plotManager->addGraph("Ualpha", Qt::yellow);
    plotManager->addGraph("Ubeta", Qt::cyan);

    // αβ 坐标系电流曲线
    plotManager->addGraph("Ialpha", Qt::yellow);
    plotManager->addGraph("Ibeta", Qt::cyan);

    // dq 坐标系电流曲线
    plotManager->addGraph("Iq", Qt::yellow);
    plotManager->addGraph("Id", Qt::cyan);

    // 添加速度打印
    plotManager->addGraph("speed", Qt::yellow);

    // 添加速度环输出打印
    plotManager->addGraph("speedOut", Qt::magenta);

    // 串口实时信号 → 动态追加数据到曲线
    connect(serialManager, &SerialManager::newmechanicalAngle, [=](float mechanicalAngle){
        plotManager->appendData("mechanicalAngle", mechanicalAngle);
    });

    connect(serialManager, &SerialManager::newUABC, [=](float Ua, float Ub, float Uc){
        plotManager->appendData("Ua", Ua);  // 添加 Ua 数据
        plotManager->appendData("Ub", Ub);  // 添加 Ub 数据
        plotManager->appendData("Uc", Uc);  // 添加 Uc 数据
    });

    connect(serialManager, &SerialManager::newADC, [=](int ADC1, int ADC2, int ADC3){
        plotManager->appendData("ADC1", ADC1);
        plotManager->appendData("ADC2", ADC2);
        plotManager->appendData("ADC3", ADC3);
    });

    connect(serialManager, &SerialManager::newTABC, [=](float Ta, float Tb, float Tc){
        plotManager->appendData("Ta", Ta);
        plotManager->appendData("Tb", Tb);
        plotManager->appendData("Tc", Tc);
    });

    connect(serialManager, &SerialManager::newIABC, [=](float Ia, float Ib, float Ic){
        plotManager->appendData("Ia", Ia);
        plotManager->appendData("Ib", Ib);
        plotManager->appendData("Ic", Ic);
    });

    connect(serialManager, &SerialManager::newUalpha_Ubeta, [=](float Ualpha, float Ubeta){
        plotManager->appendData("Ualpha", Ualpha);
        plotManager->appendData("Ubeta", Ubeta);
    });

    connect(serialManager, &SerialManager::newIalpha_Ibeta, [=](float Ialpha, float Ibeta){
        plotManager->appendData("Ialpha", Ialpha);
        plotManager->appendData("Ibeta", Ibeta);
    });

    connect(serialManager, &SerialManager::newIqId, [=](float Iq, float Id){
        plotManager->appendData("Iq", Iq);
        plotManager->appendData("Id", Id);
    });

    connect(serialManager, &SerialManager::newSpeed, [=](float speed){
        plotManager->appendData("speed", speed);
    });

    connect(serialManager, &SerialManager::newSpeedOut, [=](float speedOut){
        plotManager->appendData("speedOut", speedOut);
    });


    /* ============================= X 轴范围滑条 ============================= */
    connect(ui->x_Axis_sd, &QSlider::valueChanged, this, [this](int value){
        if (!plotManager) return;

        double minRange = 0.1;     // 最小显示范围
        double maxRange = 10.0;    // 最大显示范围
        double rangeSec = minRange + (maxRange - minRange) * value / 100.0;

        plotManager->setXAxisRange(rangeSec); // 设置显示时间范围
    });


    /* ============================= MOS 温度刷新定时器 ============================= */
    mosTimer = new QTimer(this);
    connect(mosTimer, &QTimer::timeout, this, &Widget::updateMosTempUI);
    mosTimer->start(100); // 100ms刷新一次 MOS 温度


    /* ============================= 日志输出 ============================= */
    connect(LogHelper::instance(), &LogHelper::newLog, this, [this](const QString &msg){
        // 根据日志等级设置颜色
        QString levelColor = "white";

        if (msg.startsWith("Debug:"))
            levelColor = "#00ff00";  // 绿色
        else if (msg.startsWith("Warning:"))
            levelColor = "#ffaa00";  // 黄色
        else if (msg.startsWith("Critical:"))
            levelColor = "red";      // 红色
        else if (msg.startsWith("Fatal:"))
            levelColor = "#ff4040";  // 更亮的红色

        // 添加时间戳
        QString time = QDateTime::currentDateTime().toString("HH:mm:ss.zzz");

        // 拼接 HTML 格式字符串显示在 UI
        QString line = QString("<span style='color:gray;'>[%1]</span> "
                               "<span style='color:%2;'>%3</span>")
                           .arg(time)
                           .arg(levelColor)
                           .arg(msg);

        ui->log_txt->append(line); // 添加到日志文本框
    });
}

/**
 * @brief Widget 析构函数
 */
Widget::~Widget()
{
    delete ui;
}


/**
 * @brief 打开或关闭串口按钮点击槽
 *
 * 如果串口已打开则关闭串口，否则根据 UI 选中参数打开串口。
 */
void Widget::on_openserial_bt_clicked()
{
    // 如果串口已经打开，直接关闭
    if (serialManager->isOpen()) {
        serialManager->closePort();
        return;
    }

    // 获取 UI 选中的串口名称和波特率
    QString portName = ui->ComPort_ComboBox->currentText();
    qint32 baud = ui->BuadRate_ComboBox->currentText().toInt();
    auto dataBits = QSerialPort::Data8;     // 数据位 8
    auto stopBits = QSerialPort::OneStop;   // 停止位 1
    auto parity = QSerialPort::NoParity;    // 无奇偶校验

    // 尝试打开串口，如果失败弹出错误提示
    if (!serialManager->openPort(portName, baud, dataBits, stopBits, parity)) {
        QMessageBox::critical(this, "Error", QString("Failed to open port %1!").arg(portName));
    }
}

/**
 * @brief 刷新串口列表
 *
 * 保留当前选中的串口，如果还存在则保持选中状态。
 */
void Widget::refreshSerialPortList()
{
    // 保存当前选中串口
    QString current = ui->ComPort_ComboBox->currentText();
    // 获取可用串口列表
    QStringList list = serialManager->availablePorts();

    // 清空原有列表并重新添加
    ui->ComPort_ComboBox->clear();
    ui->ComPort_ComboBox->addItems(list);

    // 恢复原来选中的串口，如果存在
    int index = ui->ComPort_ComboBox->findText(current);
    if (index != -1)
        ui->ComPort_ComboBox->setCurrentIndex(index);
}

/**
 * @brief 连接电机按钮点击槽
 *
 * 向电机发送连接命令，并延迟更新 UI 上的参数显示。
 */
void Widget::on_connectMotor_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    // 发送连接电机命令，0.12 为示例参数
    serialManager->sendFloatCommand(CMD_TypeDef::CMD_CONNECT_MOTOR, 0.12);

    // 延迟 100ms 更新 UI，保证串口返回数据已准备好
    QTimer::singleShot(100, this, [=]() {
        ui->setPairs_te->setPlainText(QString::number(serialManager->getPairs));
        ui->setDir_te->setPlainText(QString::number(serialManager->dir));
        ui->zeroOffset_te->setPlainText(QString::number(serialManager->g_zeroOffset));
        ui->iqPID_kp_te->setPlainText(QString::number(serialManager->iqPID_kp));
        ui->iqPID_ki_te->setPlainText(QString::number(serialManager->iqPID_ki));
        ui->dcBus_te->setPlainText(QString::number(serialManager->dcVbus));
        ui->setSpeedDir_te->setPlainText(QString::number(serialManager->speedDir));
        ui->speedPID_kp_te->setPlainText(QString::number(serialManager->speedPID_kp));
        ui->speedPID_ki_te->setPlainText(QString::number(serialManager->speedPID_ki));
    });
}

/**
 * @brief 串口解析命令处理槽
 * @param cmd 接收到的命令枚举
 *
 * 根据命令更新对应 UI 元素，例如连接电机状态图标。
 */
void Widget::handleParsedCommand(CMD_TypeDef cmd)
{
    switch (cmd) {
    case CMD_TypeDef::CMD_CONNECT_MOTOR:
        // 电机已连接 → 更新图标为“已连接”
        ui->connet_motor_pic->setStyleSheet("border-image: url(:/picture/serial_up.png);");
        break;
    default:
        break;
    }
}

/**
 * @brief 机械角度打印开关槽
 * @param checked 是否勾选
 *
 * 打开或关闭电机机械角度打印。
 */
void Widget::on_mechanicalAngle_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    // 保存开关状态
    anglePrintingEnabled = checked;
    if (anglePrintingEnabled) {
        qDebug() << "打印机械角度";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_MECHANICALANGLE, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_MECHANICALANGLE_CLOSE, 0.0);
        qDebug() << "停止打印机械角度";
    }
}

/**
 * @brief 设置极对数按钮槽
 *
 * 从 UI 获取输入值并发送给电机。
 */
void Widget::on_setPairs_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    // 获取输入文本并转为整数
    QString text = ui->setPairs_te->toPlainText().trimmed();
    bool ok = false;
    int value = text.toInt(&ok);
    float floatValue = static_cast<float>(value);

    qDebug() << "设置极对数";

    // 发送设置极对数命令
    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETPAIRS, floatValue);
}

/**
 * @brief 设置编码器方向按钮槽
 */
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

    qDebug() << "设置编码器方向";

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETDIR, floatValue);
}

/**
 * @brief 零点校准按钮槽
 */
void Widget::on_zeroOffset_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    qDebug() << "校准中......";
    serialManager->sendFloatCommand(CMD_TypeDef::CMD_ZEROCALIBRATIO, 0.0f);
}

/**
 * @brief 零点校准完成槽
 *
 * 更新 UI 上显示的零点偏移和修正电角度。
 */
void Widget::onZeroCalibrationFinished()
{
    qDebug() << "校准完成";
    ui->zeroOffset_te->setPlainText(QString::number(serialManager->g_zeroOffset));
    ui->correctedElecAngle_te->setPlainText(QString::number(serialManager->g_correctedElecAngle));
}

/**
 * @brief Uabc 电压打印开关槽
 * @param checked 是否勾选
 *
 * 打开或关闭三相电压 Uabc 的打印。
 */
void Widget::on_Uabc_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    uabcEnabled = checked;

    if (uabcEnabled) {
        qDebug() << "打印三相电压";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UABC, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UABC_CLOSE, 0.0);
        qDebug() << "停止打印三相电压";
    }
}

/**
 * @brief 设置 Uq 电压值按钮槽
 *
 * 从 UI 获取 Uq 值并发送给电机。
 */
void Widget::on_setUq_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setUq_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置Uq" << floatValue;
    } else {
        qDebug() << "设置Uq失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETUQ, floatValue);
}

/**
 * @brief ADC 打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_adc_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    adcEnabled = checked;

    if (adcEnabled) {
        qDebug() << "打印三相ADC";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_ADC, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_ADC_CLOSE, 0.0);
        qDebug() << "停止打印三相ADC";
    }
}

/**
 * @brief 获取母线电压按钮槽
 */
void Widget::on_dcBus_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    qDebug() << "获取母线电压";
    serialManager->sendFloatCommand(CMD_TypeDef::CMD_DCVBUS, 0.0);

    // 延迟 100ms 更新 UI 显示母线电压
    QTimer::singleShot(100, this, [=]() {
        ui->dcBus_te->setPlainText(QString::number(serialManager->dcVbus));
    });
}

/**
 * @brief SVPWM 打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_SVPWM_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    tabcEnabled = checked;

    if (tabcEnabled) {
        qDebug() << "打印三相SVPWM";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_TABC, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_TABC_CLOSE, 0.0);
        qDebug() << "停止打印三相SVPWM";
    }
}

/**
 * @brief Iabc 电流打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_Iabc_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    IabcEnabled = checked;

    if (IabcEnabled) {
        qDebug() << "打印三相电流";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IABC, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IABC_CLOSE, 0.0);
        qDebug() << "停止打印三相电流";
    }
}

/**
 * @brief Uαβ 打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_UAlpha_Beta_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    UAlpha_BetaEnabled = checked;

    if (UAlpha_BetaEnabled) {
        qDebug() << "打印UAlpha UBeta";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UALPHA_BETA, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_UALPHA_BETA_CLOSE, 0.0);
        qDebug() << "停止打印UAlpha UBeta";
    }
}

/**
 * @brief Iαβ 打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_IAlpha_Beta_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    IAlpha_BetaEnabled = checked;

    if (IAlpha_BetaEnabled) {
        qDebug() << "打印IAlpha IUBeta";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IALPHA_BETA, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IALPHA_BETA_CLOSE, 0.0);
        qDebug() << "停止打印IAlpha IUBeta";
    }
}

/**
 * @brief IQ/ID 打印开关槽
 * @param checked 是否勾选
 */
void Widget::on_iq_id_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    IQ_ID_Enabled = checked;

    if (IQ_ID_Enabled) {
        qDebug() << "打印Iq Id";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IQ_ID, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_IQ_ID_CLOSE, 0.0);
        qDebug() << "停止打印Iq Id";
    }
}

/**
 * @brief 设置 IQ 电流值按钮槽
 */
void Widget::on_setIQ_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setIQ_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);

    if (ok) {
        qDebug() << "设置 Iq " << floatValue;
    } else {
        qDebug() << "设置Iq失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETIQ, floatValue);
}

/**
 * @brief 设置 ID 电流值按钮槽
 */
void Widget::on_setID_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setID_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);

    if (ok) {
        qDebug() << "设置Id" << floatValue;
    } else {
        qDebug() << "设置Id失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETID, floatValue);
}

/**
 * @brief 控制模式选择下拉框槽
 * @param index 当前选择索引
 *
 * 根据选择索引发送对应 FOC 控制模式命令。
 */
void Widget::on_ctrolMode_ComboBox_currentIndexChanged(int index)
{
    CMD_TypeDef cmd;

    switch (index)
    {
    case 0: cmd = CMD_TypeDef::CMD_OPEN_LOOP;    break;
    case 1: cmd = CMD_TypeDef::CMD_CURRENT_LOOP; break;
    case 2: cmd = CMD_TypeDef::CMD_SPEED_LOOP;   break;
    case 3: cmd = CMD_TypeDef::CMD_POSITION_LOOP ;  break;
    default: return;
    }

    float value = static_cast<float>(index);   // 传递模式编号
    serialManager->sendFloatCommand(cmd, value);

    qDebug() << "FOC 模式切换：" << ui->ctrolMode_ComboBox->currentText();
}

/**
 * @brief 弹出设备信息窗口按钮槽
 */
void Widget::on_DevMsg_bt_clicked()
{
    Dialog dlg;   // 创建对话框
    dlg.exec();   // 弹出模态窗口
}

/**
 * @brief MOS 温度刷新槽
 *
 * 更新 UI 标签、进度条，并根据温度动态设置进度条颜色。
 */
void Widget::updateMosTempUI()
{
    float temp = serialManager->mosTemp;

    // 1️⃣ 更新温度标签
    ui->mosTemp_lab->setText(QString::number(temp, 'f', 1) + " ℃");

    // 2️⃣ 更新进度条数值
    ui->mosTemp_bar->setValue(static_cast<int>(temp));

    // 3️⃣ 根据温度动态设置进度条颜色
    QString color;
    if (temp <= 30)
        color = "green";
    else if (temp <= 50)
        color = "yellow";
    else
        color = "red";

    // 设置 QProgressBar 样式
    QString style = QString(
                        "QProgressBar {"
                        "    border: 2px solid #555;"
                        "    border-radius: 5px;"
                        "    text-align: center;"
                        "    background-color: #EEE;"
                        "}"
                        "QProgressBar::chunk {"
                        "    border-radius: 5px;"
                        "    background-color: %1;"
                        "}").arg(color);

    ui->mosTemp_bar->setStyleSheet(style);
}

/**
 * @brief 日志追加到 UI
 * @param msg 日志信息
 *
 * 在 QTextEdit 中追加日志并滚动到底部。
 */
void Widget::appendLogToUI(const QString &msg)
{
    ui->log_txt->append(msg);
    ui->log_txt->moveCursor(QTextCursor::End);
}

/**
 * @brief 新日志处理槽
 * @param msg 日志信息
 */
void Widget::onNewLog(const QString &msg)
{
    ui->log_txt->append(msg);
}


void Widget::on_setUd_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setUd_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置Ud" << floatValue;
    } else {
        qDebug() << "设置Ud失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETUD, floatValue);
}


void Widget::on_iqPID_kp_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->iqPID_kp_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置KP" << floatValue;
    } else {
        qDebug() << "设置KP失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETIQPIDKP, floatValue);
}


void Widget::on_speed_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    speed_Enabled = checked;

    if (speed_Enabled) {
        qDebug() << "打印速度";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_SPEED, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_SPEED_CLODE, 0.0);
        qDebug() << "停止打印速度";
    }
}


void Widget::on_setSpeedDir_bt_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setSpeedDir_te->toPlainText().trimmed();
    bool ok = false;
    int value = text.toInt(&ok);
    float floatValue = static_cast<float>(value);

    qDebug() << "设置速度方向";

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETSPEEDDIR, floatValue);
}


void Widget::on_speedOut_bt_clicked(bool checked)
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    speedOut_Enabled = checked;

    if (speedOut_Enabled) {
        qDebug() << "打印速度输出";
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_SPEEDOUT, 0.0);
    } else {
        serialManager->sendFloatCommand(CMD_TypeDef::CMD_SPEEDOUT_CLOSE, 0.0);
        qDebug() << "停止打印速度输出";
    }
}


void Widget::on_setSpeedTar_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->setSpeedTar_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置速度期望" << floatValue;
    } else {
        qDebug() << "设置速度期望失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETSPEEDTAR, floatValue);
}


void Widget::on_speedPID_kp_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->speedPID_kp_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置速度环KP" << floatValue;
    } else {
        qDebug() << "设置速度环KP失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETSPEEDPIDKP, floatValue);
}


void Widget::on_speedPID_ki_tb_clicked()
{
    if (!serialManager->isOpen()) {
        QMessageBox::warning(this, "Warning", "Serial port is not open!");
        return;
    }

    QString text = ui->speedPID_ki_te->toPlainText().trimmed();
    bool ok = false;
    float floatValue = text.toFloat(&ok);  // 转换为浮点数

    if (ok) {
        qDebug() << "设置速度环KI" << floatValue;
    } else {
        qDebug() << "设置速度环KI失败" << text;
    }

    serialManager->sendFloatCommand(CMD_TypeDef::CMD_SETSPEEDPIDKI, floatValue);
}

