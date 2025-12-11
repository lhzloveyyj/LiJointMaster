/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCustomPlot *plotWidget;
    QSlider *x_Axis_sd;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *speed_bt;
    QPushButton *Iabc_bt;
    QPushButton *UAlpha_Beta_bt;
    QPushButton *speedOut_bt;
    QPushButton *IAlpha_Beta_bt;
    QPushButton *pushButton_4;
    QPushButton *Uabc_bt;
    QPushButton *pushButton_8;
    QPushButton *mechanicalAngle_bt;
    QPushButton *SVPWM_bt;
    QPushButton *iq_id_bt;
    QPushButton *adc_bt;
    QPushButton *pushButton_12;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_3;
    QComboBox *ComPort_ComboBox;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_4;
    QComboBox *BuadRate_ComboBox;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_5;
    QComboBox *DataBits_comboBox;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_6;
    QComboBox *StopBits_ComboBox;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_7;
    QComboBox *Parity_ComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *openserial_bt;
    QLabel *serialStatus;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *connectMotor_bt;
    QLabel *connet_motor_pic;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *setPairs_te;
    QPushButton *setPairs_bt;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *setDir_te;
    QPushButton *setDir_bt;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QTextEdit *zeroOffset_te;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QTextEdit *correctedElecAngle_te;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *dcBus_bt;
    QTextEdit *dcBus_te;
    QProgressBar *mosTemp_bar;
    QLabel *mosTemp_lab;
    QLabel *label_14;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_25;
    QTextEdit *setSpeedDir_te;
    QPushButton *setSpeedDir_bt;
    QPushButton *zeroOffset_bt;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QTextEdit *setUq_te;
    QPushButton *setUq_bt;
    QHBoxLayout *horizontalLayout_19;
    QTextEdit *setUd_te;
    QPushButton *setUd_bt;
    QHBoxLayout *horizontalLayout_16;
    QTextEdit *setIQ_te;
    QPushButton *setIQ_tb;
    QHBoxLayout *horizontalLayout_17;
    QTextEdit *setID_te;
    QPushButton *setID_tb;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *setSpeedTar_te;
    QPushButton *setSpeedTar_tb;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QPushButton *DevMsg_bt;
    QPushButton *pushButton_13;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QComboBox *ctrolMode_ComboBox;
    QGroupBox *groupBox_8;
    QTextBrowser *log_txt;
    QWidget *layoutWidget11;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QTextEdit *iqPID_kp_te;
    QPushButton *iqPID_kp_tb;
    QTextEdit *iqPID_ki_te;
    QPushButton *iqPID_ki_tb;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_3;
    QTextEdit *speedPID_kp_te;
    QPushButton *speedPID_kp_tb;
    QTextEdit *speedPID_ki_te;
    QPushButton *speedPID_ki_tb;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit_8;
    QPushButton *pushButton_10;
    QTextEdit *textEdit_9;
    QPushButton *pushButton_11;
    QGroupBox *groupBox_10;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1300, 770);
        plotWidget = new QCustomPlot(Widget);
        plotWidget->setObjectName("plotWidget");
        plotWidget->setGeometry(QRect(170, 50, 1111, 461));
        x_Axis_sd = new QSlider(Widget);
        x_Axis_sd->setObjectName("x_Axis_sd");
        x_Axis_sd->setGeometry(QRect(190, 510, 1081, 20));
        x_Axis_sd->setMaximum(200);
        x_Axis_sd->setOrientation(Qt::Orientation::Horizontal);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(170, 570, 301, 191));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        speed_bt = new QPushButton(groupBox);
        speed_bt->setObjectName("speed_bt");
        speed_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        speed_bt->setCheckable(true);

        gridLayout->addWidget(speed_bt, 2, 2, 1, 1);

        Iabc_bt = new QPushButton(groupBox);
        Iabc_bt->setObjectName("Iabc_bt");
        Iabc_bt->setMaximumSize(QSize(80, 30));
        Iabc_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        Iabc_bt->setCheckable(true);

        gridLayout->addWidget(Iabc_bt, 1, 1, 1, 1);

        UAlpha_Beta_bt = new QPushButton(groupBox);
        UAlpha_Beta_bt->setObjectName("UAlpha_Beta_bt");
        UAlpha_Beta_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        UAlpha_Beta_bt->setCheckable(true);

        gridLayout->addWidget(UAlpha_Beta_bt, 2, 1, 1, 1);

        speedOut_bt = new QPushButton(groupBox);
        speedOut_bt->setObjectName("speedOut_bt");
        speedOut_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        speedOut_bt->setCheckable(true);

        gridLayout->addWidget(speedOut_bt, 3, 2, 1, 1);

        IAlpha_Beta_bt = new QPushButton(groupBox);
        IAlpha_Beta_bt->setObjectName("IAlpha_Beta_bt");
        IAlpha_Beta_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        IAlpha_Beta_bt->setCheckable(true);

        gridLayout->addWidget(IAlpha_Beta_bt, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        pushButton_4->setCheckable(true);

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        Uabc_bt = new QPushButton(groupBox);
        Uabc_bt->setObjectName("Uabc_bt");
        Uabc_bt->setMaximumSize(QSize(100, 30));
        Uabc_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        Uabc_bt->setCheckable(true);

        gridLayout->addWidget(Uabc_bt, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        pushButton_8->setCheckable(true);

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        mechanicalAngle_bt = new QPushButton(groupBox);
        mechanicalAngle_bt->setObjectName("mechanicalAngle_bt");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(9);
        mechanicalAngle_bt->setFont(font1);
        mechanicalAngle_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        mechanicalAngle_bt->setCheckable(true);

        gridLayout->addWidget(mechanicalAngle_bt, 0, 0, 1, 1);

        SVPWM_bt = new QPushButton(groupBox);
        SVPWM_bt->setObjectName("SVPWM_bt");
        SVPWM_bt->setMaximumSize(QSize(80, 30));
        SVPWM_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        SVPWM_bt->setCheckable(true);

        gridLayout->addWidget(SVPWM_bt, 2, 0, 1, 1);

        iq_id_bt = new QPushButton(groupBox);
        iq_id_bt->setObjectName("iq_id_bt");
        iq_id_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        iq_id_bt->setCheckable(true);

        gridLayout->addWidget(iq_id_bt, 1, 2, 1, 1);

        adc_bt = new QPushButton(groupBox);
        adc_bt->setObjectName("adc_bt");
        adc_bt->setMaximumSize(QSize(80, 30));
        adc_bt->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        adc_bt->setCheckable(true);

        gridLayout->addWidget(adc_bt, 0, 1, 1, 1);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        pushButton_12->setCheckable(true);

        gridLayout->addWidget(pushButton_12, 4, 0, 1, 1);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 50, 151, 251));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 124, 227));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial.png);"));

        horizontalLayout_7->addWidget(label_2);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(84, 30));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout_7->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_24->addWidget(label_3);

        ComPort_ComboBox = new QComboBox(layoutWidget);
        ComPort_ComboBox->setObjectName("ComPort_ComboBox");

        horizontalLayout_24->addWidget(ComPort_ComboBox);


        verticalLayout->addLayout(horizontalLayout_24);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_23->addWidget(label_4);

        BuadRate_ComboBox = new QComboBox(layoutWidget);
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->setObjectName("BuadRate_ComboBox");

        horizontalLayout_23->addWidget(BuadRate_ComboBox);


        verticalLayout->addLayout(horizontalLayout_23);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_22->addWidget(label_5);

        DataBits_comboBox = new QComboBox(layoutWidget);
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->setObjectName("DataBits_comboBox");

        horizontalLayout_22->addWidget(DataBits_comboBox);


        verticalLayout->addLayout(horizontalLayout_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_21->addWidget(label_6);

        StopBits_ComboBox = new QComboBox(layoutWidget);
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->setObjectName("StopBits_ComboBox");

        horizontalLayout_21->addWidget(StopBits_ComboBox);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_20->addWidget(label_7);

        Parity_ComboBox = new QComboBox(layoutWidget);
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->setObjectName("Parity_ComboBox");

        horizontalLayout_20->addWidget(Parity_ComboBox);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        openserial_bt = new QPushButton(layoutWidget);
        openserial_bt->setObjectName("openserial_bt");

        horizontalLayout->addWidget(openserial_bt);

        serialStatus = new QLabel(layoutWidget);
        serialStatus->setObjectName("serialStatus");
        serialStatus->setMinimumSize(QSize(30, 30));
        serialStatus->setMaximumSize(QSize(30, 30));
        serialStatus->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial_down.png);"));
        serialStatus->setScaledContents(true);
        serialStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(serialStatus);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 310, 151, 451));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(11, 11, 102, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(30, 30));
        label_9->setMaximumSize(QSize(30, 30));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/motor.png);"));

        horizontalLayout_8->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");
        label_10->setFont(font2);

        horizontalLayout_8->addWidget(label_10);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(11, 49, 108, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        connectMotor_bt = new QPushButton(layoutWidget2);
        connectMotor_bt->setObjectName("connectMotor_bt");

        horizontalLayout_6->addWidget(connectMotor_bt);

        connet_motor_pic = new QLabel(layoutWidget2);
        connet_motor_pic->setObjectName("connet_motor_pic");
        connet_motor_pic->setMinimumSize(QSize(20, 20));
        connet_motor_pic->setMaximumSize(QSize(20, 20));
        connet_motor_pic->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial_down.png);"));
        connet_motor_pic->setScaledContents(true);
        connet_motor_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(connet_motor_pic);

        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(11, 110, 128, 32));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        setPairs_te = new QTextEdit(layoutWidget3);
        setPairs_te->setObjectName("setPairs_te");
        setPairs_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_10->addWidget(setPairs_te);

        setPairs_bt = new QPushButton(layoutWidget3);
        setPairs_bt->setObjectName("setPairs_bt");
        setPairs_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_10->addWidget(setPairs_bt);

        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(11, 150, 128, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        setDir_te = new QTextEdit(layoutWidget4);
        setDir_te->setObjectName("setDir_te");
        setDir_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_11->addWidget(setDir_te);

        setDir_bt = new QPushButton(layoutWidget4);
        setDir_bt->setObjectName("setDir_bt");
        setDir_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(setDir_bt);

        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(11, 230, 136, 32));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);

        horizontalLayout_12->addWidget(label_8);

        zeroOffset_te = new QTextEdit(layoutWidget5);
        zeroOffset_te->setObjectName("zeroOffset_te");
        zeroOffset_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_12->addWidget(zeroOffset_te);

        layoutWidget6 = new QWidget(groupBox_3);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(11, 270, 136, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget6);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        horizontalLayout_13->addWidget(label_11);

        correctedElecAngle_te = new QTextEdit(layoutWidget6);
        correctedElecAngle_te->setObjectName("correctedElecAngle_te");
        correctedElecAngle_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_13->addWidget(correctedElecAngle_te);

        layoutWidget7 = new QWidget(groupBox_3);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(11, 310, 133, 32));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        dcBus_bt = new QPushButton(layoutWidget7);
        dcBus_bt->setObjectName("dcBus_bt");
        dcBus_bt->setMaximumSize(QSize(60, 30));

        horizontalLayout_15->addWidget(dcBus_bt);

        dcBus_te = new QTextEdit(layoutWidget7);
        dcBus_te->setObjectName("dcBus_te");
        dcBus_te->setMaximumSize(QSize(65, 30));

        horizontalLayout_15->addWidget(dcBus_te);

        mosTemp_bar = new QProgressBar(groupBox_3);
        mosTemp_bar->setObjectName("mosTemp_bar");
        mosTemp_bar->setGeometry(QRect(10, 390, 131, 10));
        mosTemp_bar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"    background-color: #EEE;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    border-radius: 5px;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 green,\n"
