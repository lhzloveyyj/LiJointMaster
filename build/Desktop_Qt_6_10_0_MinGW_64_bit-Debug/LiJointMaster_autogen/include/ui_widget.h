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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *ComPort_ComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *BuadRate_ComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *DataBits_comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *StopBits_ComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *Parity_ComboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *openserial_bt;
    QLabel *serialStatus;
    QFrame *frame_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *connectMotor_bt;
    QLabel *connet_motor_pic;
    QPushButton *mechanicalAngle_bt;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *setPairs_te;
    QPushButton *setPairs_bt;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *setDir_te;
    QPushButton *setDir_bt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1280, 720);
        frame = new QFrame(Widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 70, 141, 201));
        frame->setFrameShape(QFrame::Shape::WinPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(11, 11, 118, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        ComPort_ComboBox = new QComboBox(layoutWidget);
        ComPort_ComboBox->setObjectName("ComPort_ComboBox");

        horizontalLayout->addWidget(ComPort_ComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        BuadRate_ComboBox = new QComboBox(layoutWidget);
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->addItem(QString());
        BuadRate_ComboBox->setObjectName("BuadRate_ComboBox");

        horizontalLayout_2->addWidget(BuadRate_ComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        DataBits_comboBox = new QComboBox(layoutWidget);
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->addItem(QString());
        DataBits_comboBox->setObjectName("DataBits_comboBox");

        horizontalLayout_3->addWidget(DataBits_comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        StopBits_ComboBox = new QComboBox(layoutWidget);
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->addItem(QString());
        StopBits_ComboBox->setObjectName("StopBits_ComboBox");

        horizontalLayout_4->addWidget(StopBits_ComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);

        Parity_ComboBox = new QComboBox(layoutWidget);
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->addItem(QString());
        Parity_ComboBox->setObjectName("Parity_ComboBox");

        horizontalLayout_5->addWidget(Parity_ComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 160, 118, 32));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        openserial_bt = new QPushButton(layoutWidget1);
        openserial_bt->setObjectName("openserial_bt");

        horizontalLayout_9->addWidget(openserial_bt);

        serialStatus = new QLabel(layoutWidget1);
        serialStatus->setObjectName("serialStatus");
        serialStatus->setMinimumSize(QSize(30, 30));
        serialStatus->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial_down.png);"));
        serialStatus->setScaledContents(true);
        serialStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(serialStatus);

        frame_2 = new QFrame(Widget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-1, -1, 1281, 41));
        frame_2->setFrameShape(QFrame::Shape::Box);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 40, 102, 32));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial.png);"));

        horizontalLayout_7->addWidget(label_2);

        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_7->addWidget(label);

        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 280, 102, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(30, 30));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/motor.png);"));

        horizontalLayout_8->addWidget(label_9);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        horizontalLayout_8->addWidget(label_10);

        layoutWidget4 = new QWidget(Widget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 320, 108, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        connectMotor_bt = new QPushButton(layoutWidget4);
        connectMotor_bt->setObjectName("connectMotor_bt");

        horizontalLayout_6->addWidget(connectMotor_bt);

        connet_motor_pic = new QLabel(layoutWidget4);
        connet_motor_pic->setObjectName("connet_motor_pic");
        connet_motor_pic->setMinimumSize(QSize(20, 20));
        connet_motor_pic->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/serial_down.png);"));
        connet_motor_pic->setScaledContents(true);
        connet_motor_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(connet_motor_pic);

        mechanicalAngle_bt = new QPushButton(Widget);
        mechanicalAngle_bt->setObjectName("mechanicalAngle_bt");
        mechanicalAngle_bt->setGeometry(QRect(10, 450, 80, 23));
        mechanicalAngle_bt->setCheckable(true);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 350, 128, 32));
        horizontalLayout_10 = new QHBoxLayout(widget);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        setPairs_te = new QTextEdit(widget);
        setPairs_te->setObjectName("setPairs_te");
        setPairs_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_10->addWidget(setPairs_te);

        setPairs_bt = new QPushButton(widget);
        setPairs_bt->setObjectName("setPairs_bt");
        setPairs_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_10->addWidget(setPairs_bt);

        widget1 = new QWidget(Widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 390, 128, 32));
        horizontalLayout_11 = new QHBoxLayout(widget1);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        setDir_te = new QTextEdit(widget1);
        setDir_te->setObjectName("setDir_te");
        setDir_te->setMaximumSize(QSize(40, 30));

        horizontalLayout_11->addWidget(setDir_te);

        setDir_bt = new QPushButton(widget1);
        setDir_bt->setObjectName("setDir_bt");
        setDir_bt->setMinimumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(setDir_bt);


        retranslateUi(Widget);

        BuadRate_ComboBox->setCurrentIndex(4);
        DataBits_comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        BuadRate_ComboBox->setItemText(0, QCoreApplication::translate("Widget", "4800", nullptr));
        BuadRate_ComboBox->setItemText(1, QCoreApplication::translate("Widget", "9600", nullptr));
        BuadRate_ComboBox->setItemText(2, QCoreApplication::translate("Widget", "38400", nullptr));
        BuadRate_ComboBox->setItemText(3, QCoreApplication::translate("Widget", "115200", nullptr));
        BuadRate_ComboBox->setItemText(4, QCoreApplication::translate("Widget", "921600", nullptr));

        BuadRate_ComboBox->setCurrentText(QCoreApplication::translate("Widget", "921600", nullptr));
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
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("Widget", "\347\224\265\346\234\272\351\205\215\347\275\256", nullptr));
        connectMotor_bt->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        connet_motor_pic->setText(QString());
        mechanicalAngle_bt->setText(QCoreApplication::translate("Widget", "\346\234\272\346\242\260\350\247\222\345\272\246", nullptr));
        setPairs_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\236\201\345\257\271\346\225\260", nullptr));
        setDir_bt->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\226\271\345\220\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
