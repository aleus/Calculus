/// @author M. A. Serebrennikov
#include "ChartData.h"
#include "ChartItem.h"
#include "ChartItemPainter.h"

using namespace sp;

void ChartItemPainter::paint(QNanoPainter *p)
{
    qreal dx = 0.2;
    qreal x0 = _xShift;
    qreal y0 = height()/2 + _yShift;

    // Paint the background circle
    p->setStrokeStyle("#202020");
    p->setLineWidth(1);

    auto chartData = _chartData.lock();

    {
        p->beginPath();
        qreal x = x0;
        qreal y = y0;
        p->moveTo(x, y);
        for (auto point: chartData->points()) {
            p->lineTo(x+=dx*_xScale, _yScale*point + y);
        }
        p->stroke();
    }

    if (_pointSize) {
        p->beginPath();
        qreal x = x0;
        qreal y = y0;

        for (auto point: chartData->points()) {
            p->circle(x+=dx*_xScale, _yScale*point + y, _pointSize);
        }
        p->setFillStyle("#fd8c2f");
        p->setStrokeStyle("#fd8c2f");
        p->fill();
        p->stroke();
    }
}

//------------------------------------------------------------------------------
void ChartItemPainter::synchronize(QNanoQuickItem *item)
{
    auto chartItem = dynamic_cast<ChartItem*>(item);

    _chartData = chartItem->chartData();

    _xShift = chartItem->xShift();
    _yShift = chartItem->yShift();
    _xScale = chartItem->xScale();
    _yScale = chartItem->yScale();
    _pointSize = chartItem->pointSize();

    chartItem->onAfterSync();
}
