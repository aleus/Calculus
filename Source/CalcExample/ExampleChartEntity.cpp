#include "ExampleChartEntity.h"
#include "SinCalcBlock.h"
#include "RandCalcBlock.h"

namespace sp {

CalcPipeline ExampleChartEntity::pipeline() const
{
    CalcPipeline result;
    result.emplace_back(new SinCalcBlock);
    result.emplace_back(new RandCalcBlock);

    return result;
}

//------------------------------------------------------------------------------
void ExampleChartEntity::setHasSin(bool hasSin)
{
    _hasSin = hasSin;
}

//------------------------------------------------------------------------------
void ExampleChartEntity::setHasRand(bool hasRand)
{
    _hasRand = hasRand;
}

} // namespace sp
