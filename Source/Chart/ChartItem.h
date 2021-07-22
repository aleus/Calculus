/// @author M. A. Serebrennikov
#pragma once

#include "ChartData.h"

#include <qnanoquickitem.h>
#include <valarray>
#include <memory>

namespace sp {

class ChartItemPainter;

class ChartItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(ChartData * chartData READ chartDataRaw WRITE setChartDataRaw NOTIFY chartDataChanged)
    Q_PROPERTY(qreal xShift READ xShift WRITE setXShift NOTIFY xShiftChanged)
    Q_PROPERTY(qreal yShift READ yShift WRITE setYShift NOTIFY yShiftChanged)
    Q_PROPERTY(qreal xScale READ xScale WRITE setXScale NOTIFY xScaleChanged)
    Q_PROPERTY(qreal yScale READ yScale WRITE setYScale NOTIFY yScaleChanged)
    Q_PROPERTY(int pointSize READ pointSize WRITE setPointSize NOTIFY pointSizeChanged)

    public:
        ChartItem(QQuickItem *parent = nullptr);

        //----------------------------------------------------------------------
        // GET
        //----------------------------------------------------------------------
        inline const auto & chartData() const { return _chartData; }
        inline ChartData * chartDataRaw() const { return _chartData.get(); }
        inline int pointSize() const { return _pointSize; }

        inline auto xShift() const { return _xShift; }
        inline auto yShift() const { return _yShift; }
        inline auto xScale() const { return _xScale; }
        inline auto yScale() const { return _yScale; }

        //----------------------------------------------------------------------
        // SET
        //----------------------------------------------------------------------
        void setChartData(const ChartDataPtr & chartData);
        void setChartDataRaw(ChartData * chartData);
        void setXShift(qreal xShift);
        void setYShift(qreal yShift);
        void setXScale(qreal xScale);
        void setYScale(qreal yScale);
        void setPointSize(int pointSize);

        //----------------------------------------------------------------------
        // SPECIAL
        //----------------------------------------------------------------------
        void onAfterSync();

        //----------------------------------------------------------------------
        // OVERRIDE
        //----------------------------------------------------------------------
        QNanoQuickItemPainter *createItemPainter() const override;

    signals:
        void chartDataChanged();
        void xShiftChanged();
        void yShiftChanged();
        void xScaleChanged();
        void yScaleChanged();
        void pointSizeChanged();
        void wellPointsChanged();

    private:
        ChartDataPtr _chartData;
        qreal _xShift = 0.0;
        qreal _yShift = 0.0;
        qreal _xScale = 1.0;
        qreal _yScale = 1.0;
        int _pointSize = 0;
};

} // namespace sp {
