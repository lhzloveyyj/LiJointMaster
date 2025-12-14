#include "widget.h"
#include <QApplication>
#include "LogHelper.h"

/**
 * @brief 应用程序入口函数
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 返回程序执行状态
 *
 * 初始化 QApplication、日志捕获并显示主窗口 Widget。
 */
int main(int argc, char *argv[])
{
    // 1️⃣ 创建 Qt 应用程序对象
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/picture/ico.ico"));


    // 2️⃣ 安装日志捕获（将 qDebug、qWarning 等信息重定向）
    LogHelper::install();   // ★ 捕获 qDebug 输出

    // 3️⃣ 创建主窗口并显示
    Widget w;
    w.show();

    // 4️⃣ 启动 Qt 事件循环
    return a.exec();
}
