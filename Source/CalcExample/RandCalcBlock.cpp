#include "ExampleChartEntity.h"
#include "RandCalcBlock.h"

#include <QtGlobal>
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
    const double amplitude = 50;

    for (auto & entity: entities) {
        auto chartEntity = std::dynamic_pointer_cast<ExampleChartEntity>(entity);
        Q_ASSERT_X(chartEntity, "RandCalcBlock", "Entity isn't a ExampleChartEntity");

        if (chartEntity && chartEntity->hasRand()) {
            auto points = chartEntity->points();

            for (size_t i = 0, count = points.size(); i<count; ++i) {
                points[i] += amplitude*getRandom();
            }

            chartEntity->setPoints(std::move(points));
        }
    }
}

} // namespace sp
