#include "ChartEntity.h"
#include "RandCalcBlock.h"

#include <random>

namespace sp {

namespace  {
float getRandom()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(-0.2, 0.2); // rage 0 - 1
    return dis(e);
}
} // namespace

//------------------------------------------------------------------------------
void RandCalcBlock::calc(const std::vector<CalcEntityPtr> & entities) const
{
    const double amplitude = 50; // Debug!!! Отладочное значение

    for (auto & entity: entities) {
        auto chartEntity = std::dynamic_pointer_cast<ChartEntity>(entity);
        Q_ASSERT_X(chartEntity, "RandCalcBlock", "Entity isn't a ChartEntity");

        if (chartEntity && chartEntity->hasRand()) {
            auto points = chartEntity->chartData()->points();

            for (size_t i = 0, count = points.size(); i<count; ++i) {
                points[i] += amplitude*getRandom();
            }

            chartEntity->chartData()->setPoints(std::move(points));
        }
    }
}

} // namespace sp