"        stop: 0.5 yellow,\n"
"        stop: 1 red\n"
"    );\n"
"}\n"
""));
        mosTemp_bar->setValue(0);
        mosTemp_bar->setTextVisible(false);
        mosTemp_lab = new QLabel(groupBox_3);
        mosTemp_lab->setObjectName("mosTemp_lab");
        mosTemp_lab->setGeometry(QRect(90, 350, 50, 30));
        mosTemp_lab->setMaximumSize(QSize(70, 30));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 350, 60, 30));
        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 190, 128, 32));
        horizontalLayout_25 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        setSpeedDir_te = new QTextEdit(layoutWidget_2);
        setSpeedDir_te->setObjectName("setSpeedDir_te");
        setSpeedDir_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_25->addWidget(setSpeedDir_te);

        setSpeedDir_bt = new QPushButton(layoutWidget_2);
        setSpeedDir_bt->setObjectName("setSpeedDir_bt");
        setSpeedDir_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_25->addWidget(setSpeedDir_bt);

        zeroOffset_bt = new QPushButton(groupBox_3);
        zeroOffset_bt->setObjectName("zeroOffset_bt");
        zeroOffset_bt->setGeometry(QRect(20, 80, 80, 23));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(480, 530, 192, 234));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        setUq_te = new QTextEdit(groupBox_4);
        setUq_te->setObjectName("setUq_te");
        setUq_te->setMaximumSize(QSize(80, 25));

        horizontalLayout_14->addWidget(setUq_te);

        setUq_bt = new QPushButton(groupBox_4);
        setUq_bt->setObjectName("setUq_bt");
        setUq_bt->setMaximumSize(QSize(80, 25));

        horizontalLayout_14->addWidget(setUq_bt);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        setUd_te = new QTextEdit(groupBox_4);
        setUd_te->setObjectName("setUd_te");
        setUd_te->setMaximumSize(QSize(80, 25));

        horizontalLayout_19->addWidget(setUd_te);

        setUd_bt = new QPushButton(groupBox_4);
        setUd_bt->setObjectName("setUd_bt");
        setUd_bt->setMaximumSize(QSize(80, 25));

        horizontalLayout_19->addWidget(setUd_bt);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        setIQ_te = new QTextEdit(groupBox_4);
        setIQ_te->setObjectName("setIQ_te");
        setIQ_te->setMaximumSize(QSize(80, 25));

        horizontalLayout_16->addWidget(setIQ_te);

        setIQ_tb = new QPushButton(groupBox_4);
        setIQ_tb->setObjectName("setIQ_tb");
        setIQ_tb->setMaximumSize(QSize(80, 25));

        horizontalLayout_16->addWidget(setIQ_tb);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        setID_te = new QTextEdit(groupBox_4);
        setID_te->setObjectName("setID_te");
        setID_te->setMaximumSize(QSize(80, 25));

        horizontalLayout_17->addWidget(setID_te);

        setID_tb = new QPushButton(groupBox_4);
        setID_tb->setObjectName("setID_tb");
        setID_tb->setMaximumSize(QSize(80, 25));

        horizontalLayout_17->addWidget(setID_tb);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        setSpeedTar_te = new QTextEdit(groupBox_4);
        setSpeedTar_te->setObjectName("setSpeedTar_te");
        setSpeedTar_te->setMaximumSize(QSize(80, 25));

        horizontalLayout_2->addWidget(setSpeedTar_te);

        setSpeedTar_tb = new QPushButton(groupBox_4);
        setSpeedTar_tb->setObjectName("setSpeedTar_tb");
        setSpeedTar_tb->setMaximumSize(QSize(80, 25));

        horizontalLayout_2->addWidget(setSpeedTar_tb);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        textEdit_2 = new QTextEdit(groupBox_4);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMaximumSize(QSize(80, 25));

        horizontalLayout_3->addWidget(textEdit_2);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(80, 25));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 0, 1271, 41));
        layoutWidget8 = new QWidget(groupBox_6);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(11, 10, 304, 25));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget8);
        label_12->setObjectName("label_12");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font3.setPointSize(14);
        label_12->setFont(font3);

        horizontalLayout_9->addWidget(label_12);

        DevMsg_bt = new QPushButton(layoutWidget8);
        DevMsg_bt->setObjectName("DevMsg_bt");

        horizontalLayout_9->addWidget(DevMsg_bt);

        pushButton_13 = new QPushButton(layoutWidget8);
        pushButton_13->setObjectName("pushButton_13");

        horizontalLayout_9->addWidget(pushButton_13);

        layoutWidget9 = new QWidget(groupBox_6);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(1180, 10, 86, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget9);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);

        horizontalLayout_4->addWidget(label_15);

        label_16 = new QLabel(layoutWidget9);
        label_16->setObjectName("label_16");
        QFont font4;
        font4.setPointSize(10);
        label_16->setFont(font4);

        horizontalLayout_4->addWidget(label_16);

        layoutWidget10 = new QWidget(Widget);
        layoutWidget10->setObjectName("layoutWidget10");
        layoutWidget10->setGeometry(QRect(180, 530, 245, 29));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget10);
        label_13->setObjectName("label_13");
        label_13->setFont(font2);

        horizontalLayout_18->addWidget(label_13);

        ctrolMode_ComboBox = new QComboBox(layoutWidget10);
        ctrolMode_ComboBox->addItem(QString());
        ctrolMode_ComboBox->addItem(QString());
        ctrolMode_ComboBox->addItem(QString());
        ctrolMode_ComboBox->addItem(QString());
        ctrolMode_ComboBox->setObjectName("ctrolMode_ComboBox");
        ctrolMode_ComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3a3a3a;\n"
