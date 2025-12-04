#include "plotmanager.h"

/**
 * @brief 构造函数
 * @param plotWidget QCustomPlot 对象指针
 * @param parent 父对象
 *
 * 初始化坐标轴样式、鼠标交互和定时刷新。
 */
PlotManager::PlotManager(QCustomPlot *plotWidget, QObject *parent)
    : QObject(parent),
    m_plot(plotWidget),
    m_key(0),
    m_xAxisRange(5)   // 默认显示5秒
{
    // 1️⃣ 设置坐标轴标签
    m_plot->xAxis->setLabel("Time (s)");
    m_plot->yAxis->setLabel("Value");

    // 2️⃣ 坐标轴线条颜色
    m_plot->xAxis->setBasePen(QPen(Qt::white));
    m_plot->yAxis->setBasePen(QPen(Qt::white));
    m_plot->xAxis->setTickPen(QPen(Qt::white));
    m_plot->yAxis->setTickPen(QPen(Qt::white));
    m_plot->xAxis->setSubTickPen(QPen(Qt::white));
    m_plot->yAxis->setSubTickPen(QPen(Qt::white));

    // 3️⃣ 坐标轴文字颜色
    m_plot->xAxis->setTickLabelColor(Qt::white);
    m_plot->yAxis->setTickLabelColor(Qt::white);
    m_plot->xAxis->setLabelColor(Qt::white);
    m_plot->yAxis->setLabelColor(Qt::white);

    // 4️⃣ 网格线颜色
    m_plot->xAxis->grid()->setPen(QPen(QColor(80, 80, 80)));
    m_plot->yAxis->grid()->setPen(QPen(QColor(80, 80, 80)));

    // 5️⃣ 启用鼠标交互（拖动、缩放）
    m_plot->setInteraction(QCP::iRangeDrag);
    m_plot->setInteraction(QCP::iRangeZoom);

    // 6️⃣ 定时刷新绘图，每 30ms 刷新一次
    m_replotTimer = new QTimer(this);
    m_replotTimer->setInterval(30);
    connect(m_replotTimer, &QTimer::timeout, [this](){
        if (m_plot) m_plot->replot();
    });
    m_replotTimer->start();
}

/**
 * @brief 添加曲线
 * @param name 曲线名称（唯一）
 * @param color 曲线颜色
 *
 * 如果曲线已存在，则忽略。否则新建曲线并存储在 m_graphs。
 */
void PlotManager::addGraph(const QString &name, const QColor &color)
{
    if (m_graphs.contains(name)) return;

    // 1️⃣ 添加曲线
    QCPGraph *graph = m_plot->addGraph();
    graph->setPen(QPen(color));

    // 2️⃣ 保存曲线和对应数据缓存
    m_graphs[name] = { graph, QVector<double>() };
}

/**
 * @brief 添加新数据到指定曲线
 * @param name 曲线名称
 * @param value 新数据值
 *
 * 自动滚动显示最后 m_xAxisRange 秒数据。
 */
void PlotManager::appendData(const QString &name, double value)
{
    if (!m_graphs.contains(name)) return;

    // 1️⃣ 更新时间戳（假设采样间隔 0.5ms）
    m_key += 0.0005;

    // 2️⃣ 获取曲线及其缓存数据
    GraphData &g = m_graphs[name];

    // 3️⃣ 保存数据到缓存
    g.data.append(value);

    // 4️⃣ 添加数据到 QCustomPlot 曲线
    g.graph->addData(m_key, value);

    // 5️⃣ 滚动显示最后 m_xAxisRange 秒
    m_plot->xAxis->setRange(m_key, m_xAxisRange, Qt::AlignRight);
}

/**
 * @brief 设置 X 轴显示范围（秒）
 * @param seconds 显示范围，单位秒
 */
void PlotManager::setXAxisRange(double seconds)
{
    m_xAxisRange = seconds;

    // 1️⃣ 更新当前 X 轴显示范围
    if (!m_graphs.isEmpty()) {
        double latestKey = m_key;
        m_plot->xAxis->setRange(latestKey - m_xAxisRange, latestKey);
    }
}
