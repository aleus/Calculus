#include "ChartData.h"
#include "SinCalcBlock.h"
#include "RandCalcBlock.h"

using namespace sp;

//------------------------------------------------------------------------------
void ChartData::setCount(size_t count)
{
    _points.resize(count);
}

//------------------------------------------------------------------------------
void ChartData::setPoints(std::valarray<double> && points)
{
    _points = std::move(points);
}

//------------------------------------------------------------------------------
void ChartData::setPoints(const std::valarray<double> & points)
{
    _points = points;
}

//------------------------------------------------------------------------------
CalcPipeline ChartData::pipeline() const
{
    CalcPipeline result;
    result.emplace_back(new SinCalcBlock);
    result.emplace_back(new RandCalcBlock);

    return result;
}
