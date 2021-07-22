/// @author M. A. Serebrennikov
#pragma once

#include "Chart/ChartData.h"
#include "Core/CalcEntity.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс ExampleChartEntity - пример сущности построения графика.
 ******************************************************************************/
class ExampleChartEntity : public ChartData, public CalcEntity
{
    Q_OBJECT

    public:
        CalcPipeline pipeline() const override;

        //----------------------------------------------------------------------
        // GET
        //----------------------------------------------------------------------
        inline bool hasSin() const { return _hasSin; }
        inline bool hasRand() const { return _hasRand; }

        //----------------------------------------------------------------------
        // SET
        //----------------------------------------------------------------------
        void setHasSin(bool hasSin);
        inline ExampleChartEntity * hasSin(bool hasSin) { setHasSin(hasSin); return this; }

        void setHasRand(bool hasRand);
        inline ExampleChartEntity * hasRand(bool hasRand) { setHasRand(hasRand); return this; }

    private:
        bool _hasSin = false;
        bool _hasRand = false;
};

using ExampleChartEntityPtr = std::shared_ptr<ExampleChartEntity>;
using ExampleChartEntityWeak = std::weak_ptr<ExampleChartEntity>;

} // namespace sp
