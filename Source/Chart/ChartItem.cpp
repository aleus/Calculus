/// @author M. A. Serebrennikov
#include "ChartItem.h"
#include "ChartItemPainter.h"
#include "ChartData.h"
#include "Core/Calc.h"

using namespace sp;

//------------------------------------------------------------------------------
ChartItem::ChartItem(QQuickItem *parent)
    : QNanoQuickItem(parent)
{
    connect(this, &ChartItem::pointSizeChanged, this, &ChartItem::update);

}

//------------------------------------------------------------------------------
void ChartItem::setChartData(const ChartDataPtr & chartData)
{
    if (_chartData != chartData) {
        if (_chartData) {
            _chartData->disconnect(this);
        }

        _chartData = chartData;

        update();
        connect(_chartData.get(), &ChartData::updated, this, &ChartItem::update);

        emit chartDataChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setChartDataRaw(ChartData * chartData)
{
    setChartData(chartData->shared_from_this());
}

//------------------------------------------------------------------------------
void ChartItem::setXShift(qreal xShift)
{
    if (!qFuzzyCompare(_xShift, xShift)) {
        _xShift = xShift;
        update();
        emit xShiftChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setYShift(qreal yShift)
{
    if (!qFuzzyCompare(_yShift, yShift)) {
        _yShift = yShift;
        update();
        emit yShiftChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setXScale(qreal xScale)
{
    if (!qFuzzyCompare(_xScale, xScale)) {
        _xScale = xScale;
        update();
        emit xScaleChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setYScale(qreal yScale)
{
    if (!qFuzzyCompare(_yScale, yScale)) {
        _yScale = yScale;
        update();
        emit yScaleChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setPointSize(int pointSize)
{
    if (_pointSize != pointSize) {
        _pointSize = pointSize;
        emit pointSizeChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::onAfterSync()
{
}

//------------------------------------------------------------------------------
QNanoQuickItemPainter *ChartItem::createItemPainter() const
{
    // Create painter for this item
    return new ChartItemPainter();
}
