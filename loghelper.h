#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QObject>
#include <QtMessageHandler>

class LogHelper : public QObject
{
    Q_OBJECT
public:
    explicit LogHelper(QObject *parent = nullptr);
    static LogHelper *instance();
    static void install();

    static void messageHandler(QtMsgType type,
                               const QMessageLogContext &context,
                               const QString &msg);

signals:
    void newLog(const QString &msg);

private:
    static QtMessageHandler defaultHandler;   // ⭐ Qt5 必须手动保存默认 handler
};

#endif // LOGHELPER_H
