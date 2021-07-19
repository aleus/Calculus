#include "Calc.h"

#include <algorithm>
#include <functional>
#include <stdexcept>

namespace sp {

//------------------------------------------------------------------------------
Calc & Calc::instance()
{
    static Calc result;
    return result;
}

//------------------------------------------------------------------------------
bool Calc::calc(const std::vector<CalcEntityPtr> & entities)
{
    // Находим все затронутые изменениями и расчётами сущности
    auto initialPipelines = distribute(entities);
    std::vector<CalcEntityPtr> totalEntities(entities);

    for (const auto & [pipeline, entities]: initialPipelines) {
        for (const auto & calcBlock: *pipeline) {
            auto buf = calcBlock->connectedEntities(entities);
            std::move(buf.begin(), buf.end(), std::back_inserter(totalEntities));
        }
    }

    // Расчитываем
    auto totalPipelines = distribute(totalEntities);

    for (const auto & [pipeline, entities]: totalPipelines) {
        for (const auto & calcBlock: *pipeline) {
            calcBlock->calc(entities);
        }
    }

    // TODO Добавить в pipeline проверку на корректность расчётов
    return true;
}

//------------------------------------------------------------------------------
Calc::PipelineHash Calc::distribute(const std::vector<CalcEntityPtr> & entities)
{
    Calc::PipelineHash result;

    for (const auto & entity: entities) {
        try {
            const Pipeline & pipeline = _pipelines.at(&typeid(entity));
            result[&pipeline].push_back(entity);
        } catch (const std::out_of_range &) {
            Q_ASSERT_X(false, "Calc", "Need to add new entity type to calc pipeline.");
            continue;
        }
    }

    return result;
}

} // namespace sp
