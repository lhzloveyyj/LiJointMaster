#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/**
 * @brief Dialog 类
 *
 * 简单的模态对话框示例，用于显示开发者信息或其他消息。
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父对象指针
     *
     * 会初始化 UI。
     */
    explicit Dialog(QWidget *parent = nullptr);

    /**
     * @brief 析构函数
     *
     * 会释放 UI 指针。
     */
    ~Dialog();

private:
    Ui::Dialog *ui; ///< 对应 UI 文件的指针，用于访问控件
};

#endif // DIALOG_H
