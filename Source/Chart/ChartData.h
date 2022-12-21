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
        void setPoints(std::valarray<double> && points);
        void setPoints(const std::valarray<double> & points);

    signals:
        void updated();

    private:
        std::valarray<double> _points;
};

using ChartDataPtr = std::shared_ptr<ChartData>;
using ChartDataWeak = std::weak_ptr<ChartData>;

} // namespace sp {

