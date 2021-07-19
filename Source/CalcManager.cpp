#include "CalcManager.h"

#include <functional>
#include <stdexcept>

namespace sp {

//------------------------------------------------------------------------------
void CalcManager::calc(const std::vector<CalcEntityPtr> & entities)
{
    auto pipelineVector = distribute(entities);

    for (const auto & [pipeline, entities]: pipelineVector) {
        for (const auto & calcBlock: *pipeline) {
            calcBlock->calc(entities);
        }
    }
}

//------------------------------------------------------------------------------
CalcManager::PipelineHash CalcManager::distribute(const std::vector<CalcEntityPtr> & entities)
{
    CalcManager::PipelineHash result;

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
