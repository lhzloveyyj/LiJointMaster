#include "dialog.h"
#include "ui_dialog.h"

/**
 * @brief 构造函数
 * @param parent 父窗口指针
 *
 * 初始化 Dialog 对象，并设置 UI。
 */
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this); // 初始化界面控件
}

/**
 * @brief 析构函数
 *
 * 释放界面资源。
 */
Dialog::~Dialog()
{
    delete ui; // 删除 UI 对象，释放内存
}
