#ifndef MYPLOT_H
#define MYPLOT_H

#include "qcustomplot.h"

class MyPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit MyPlot(QWidget *parent = nullptr) : QCustomPlot(parent) {}

signals:
    void mouseLeave();

protected:
    void leaveEvent(QEvent *event) override {
        emit mouseLeave();
        QCustomPlot::leaveEvent(event);
    }
};

#endif // MYPLOT_H
