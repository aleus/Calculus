#include "RandCalcBlock.h"
#include "ChartData.h"

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

void RandCalcBlock::calc(const std::vector<CalcEntityPtr> & entities) const
{
    const double amplitude = 50;

    for (auto & entity: entities) {
        auto chartData = std::dynamic_pointer_cast<ChartData>(entity);
        if (chartData) {
            auto points = chartData->points();

            for (size_t i = 0, count = points.size(); i<count; ++i) {
                points[i] += amplitude*getRandom();
            }

            chartData->setPoints(std::move(points));
        } else {
            Q_ASSERT_X(false, "RandCalcBlock", "Entity isn't a ChartData");
        }
    }
}

} // namespace sp
