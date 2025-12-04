#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QObject>
#include <QtMessageHandler>

/**
 * @brief LogHelper
 * 用于捕获 Qt 全局日志（qDebug/qWarning/qCritical/qInfo）
 * 并通过信号发送带 HTML 颜色的日志信息到 UI。
 *
 * 使用方法：
 * - 在 main() 中调用 LogHelper::install() 安装自定义日志处理
 * - 通过 LogHelper::instance()->newLog() 信号连接到 UI 显示
 */
class LogHelper : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent 父对象
     */
    explicit LogHelper(QObject *parent = nullptr);

    /**
     * @brief 获取单例对象
     * @return LogHelper 单例指针
     */
    static LogHelper *instance();

    /**
     * @brief 安装日志处理
     * ⭐ 会替换 Qt 原有全局日志处理函数
     */
    static void install();

    /**
     * @brief 自定义 Qt 日志处理函数
     * @param type 日志类型（QtDebugMsg/QtWarningMsg/QtCriticalMsg/QtInfoMsg）
     * @param context 日志上下文（文件名、行号、函数名等）
     * @param msg 日志消息
     *
     * 内部会：
     * - 保留原控制台输出
     * - 将日志转换成带 HTML 颜色的字符串
     * - 发射 newLog() 信号
     */
    static void messageHandler(QtMsgType type,
                               const QMessageLogContext &context,
                               const QString &msg);

signals:
    /**
     * @brief 新日志信号
     * @param msg 带 HTML 的日志消息
     */
    void newLog(const QString &msg);

private:
    static QtMessageHandler defaultHandler;   ///< 保存 Qt 原始日志处理函数
};

#endif // LOGHELPER_H
