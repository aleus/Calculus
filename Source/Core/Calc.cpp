#include "Calc.h"
#include "CalcBlock.h"
#include "CalcEntity.h"

#include <algorithm>
#include <functional>

namespace sp {

//------------------------------------------------------------------------------
Calc & Calc::instance()
{
    static Calc result;
    return result;
}

//------------------------------------------------------------------------------
void Calc::regPipeline(const CalcEntityPtr & entity)
{
    Q_ASSERT(entity);

    const auto & entityRaw = *entity.get();
    auto * entityType = &typeid(entityRaw);

    regPipeline(entityType, entity->pipeline());
}

//------------------------------------------------------------------------------
void Calc::regPipeline(const std::type_info * entityType, CalcPipeline && pipeline)
{
    Q_ASSERT(!_pipelines.count(entityType));

    _pipelines[entityType] = std::move(pipeline);
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
        const auto & entityRaw = *entity.get();
        auto * entityType = &typeid(entityRaw);

        const auto pipelineItr = _pipelines.find(entityType);
        if (pipelineItr != _pipelines.end()) {
            result[&pipelineItr->second].push_back(entity);
        } else {
            regPipeline(entityType, entity->pipeline());
            const auto * pipeline = &_pipelines[entityType];
            result[pipeline].push_back(entity);
        }
    }

    return result;
}

} // namespace sp
