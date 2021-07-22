/// @author M. A. Serebrennikov
#pragma once

#include "ChartData.h"

#include <qnanoquickitempainter.h>
#include <memory>
#include <valarray>

namespace sp {

class ChartItem;

class ChartItemPainter : public QNanoQuickItemPainter
{
    public:
        ChartItemPainter() = default;

        void paint(QNanoPainter *p) override;

    protected:
        void synchronize(QNanoQuickItem *item) override;

    private:
        ChartDataWeak _chartData;
        qreal _xShift = 0.0;
        qreal _yShift = 0.0;
        qreal _xScale = 1.0;
        qreal _yScale = 1.0;
        int _pointSize = 0.0;
        bool _dirtyFlag = true;
};

} // namespace sp {
