#include "ChartData.h"
#include <cmath>
#include <random>
#include <QDebug>

using namespace sp;

float getRandom()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(-0.2, 0.2); // rage 0 - 1
    return dis(e);
}

//------------------------------------------------------------------------------
ChartData::ChartData()
{
    // Debug!!! Set outside
    const int count = 10000;
    const qreal amplitude = 50;
    const qreal k = 30./count;
    _points.resize(count);

    for (size_t i=0, count=_points.size(); i<count; ++i) {
        _points[i] = amplitude*sin(i*k + getRandom());
    }
}

//------------------------------------------------------------------------------
ChartData::ChartData(const ChartData &rhs)
    : _points(rhs._points)
{

}

//------------------------------------------------------------------------------
ChartData &ChartData::operator =(ChartData chartData)
{
    // Debug!!!
    _points = chartData._points;
    return *this;
}

//------------------------------------------------------------------------------
void ChartData::makeWellPoints()
{
    qDebug() << "Debug!! makeWellPoints";
    // Debug!!! Set outside
    const qreal amplitude = 50;
    qreal y0 = 0;
    const qreal k = 0.5;

    for (size_t i=0, count=_points.size(); i<count; ++i) {
        _points[i] = i*k + y0 + amplitude*getRandom();
    }
}
