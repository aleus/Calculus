/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcEntity.h"
#include <valarray>

namespace sp {

class ChartData : public CalcEntity
{
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

        void setPoints(std::valarray<double> && points);
        void setPoints(const std::valarray<double> & points);

        //----------------------------------------------------------------------
        // OVERRIDE
        //----------------------------------------------------------------------
        CalcPipeline pipeline() const override;

    private:
        std::valarray<double> _points;
};

} // namespace sp {
