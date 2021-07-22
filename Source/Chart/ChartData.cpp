#include "ChartData.h"

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
