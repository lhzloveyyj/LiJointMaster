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

static QMutex logMutex; ///< 线程安全锁，保证多线程下日志安全

// ⭐ 定义默认 handler，用于保留原始 Qt 输出
QtMessageHandler LogHelper::defaultHandler = nullptr;

/**
 * @brief 构造函数
 * @param parent 父对象
 *
 * 初始化 LogHelper 对象。
 */
LogHelper::LogHelper(QObject *parent)
    : QObject(parent)
{
}

/**
 * @brief 获取 LogHelper 单例
 * @return LogHelper 指针
 *
 * 使用静态局部变量实现线程安全的单例模式。
 */
LogHelper *LogHelper::instance()
{
    static LogHelper helper;
    return &helper;
}

/**
 * @brief 安装自定义日志处理函数
 *
 * 1️⃣ 保存 Qt 原来的输出函数（stdout/stderr + 颜色）
 * 2️⃣ 设置我们自定义的 messageHandler
 */
void LogHelper::install()
{
    // ⭐ 保存 Qt 原来的输出函数
    defaultHandler = qInstallMessageHandler(nullptr);

    // ⭐ 设置自定义 handler
    qInstallMessageHandler(LogHelper::messageHandler);
}

/**
 * @brief Qt 日志消息处理函数
 * @param type 消息类型
 * @param context 日志上下文信息
 * @param msg 日志内容
 *
 * 将 Qt 日志消息格式化为 HTML，并通过信号发送给 UI。
 */
void LogHelper::messageHandler(QtMsgType type,
                               const QMessageLogContext &context,
                               const QString &msg)
{
    QMutexLocker locker(&logMutex); // 线程安全保护

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

    // 3️⃣ ⛔ 只发送一次！不能重复发信号
    emit LogHelper::instance()->newLog(html);
}
