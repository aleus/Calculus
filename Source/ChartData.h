/// @author M. A. Serebrennikov
#pragma once

#include <QObject>
#include <valarray>

namespace sp {

class ChartData : public QObject
{
    Q_OBJECT

    public:
        ChartData();
        ChartData(const ChartData &);

        ChartData& operator = (ChartData);

        //----------------------------------------------------------------------
        // GET
        //----------------------------------------------------------------------
        inline auto count() const { return _points.size(); }
        inline const auto & points() const { return _points; }

        //----------------------------------------------------------------------
        // SPECIAL
        //----------------------------------------------------------------------
        void makeWellPoints();

    private:
        std::valarray<qreal> _points;

        const size_t _count = 100;
};

} // namespace sp {
