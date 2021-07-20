#include "ChartData.h"
#include "SinCalcBlock.h"

#include <QtGlobal>
#include <cmath>

namespace sp {

void SinCalcBlock::calc(const std::vector<CalcEntityPtr> & entities) const
{
    const double amplitude = 50;
    const double k = 0.03;

    for (auto & entity: entities) {
        auto chartData = std::dynamic_pointer_cast<ChartData>(entity);
        if (chartData) {
            auto points = chartData->points();

            for (size_t i = 0, count = points.size(); i<count; ++i) {
                points[i] = amplitude*sin(i*k);
            }

            chartData->setPoints(std::move(points));
        } else {
            Q_ASSERT_X(false, "SinCalcBlock", "Entity isn't a ChartData");
        }
    }
}

} // namespace sp