"    color: #eeeeee;\n"
"    border: 1px solid #666;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #0099ff;\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\350\217\234\345\215\225\346\225\264\344\275\223 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #444;\n"
"}\n"
"\n"
"/* \346\257\217\344\270\200\351\241\271\347\232\204\351\273\230\350\256\244\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item {\n"
"    padding: 6px;\n"
"    color: #eeeeee;\n"
"}\n"
"\n"
"/* \342\236\244 \345\274\272\345\210\266\351\200\211\344\270\255\351\253\230\344\272\256\357\274\210\345\205\263\351\224\256\357\274\201\357\274\211 */\n"
"QComboBox QAbstractItemView::item:selected {\n"
"    background-color: #00aaff;\n"
"    color: #000000;\n"
"}\n"
""));

        horizontalLayout_18->addWidget(ctrolMode_ComboBox);

        groupBox_8 = new QGroupBox(Widget);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(880, 640, 391, 121));
        log_txt = new QTextBrowser(groupBox_8);
        log_txt->setObjectName("log_txt");
        log_txt->setGeometry(QRect(10, 20, 371, 91));
        layoutWidget11 = new QWidget(Widget);
        layoutWidget11->setObjectName("layoutWidget11");
        layoutWidget11->setGeometry(QRect(680, 530, 584, 110));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(layoutWidget11);
        groupBox_5->setObjectName("groupBox_5");
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName("gridLayout_2");
        iqPID_kp_te = new QTextEdit(groupBox_5);
        iqPID_kp_te->setObjectName("iqPID_kp_te");
        iqPID_kp_te->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(iqPID_kp_te, 0, 0, 1, 1);

        iqPID_kp_tb = new QPushButton(groupBox_5);
        iqPID_kp_tb->setObjectName("iqPID_kp_tb");
        iqPID_kp_tb->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(iqPID_kp_tb, 0, 1, 1, 1);

        iqPID_ki_te = new QTextEdit(groupBox_5);
        iqPID_ki_te->setObjectName("iqPID_ki_te");
        iqPID_ki_te->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(iqPID_ki_te, 1, 0, 1, 1);

        iqPID_ki_tb = new QPushButton(groupBox_5);
        iqPID_ki_tb->setObjectName("iqPID_ki_tb");
        iqPID_ki_tb->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(iqPID_ki_tb, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox_5);

        groupBox_9 = new QGroupBox(layoutWidget11);
        groupBox_9->setObjectName("groupBox_9");
        gridLayout_3 = new QGridLayout(groupBox_9);
        gridLayout_3->setObjectName("gridLayout_3");
        speedPID_kp_te = new QTextEdit(groupBox_9);
        speedPID_kp_te->setObjectName("speedPID_kp_te");
        speedPID_kp_te->setMaximumSize(QSize(80, 30));

        gridLayout_3->addWidget(speedPID_kp_te, 0, 0, 1, 1);

        speedPID_kp_tb = new QPushButton(groupBox_9);
        speedPID_kp_tb->setObjectName("speedPID_kp_tb");
        speedPID_kp_tb->setMaximumSize(QSize(80, 30));

        gridLayout_3->addWidget(speedPID_kp_tb, 0, 1, 1, 1);

        speedPID_ki_te = new QTextEdit(groupBox_9);
        speedPID_ki_te->setObjectName("speedPID_ki_te");
        speedPID_ki_te->setMaximumSize(QSize(80, 30));

        gridLayout_3->addWidget(speedPID_ki_te, 1, 0, 1, 1);

        speedPID_ki_tb = new QPushButton(groupBox_9);
        speedPID_ki_tb->setObjectName("speedPID_ki_tb");
        speedPID_ki_tb->setMaximumSize(QSize(80, 30));

        gridLayout_3->addWidget(speedPID_ki_tb, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox_9);

        groupBox_7 = new QGroupBox(layoutWidget11);
        groupBox_7->setObjectName("groupBox_7");
        gridLayout_5 = new QGridLayout(groupBox_7);
        gridLayout_5->setObjectName("gridLayout_5");
        textEdit_8 = new QTextEdit(groupBox_7);
        textEdit_8->setObjectName("textEdit_8");
        textEdit_8->setMaximumSize(QSize(80, 30));

        gridLayout_5->addWidget(textEdit_8, 0, 0, 1, 1);

        pushButton_10 = new QPushButton(groupBox_7);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setMaximumSize(QSize(80, 30));

        gridLayout_5->addWidget(pushButton_10, 0, 1, 1, 1);

        textEdit_9 = new QTextEdit(groupBox_7);
        textEdit_9->setObjectName("textEdit_9");
        textEdit_9->setMaximumSize(QSize(80, 30));

        gridLayout_5->addWidget(textEdit_9, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(groupBox_7);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setMaximumSize(QSize(80, 30));

        gridLayout_5->addWidget(pushButton_11, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox_7);

        groupBox_10 = new QGroupBox(Widget);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(680, 639, 191, 121));

        retranslateUi(Widget);

        BuadRate_ComboBox->setCurrentIndex(10);
        DataBits_comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\346\233\262\347\272\277\346\211\223\345\215\260", nullptr));
        speed_bt->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246", nullptr));
        Iabc_bt->setText(QCoreApplication::translate("Widget", "\344\270\211\347\233\270\347\224\265\346\265\201", nullptr));
        UAlpha_Beta_bt->setText(QCoreApplication::translate("Widget", "UAlpha_Beta", nullptr));
        speedOut_bt->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\347\216\257\350\276\223\345\207\272", nullptr));
        IAlpha_Beta_bt->setText(QCoreApplication::translate("Widget", "IAlpha_Beta", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\344\275\215\347\275\256", nullptr));
        Uabc_bt->setText(QCoreApplication::translate("Widget", "\344\270\211\347\233\270\347\224\265\345\216\213\346\233\262\347\272\277", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\347\224\265\346\265\201\347\216\257\350\276\223\345\207\272", nullptr));
        mechanicalAngle_bt->setText(QCoreApplication::translate("Widget", "\346\234\272\346\242\260\350\247\222\345\272\246", nullptr));
        SVPWM_bt->setText(QCoreApplication::translate("Widget", "\344\270\211\347\233\270SVPWM", nullptr));
        iq_id_bt->setText(QCoreApplication::translate("Widget", "IQ_ID", nullptr));
        adc_bt->setText(QCoreApplication::translate("Widget", "\344\270\211\347\233\270ADC", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "\344\275\215\347\275\256\347\216\257\350\276\223\345\207\272", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        BuadRate_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "4800", nullptr));
        BuadRate_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "9600", nullptr));
        BuadRate_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "38400", nullptr));
        BuadRate_ComboBox->setItemText(3, QCoreApplication::translate("Widget", "115200", nullptr));
        BuadRate_ComboBox->setItemText(4, QCoreApplication::translate("Widget", "921600", nullptr));
        BuadRate_ComboBox->setItemText(5, QCoreApplication::translate("Widget", "1500000", nullptr));
        BuadRate_ComboBox->setItemText(6, QCoreApplication::translate("Widget", "2000000", nullptr));
        BuadRate_ComboBox->setItemText(7, QCoreApplication::translate("Widget", "2500000", nullptr));
        BuadRate_ComboBox->setItemText(8, QCoreApplication::translate("Widget", "3000000", nullptr));
        BuadRate_ComboBox->setItemText(9, QCoreApplication::translate("Widget", "3500000", nullptr));
        BuadRate_ComboBox->setItemText(10, QCoreApplication::translate("Widget", "4000000", nullptr));

        BuadRate_ComboBox->setCurrentText(QCoreApplication::translate("Widget", "4000000", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        DataBits_comboBox->setItemText(0, QCoreApplication::translate("Widget", "5", nullptr));
        DataBits_comboBox->setItemText(1, QCoreApplication::translate("Widget", "6", nullptr));
        DataBits_comboBox->setItemText(2, QCoreApplication::translate("Widget", "7", nullptr));
        DataBits_comboBox->setItemText(3, QCoreApplication::translate("Widget", "8", nullptr));

        label_6->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        StopBits_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        StopBits_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "1.5", nullptr));
        StopBits_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "2", nullptr));

        label_7->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        Parity_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "None", nullptr));
        Parity_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "Even", nullptr));
        Parity_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "Odd", nullptr));
        Parity_ComboBox->setItemText(3, QCoreApplication::translate("Widget", "Space", nullptr));
        Parity_ComboBox->setItemText(4, QCoreApplication::translate("Widget", "Mark", nullptr));

        openserial_bt->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        serialStatus->setText(QString());
        groupBox_3->setTitle(QString());
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("Widget", "\347\224\265\346\234\272\351\205\215\347\275\256", nullptr));
        connectMotor_bt->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        connet_motor_pic->setText(QString());
        setPairs_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\236\201\345\257\271\346\225\260", nullptr));
        setDir_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\350\247\222\345\272\246\346\226\271\345\220\221", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\351\233\266\345\201\217\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\347\224\265\350\247\222\345\272\246", nullptr));
        dcBus_bt->setText(QCoreApplication::translate("Widget", "\346\257\215\347\272\277\347\224\265\345\216\213", nullptr));
        mosTemp_bar->setFormat(QCoreApplication::translate("Widget", "%p\302\260C", nullptr));
        mosTemp_lab->setText(QString());
        label_14->setText(QCoreApplication::translate("Widget", "MOS\346\270\251\345\272\246", nullptr));
        setSpeedDir_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\351\200\237\345\272\246\346\226\271\345\220\221", nullptr));
        zeroOffset_bt->setText(QCoreApplication::translate("Widget", "\351\233\266\347\224\265\344\275\215\346\240\241\345\207\206", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\347\273\231\345\256\232\346\216\247\345\210\266\346\234\237\346\234\233", nullptr));
        setUq_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Uq", nullptr));
        setUd_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Ud", nullptr));
        setIQ_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Iq", nullptr));
        setID_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Id", nullptr));
        setSpeedTar_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\351\200\237\345\272\246", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\344\275\215\347\275\256", nullptr));
        groupBox_6->setTitle(QString());
        label_12->setText(QCoreApplication::translate("Widget", "LiJointMaster", nullptr));
        DevMsg_bt->setText(QCoreApplication::translate("Widget", "\345\274\200\345\217\221\350\200\205\347\225\231\350\250\200", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "\347\211\210\346\234\254\345\217\267", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "1.0.0", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\346\216\247\345\210\266\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        ctrolMode_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "\345\274\200\347\216\257\346\250\241\345\274\217", nullptr));
        ctrolMode_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));
        ctrolMode_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "\351\200\237\345\272\246-\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));
        ctrolMode_ComboBox->setItemText(3, QCoreApplication::translate("Widget", "\344\275\215\347\275\256-\351\200\237\345\272\246-\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));

        groupBox_8->setTitle(QCoreApplication::translate("Widget", "LOG\344\277\241\346\201\257", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "\347\224\265\346\265\201\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        iqPID_kp_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        iqPID_ki_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KI", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        speedPID_kp_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        speedPID_ki_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KI", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Widget", "\344\275\215\347\275\256\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KD", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
