#include "plotmanager.h"

PlotManager::PlotManager(QCustomPlot *plotWidget, QObject *parent)
    : QObject(parent),
    m_plot(plotWidget),
    m_key(0),
    m_xAxisRange(5)   // 默认显示5秒
{
    // 坐标轴样式
    m_plot->xAxis->setLabel("Time (s)");
    m_plot->yAxis->setLabel("Value");

    m_plot->xAxis->setBasePen(QPen(Qt::white));
    m_plot->yAxis->setBasePen(QPen(Qt::white));
    m_plot->xAxis->setTickPen(QPen(Qt::white));
    m_plot->yAxis->setTickPen(QPen(Qt::white));
    m_plot->xAxis->setSubTickPen(QPen(Qt::white));
    m_plot->yAxis->setSubTickPen(QPen(Qt::white));
    m_plot->xAxis->setTickLabelColor(Qt::white);
    m_plot->yAxis->setTickLabelColor(Qt::white);
    m_plot->xAxis->setLabelColor(Qt::white);
    m_plot->yAxis->setLabelColor(Qt::white);
    m_plot->xAxis->grid()->setPen(QPen(QColor(80, 80, 80)));
    m_plot->yAxis->grid()->setPen(QPen(QColor(80, 80, 80)));

    // 鼠标交互
    m_plot->setInteraction(QCP::iRangeDrag);
    m_plot->setInteraction(QCP::iRangeZoom);

    // 定时刷新
    m_replotTimer = new QTimer(this);
    m_replotTimer->setInterval(30); // 每 30ms 刷新一次
    connect(m_replotTimer, &QTimer::timeout, [this](){
        if (m_plot) m_plot->replot();
    });
    m_replotTimer->start();
}

void PlotManager::addGraph(const QString &name, const QColor &color)
{
    if (m_graphs.contains(name)) return;

    QCPGraph *graph = m_plot->addGraph();
    graph->setPen(QPen(color));
    m_graphs[name] = { graph, QVector<double>() };
}

void PlotManager::appendData(const QString &name, double value)
{
    if (!m_graphs.contains(name)) return;

    m_key += 0.001; // 假设采样间隔 1ms

    GraphData &g = m_graphs[name];
    g.data.append(value);
    g.graph->addData(m_key, value);

    // 滚动显示最后 m_xAxisRange 秒
    m_plot->xAxis->setRange(m_key, m_xAxisRange, Qt::AlignRight);
}

void PlotManager::setXAxisRange(double seconds)
{
    m_xAxisRange = seconds;
    if (!m_graphs.isEmpty()) {
        double latestKey = m_key;
        m_plot->xAxis->setRange(latestKey - m_xAxisRange, latestKey);
    }
}



