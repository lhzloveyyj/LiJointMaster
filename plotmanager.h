#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#pragma once
#include <QObject>
#include <QVector>
#include <QPen>
#include <QMap>
#include <QTimer>
#include "qcustomplot.h"

/**
 * @brief PlotManager
 * 管理 QCustomPlot 曲线绘图
 *
 * 功能：
 * - 添加曲线并设置颜色
 * - 追加数据并自动滚动显示
 * - 设置X轴显示范围
 */
class PlotManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param plotWidget 指向 QCustomPlot 的指针
     * @param parent 父对象
     */
    explicit PlotManager(QCustomPlot *plotWidget, QObject *parent = nullptr);

    /**
     * @brief 添加曲线
     * @param name 曲线名称（唯一）
     * @param color 曲线颜色
     */
    void addGraph(const QString &name, const QColor &color);

    /**
     * @brief 设置X轴显示时间范围（秒）
     */
    void setXAxisRange(double rangeSec);

public slots:
    /**
     * @brief 向指定曲线追加数据
     * @param name 曲线名
     * @param value 新增数据值
     */
    void appendData(const QString &name, double value);

private:
    QCustomPlot *m_plot;        ///< 绘图控件指针
    QTimer *m_replotTimer;      ///< 定时刷新绘图

    struct GraphData {
        QCPGraph *graph;        ///< QCustomPlot 曲线对象
        QVector<double> data;   ///< 曲线数据缓存
    };

    QMap<QString, GraphData> m_graphs;  ///< 曲线集合，key=曲线名
    double m_key;                        ///< X轴时间/采样点
    double m_xAxisRange;                 ///< 当前显示X轴时间范围（秒）
};

#endif // PLOTMANAGER_H
