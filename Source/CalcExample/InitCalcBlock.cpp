#include "ChartEntity.h"
#include "InitCalcBlock.h"

namespace sp {

void InitCalcBlock::calc(const std::vector<CalcEntityPtr> & entities) const
{
    for (auto & entity: entities) {
        auto chartEntity = std::dynamic_pointer_cast<ChartEntity>(entity);
        Q_ASSERT_X(chartEntity, "InitCalcBlock", "Entity isn't a ChartEntity");

        if (chartEntity) {
            size_t count = chartEntity->count();
            chartEntity->chartData()->setPoints(std::valarray<double>(0., count));
        }
    }
}

} // namespace sp
