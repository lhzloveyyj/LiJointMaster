#include "widget.h"

#include <QApplication>
#include "LogHelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LogHelper::install();   // ★ 捕获 qDebug 输出

    Widget w;
    w.show();
    return a.exec();
}
