#include "ExampleChartEntity.h"
#include "SinCalcBlock.h"

#include <QtGlobal>
#include <cmath>

namespace sp {

void SinCalcBlock::calc(const std::vector<CalcEntityPtr> & entities) const
{
    const double amplitude = 50;
    const double k = 0.03;

    for (auto & entity: entities) {
        auto chartEntity = std::dynamic_pointer_cast<ExampleChartEntity>(entity);
        Q_ASSERT_X(chartEntity, "SinCalcBlock", "Entity isn't a ExampleChartEntity");

        if (chartEntity && chartEntity->hasSin()) {
            auto points = chartEntity->points();

            for (size_t i = 0, count = points.size(); i<count; ++i) {
                points[i] = amplitude*sin(i*k);
            }

            chartEntity->setPoints(std::move(points));
        }
    }
}

} // namespace sp
