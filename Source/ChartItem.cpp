/// @author M. A. Serebrennikov
#include "ChartItem.h"
#include "ChartItemPainter.h"

#include <QDebug>

using namespace sp;

//------------------------------------------------------------------------------
ChartItem::ChartItem(QQuickItem *parent)
    :  QNanoQuickItem(parent)
{
    connect(this, &ChartItem::pointSizeChanged, this, &ChartItem::update);
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
    qDebug() << "Debug!!! pointSize" << pointSize;
    if (_pointSize != pointSize) {
        _pointSize = pointSize;
        emit pointSizeChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setRotate(bool rotate)
{
    if (_rotate != rotate) {
        _rotate = rotate;
        update();
        emit rotateChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::setWellPoints(bool wellPoints)
{
    if (_wellPoints != wellPoints) {
        _wellPoints = wellPoints;
        if (_wellPoints) {
            _chartData.makeWellPoints();
            _dirtyFlag = true;
        }
        update();
        emit wellPointsChanged();
    }
}

//------------------------------------------------------------------------------
void ChartItem::onAfterSync()
{
    _dirtyFlag = false;
}

//------------------------------------------------------------------------------
QNanoQuickItemPainter *ChartItem::createItemPainter() const
{
    // Create painter for this item
    return new ChartItemPainter();
}
