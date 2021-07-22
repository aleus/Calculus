/// @author M. A. Serebrennikov
#pragma once

#include <QObject>
#include <memory>
#include <valarray>

namespace sp {

class ChartData : public QObject, public std::enable_shared_from_this<ChartData>
{
    Q_OBJECT

    public:
        //----------------------------------------------------------------------
        // GET
        //----------------------------------------------------------------------
        inline auto count() const { return _points.size(); }
        inline const auto & points() const { return _points; }

        //----------------------------------------------------------------------
        // SET
        //----------------------------------------------------------------------
        void setCount(size_t count);
        inline ChartData * count(size_t count) { setCount(count); return this; };

        void setPoints(std::valarray<double> && points);
        void setPoints(const std::valarray<double> & points);

    private:
        std::valarray<double> _points;
};

using ChartDataPtr = std::shared_ptr<ChartData>;

} // namespace sp {

