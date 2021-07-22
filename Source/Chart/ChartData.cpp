#include "ChartData.h"

using namespace sp;

//------------------------------------------------------------------------------
void ChartData::setPoints(std::valarray<double> && points)
{
    _points = std::move(points);
    emit updated();
}

//------------------------------------------------------------------------------
void ChartData::setPoints(const std::valarray<double> & points)
{
    _points = points;
    emit updated();
}
