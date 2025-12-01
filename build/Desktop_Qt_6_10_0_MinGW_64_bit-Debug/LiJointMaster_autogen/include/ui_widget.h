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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QPushButton *pushButton_5;
    QPushButton *Iabc_bt;
    QPushButton *UAlpha_Beta_bt;
    QPushButton *pushButton_9;
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
    QWidget *widget;
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *connectMotor_bt;
    QLabel *connet_motor_pic;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *setPairs_te;
    QPushButton *setPairs_bt;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *setDir_te;
    QPushButton *setDir_bt;
    QPushButton *zeroOffset_bt;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QTextEdit *zeroOffset_te;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QTextEdit *correctedElecAngle_te;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *dcBus_bt;
    QTextEdit *dcBus_te;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QTextEdit *textEdit_3;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_14;
    QTextEdit *setUq_te;
    QPushButton *setUq_bt;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_16;
    QTextEdit *setIQ_te;
    QPushButton *setIQ_tb;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_17;
    QTextEdit *setID_te;
    QPushButton *setID_tb;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_6;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_10;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_9;
    QPushButton *pushButton_11;
    QGroupBox *groupBox_9;
    QPushButton *pushButton_14;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_13;
    QPushButton *pushButton_15;
    QGroupBox *groupBox_6;
    QLabel *label_12;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QComboBox *ctrolMode_ComboBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1300, 770);
        plotWidget = new QCustomPlot(Widget);
        plotWidget->setObjectName("plotWidget");
        plotWidget->setGeometry(QRect(160, 60, 1121, 451));
        x_Axis_sd = new QSlider(Widget);
        x_Axis_sd->setObjectName("x_Axis_sd");
        x_Axis_sd->setGeometry(QRect(190, 510, 1081, 20));
        x_Axis_sd->setMaximum(200);
        x_Axis_sd->setOrientation(Qt::Orientation::Horizontal);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 570, 291, 191));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        pushButton_5->setCheckable(true);

        gridLayout->addWidget(pushButton_5, 2, 2, 1, 1);

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

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #2ecc71;     /* \346\214\211\344\270\213\357\274\210checked\357\274\211\345\217\230\344\272\256\347\273\277\350\211\262 */\n"
"    color: black;                  /* \346\233\264\346\230\216\346\230\276 */\n"
"    font-weight: bold;\n"
"    border: 2px solid #27ae60;\n"
"}"));
        pushButton_9->setCheckable(true);

        gridLayout->addWidget(pushButton_9, 3, 2, 1, 1);

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
        groupBox_2->setGeometry(QRect(10, 60, 151, 241));
        widget = new QWidget(groupBox_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 124, 227));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial.png);"));

        horizontalLayout_7->addWidget(label_2);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(84, 30));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout_7->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_24->addWidget(label_3);

        ComPort_ComboBox = new QComboBox(widget);
        ComPort_ComboBox->setObjectName("ComPort_ComboBox");

        horizontalLayout_24->addWidget(ComPort_ComboBox);


        verticalLayout->addLayout(horizontalLayout_24);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_23->addWidget(label_4);

        BuadRate_ComboBox = new QComboBox(widget);
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
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        horizontalLayout_22->addWidget(label_5);

        DataBits_comboBox = new QComboBox(widget);
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->setObjectName("DataBits_comboBox");

        horizontalLayout_22->addWidget(DataBits_comboBox);


        verticalLayout->addLayout(horizontalLayout_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        horizontalLayout_21->addWidget(label_6);

        StopBits_ComboBox = new QComboBox(widget);
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->setObjectName("StopBits_ComboBox");

        horizontalLayout_21->addWidget(StopBits_ComboBox);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        horizontalLayout_20->addWidget(label_7);

        Parity_ComboBox = new QComboBox(widget);
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
        openserial_bt = new QPushButton(widget);
        openserial_bt->setObjectName("openserial_bt");

        horizontalLayout->addWidget(openserial_bt);

        serialStatus = new QLabel(widget);
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
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(11, 11, 102, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(30, 30));
        label_9->setMaximumSize(QSize(30, 30));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/motor.png);"));

        horizontalLayout_8->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");
        label_10->setFont(font2);

        horizontalLayout_8->addWidget(label_10);

        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(11, 49, 108, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        connectMotor_bt = new QPushButton(layoutWidget1);
        connectMotor_bt->setObjectName("connectMotor_bt");

        horizontalLayout_6->addWidget(connectMotor_bt);

        connet_motor_pic = new QLabel(layoutWidget1);
        connet_motor_pic->setObjectName("connet_motor_pic");
        connet_motor_pic->setMinimumSize(QSize(20, 20));
        connet_motor_pic->setMaximumSize(QSize(30, 30));
        connet_motor_pic->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial_down.png);"));
        connet_motor_pic->setScaledContents(true);
        connet_motor_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(connet_motor_pic);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(11, 80, 128, 32));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        setPairs_te = new QTextEdit(layoutWidget2);
        setPairs_te->setObjectName("setPairs_te");
        setPairs_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_10->addWidget(setPairs_te);

        setPairs_bt = new QPushButton(layoutWidget2);
        setPairs_bt->setObjectName("setPairs_bt");
        setPairs_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_10->addWidget(setPairs_bt);

        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(11, 118, 128, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        setDir_te = new QTextEdit(layoutWidget3);
        setDir_te->setObjectName("setDir_te");
        setDir_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_11->addWidget(setDir_te);

        setDir_bt = new QPushButton(layoutWidget3);
        setDir_bt->setObjectName("setDir_bt");
        setDir_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(setDir_bt);

        zeroOffset_bt = new QPushButton(groupBox_3);
        zeroOffset_bt->setObjectName("zeroOffset_bt");
        zeroOffset_bt->setGeometry(QRect(11, 156, 80, 23));
        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(11, 185, 136, 32));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);

        horizontalLayout_12->addWidget(label_8);

        zeroOffset_te = new QTextEdit(layoutWidget4);
        zeroOffset_te->setObjectName("zeroOffset_te");
        zeroOffset_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_12->addWidget(zeroOffset_te);

        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(11, 223, 136, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget5);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        horizontalLayout_13->addWidget(label_11);

        correctedElecAngle_te = new QTextEdit(layoutWidget5);
        correctedElecAngle_te->setObjectName("correctedElecAngle_te");
        correctedElecAngle_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_13->addWidget(correctedElecAngle_te);

        layoutWidget6 = new QWidget(groupBox_3);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(11, 261, 133, 32));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        dcBus_bt = new QPushButton(layoutWidget6);
        dcBus_bt->setObjectName("dcBus_bt");
        dcBus_bt->setMaximumSize(QSize(60, 30));

        horizontalLayout_15->addWidget(dcBus_bt);

        dcBus_te = new QTextEdit(layoutWidget6);
        dcBus_te->setObjectName("dcBus_te");
        dcBus_te->setMaximumSize(QSize(65, 30));

        horizontalLayout_15->addWidget(dcBus_te);

        widget1 = new QWidget(groupBox_3);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(12, 301, 133, 32));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(pushButton_3);

        textEdit_3 = new QTextEdit(widget1);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setMaximumSize(QSize(65, 30));

        horizontalLayout_4->addWidget(textEdit_3);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(480, 530, 191, 231));
        layoutWidget7 = new QWidget(groupBox_4);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(10, 20, 168, 32));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        setUq_te = new QTextEdit(layoutWidget7);
        setUq_te->setObjectName("setUq_te");
        setUq_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_14->addWidget(setUq_te);

        setUq_bt = new QPushButton(layoutWidget7);
        setUq_bt->setObjectName("setUq_bt");
        setUq_bt->setMaximumSize(QSize(80, 30));

        horizontalLayout_14->addWidget(setUq_bt);

        layoutWidget8 = new QWidget(groupBox_4);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(10, 60, 168, 32));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        setIQ_te = new QTextEdit(layoutWidget8);
        setIQ_te->setObjectName("setIQ_te");
        setIQ_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_16->addWidget(setIQ_te);

        setIQ_tb = new QPushButton(layoutWidget8);
        setIQ_tb->setObjectName("setIQ_tb");
        setIQ_tb->setMaximumSize(QSize(80, 30));

        horizontalLayout_16->addWidget(setIQ_tb);

        layoutWidget9 = new QWidget(groupBox_4);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(10, 100, 168, 32));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        setID_te = new QTextEdit(layoutWidget9);
        setID_te->setObjectName("setID_te");
        setID_te->setMaximumSize(QSize(80, 30));

        horizontalLayout_17->addWidget(setID_te);

        setID_tb = new QPushButton(layoutWidget9);
        setID_tb->setObjectName("setID_tb");
        setID_tb->setMaximumSize(QSize(80, 30));

        horizontalLayout_17->addWidget(setID_tb);

        widget2 = new QWidget(groupBox_4);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 140, 168, 32));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget2);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(textEdit);

        pushButton = new QPushButton(widget2);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(pushButton);

        widget3 = new QWidget(groupBox_4);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(10, 180, 168, 32));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        textEdit_2 = new QTextEdit(widget3);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(textEdit_2);

        pushButton_2 = new QPushButton(widget3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(pushButton_2);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(680, 530, 191, 111));
        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(100, 30, 80, 30));
        pushButton_6->setMaximumSize(QSize(80, 30));
        textEdit_4 = new QTextEdit(groupBox_5);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(10, 30, 80, 30));
        textEdit_4->setMaximumSize(QSize(80, 30));
        textEdit_5 = new QTextEdit(groupBox_5);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(10, 70, 80, 30));
        textEdit_5->setMaximumSize(QSize(80, 30));
        pushButton_7 = new QPushButton(groupBox_5);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(100, 70, 80, 30));
        pushButton_7->setMaximumSize(QSize(80, 30));
        groupBox_7 = new QGroupBox(Widget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(680, 650, 191, 111));
        pushButton_10 = new QPushButton(groupBox_7);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(100, 30, 80, 30));
        pushButton_10->setMaximumSize(QSize(80, 30));
        textEdit_8 = new QTextEdit(groupBox_7);
        textEdit_8->setObjectName("textEdit_8");
        textEdit_8->setGeometry(QRect(10, 30, 80, 30));
        textEdit_8->setMaximumSize(QSize(80, 30));
        textEdit_9 = new QTextEdit(groupBox_7);
        textEdit_9->setObjectName("textEdit_9");
        textEdit_9->setGeometry(QRect(10, 70, 80, 30));
        textEdit_9->setMaximumSize(QSize(80, 30));
        pushButton_11 = new QPushButton(groupBox_7);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(100, 70, 80, 30));
        pushButton_11->setMaximumSize(QSize(80, 30));
        groupBox_9 = new QGroupBox(Widget);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(880, 530, 191, 111));
        pushButton_14 = new QPushButton(groupBox_9);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(100, 30, 80, 30));
        pushButton_14->setMaximumSize(QSize(80, 30));
        textEdit_12 = new QTextEdit(groupBox_9);
        textEdit_12->setObjectName("textEdit_12");
        textEdit_12->setGeometry(QRect(10, 30, 80, 30));
        textEdit_12->setMaximumSize(QSize(80, 30));
        textEdit_13 = new QTextEdit(groupBox_9);
        textEdit_13->setObjectName("textEdit_13");
        textEdit_13->setGeometry(QRect(10, 70, 80, 30));
        textEdit_13->setMaximumSize(QSize(80, 30));
        pushButton_15 = new QPushButton(groupBox_9);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(100, 70, 80, 30));
        pushButton_15->setMaximumSize(QSize(80, 30));
        groupBox_6 = new QGroupBox(Widget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 10, 1271, 41));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 10, 131, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font3.setPointSize(14);
        label_12->setFont(font3);
        widget4 = new QWidget(Widget);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(180, 530, 245, 29));
        horizontalLayout_18 = new QHBoxLayout(widget4);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(widget4);
        label_13->setObjectName("label_13");
        label_13->setFont(font2);

        horizontalLayout_18->addWidget(label_13);

        ctrolMode_ComboBox = new QComboBox(widget4);
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


        retranslateUi(Widget);

        BuadRate_ComboBox->setCurrentIndex(10);
        DataBits_comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\346\233\262\347\272\277\346\211\223\345\215\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246", nullptr));
        Iabc_bt->setText(QCoreApplication::translate("Widget", "\344\270\211\347\233\270\347\224\265\346\265\201", nullptr));
        UAlpha_Beta_bt->setText(QCoreApplication::translate("Widget", "UAlpha_Beta", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\347\216\257\350\276\223\345\207\272", nullptr));
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
        setDir_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\226\271\345\220\221", nullptr));
        zeroOffset_bt->setText(QCoreApplication::translate("Widget", "\351\233\266\347\224\265\344\275\215\346\240\241\345\207\206", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\351\233\266\345\201\217\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\347\224\265\350\247\222\345\272\246", nullptr));
        dcBus_bt->setText(QCoreApplication::translate("Widget", "\346\257\215\347\272\277\347\224\265\345\216\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "MOS\346\270\251\345\272\246", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\347\273\231\345\256\232\346\216\247\345\210\266\346\234\237\346\234\233", nullptr));
        setUq_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Uq", nullptr));
        setIQ_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Iq", nullptr));
        setID_tb->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256Id", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\351\200\237\345\272\246", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\344\275\215\347\275\256", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "\347\224\265\346\265\201\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KI", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KI", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("Widget", "\344\275\215\347\275\256\347\216\257PID\345\217\202\346\225\260\346\225\264\345\256\232", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KP", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256KD", nullptr));
        groupBox_6->setTitle(QString());
        label_12->setText(QCoreApplication::translate("Widget", "LiJointMaster", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\346\216\247\345\210\266\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        ctrolMode_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "\345\274\200\347\216\257\346\250\241\345\274\217", nullptr));
        ctrolMode_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));
        ctrolMode_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "\351\200\237\345\272\246-\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));
        ctrolMode_ComboBox->setItemText(3, QCoreApplication::translate("Widget", "\344\275\215\347\275\256-\351\200\237\345\272\246-\345\212\233\347\237\251\346\216\247\345\210\266", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
