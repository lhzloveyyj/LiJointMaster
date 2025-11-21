#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#pragma once
#include <QObject>
#include <QVector>
#include <QPen>
#include <QMap>
#include <QTimer>
#include "qcustomplot.h"

class PlotManager : public QObject
{
    Q_OBJECT
public:
    explicit PlotManager(QCustomPlot *plotWidget, QObject *parent = nullptr);

    // 添加曲线
    void addGraph(const QString &name, const QColor &color);

    void setXAxisRange(double rangeSec);


public slots:
    // 通用数据追加函数
    void appendData(const QString &name, double value);

private:
    QCustomPlot *m_plot;
    QTimer *m_replotTimer;

    struct GraphData {
        QCPGraph *graph;
        QVector<double> data;
    };

    QMap<QString, GraphData> m_graphs;  // key: 曲线名
    double m_key;                        // X轴时间/采样点
    double m_xAxisRange;                 // 当前显示x轴时间范围
};

#endif // PLOTMANAGER_H
