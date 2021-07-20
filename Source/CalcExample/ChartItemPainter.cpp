/// @author M. A. Serebrennikov
#include "ChartData.h"
#include "ChartItem.h"
#include "ChartItemPainter.h"

#include <QDebug>

using namespace sp;

void ChartItemPainter::paint(QNanoPainter *p)
{
    qreal dx = !_rotate ? 0.2 : 0.0;
    qreal dy = !_rotate ? 0.0 : 0.2;
    qreal x0 = !_rotate ? _xShift              : width()/2 + _xShift;
    qreal y0 = !_rotate ? height()/2 + _yShift : _yShift;

    // Paint the background circle
    p->setStrokeStyle("#202020");
    p->setLineWidth(1);

    {
        p->beginPath();
        qreal x = x0;
        qreal y = y0;
        p->moveTo(x, y);
        for (auto point: _points) {
            if (!_rotate) {
                p->lineTo(x+=dx*_xScale, _yScale*point + y);
            } else {
                p->lineTo(_xScale*point + x, y+=dy*_yScale);
            }
        }
        p->stroke();
    }

    if (_pointSize) {
        p->beginPath();
        qreal x = x0;
        qreal y = y0;

        for (auto point: _points) {
            if (!_rotate) {
                p->circle(x+=dx*_xScale, _yScale*point + y, _pointSize);
            } else {
                p->circle(_xScale*point + x, y+=dy*_yScale, _pointSize);
            }
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
    Q_ASSUME(chartItem);

    if (chartItem->dirtyFlag()) {
        _points = chartItem->chartData()->points();
    }

    _xShift = chartItem->xShift();
    _yShift = chartItem->yShift();
    _xScale = chartItem->xScale();
    _yScale = chartItem->yScale();
    _pointSize = chartItem->pointSize();
    _rotate = chartItem->rotate();

    chartItem->onAfterSync();
}
