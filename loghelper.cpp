#include "LogHelper.h"
#include <QMutex>
#include <QDebug>

/*
qDebug() << "调试输出";
qInfo() << "一般信息输出";
qWarning() << "警告输出";
qCritical() << "严重错误";
qFatal("致命错误，程序终止");
*/

static QMutex logMutex;

// ⭐ 定义默认 handler
QtMessageHandler LogHelper::defaultHandler = nullptr;

LogHelper::LogHelper(QObject *parent)
    : QObject(parent)
{
}

LogHelper *LogHelper::instance()
{
    static LogHelper helper;
    return &helper;
}

void LogHelper::install()
{
    // ⭐ 保存 Qt 原来的输出函数（stdout/stderr + 颜色）
    defaultHandler = qInstallMessageHandler(nullptr);

    // ⭐ 设置我们自定义的 handler
    qInstallMessageHandler(LogHelper::messageHandler);
}

void LogHelper::messageHandler(QtMsgType type,
                               const QMessageLogContext &context,
                               const QString &msg)
{
    QMutexLocker locker(&logMutex);

    // 1️⃣ 保持原控制台输出（带原有颜色）
    if (defaultHandler)
        defaultHandler(type, context, msg);

    // 2️⃣ 生成一条带颜色的 HTML
    QString html;

    switch (type) {
    case QtDebugMsg:
        html = QString("<span style='color:#00ff00;'>[Debug] %1</span>").arg(msg);
        break;

    case QtWarningMsg:
        html = QString("<span style='color:#ffaa00;'>[Warning] %1</span>").arg(msg);
        break;

    case QtCriticalMsg:
        html = QString("<span style='color:#ff4444;'>[Critical] %1</span>").arg(msg);
        break;

    case QtInfoMsg:
        html = QString("<span style='color:#00bbff;'>[Info] %1</span>").arg(msg);
        break;

    default:
        html = msg;
        break;
    }

    // 3️⃣ ⛔ 只发送一次！不能重复！
    emit LogHelper::instance()->newLog(html);
}
