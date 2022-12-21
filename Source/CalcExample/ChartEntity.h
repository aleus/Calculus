/// @author M. A. Serebrennikov
#pragma once

#include "Chart/ChartData.h"
#include "Core/CalcEntity.h"

#include <QObject>

namespace sp {

/***************************************************************************//**
 * @brief Класс ChartEntity - пример сущности построения графика.
 ******************************************************************************/
class ChartEntity : public QObject, public CalcEntity
{
    Q_OBJECT

    Q_PROPERTY(ChartData * chartData READ chartDataRaw CONSTANT)
    Q_PROPERTY(bool hasSin READ hasSin WRITE setHasSinUser NOTIFY hasSinChanged)
    Q_PROPERTY(bool hasRand READ hasRand WRITE setHasRandUser NOTIFY hasRandChanged)

    public:
        ChartEntity();

        //----------------------------------------------------------------------
        // GET
        //----------------------------------------------------------------------
        inline const ChartDataPtr & chartData() const { return _chartData; }
        inline ChartData * chartDataRaw() const { return _chartData.get(); }

        inline auto count() const { return _count; }
        inline bool hasSin() const { return _hasSin; }
        inline bool hasRand() const { return _hasRand; }

        //----------------------------------------------------------------------
        // SET
        //----------------------------------------------------------------------
        void setCount(size_t count);
        inline ChartEntity *count(size_t count) { setCount(count); return this; }

        void setHasSin(bool hasSin);
        inline ChartEntity * hasSin(bool hasSin) { setHasSin(hasSin); return this; }
        void setHasSinUser(bool hasSin);

        void setHasRand(bool hasRand);
        inline ChartEntity * hasRand(bool hasRand) { setHasRand(hasRand); return this; }
        void setHasRandUser(bool hasRand);

        //----------------------------------------------------------------------
        // OVERRIDE
        //----------------------------------------------------------------------
        CalcPipeline pipeline() const override;

    signals:
        void hasSinChanged();
        void hasRandChanged();

    private:
        ChartDataPtr _chartData;
        size_t _count = 0;
        bool _hasSin = false;
        bool _hasRand = false;
};

using ChartEntityPtr = std::shared_ptr<ChartEntity>;
using ChartEntityWeak = std::weak_ptr<ChartEntity>;

} // namespace sp
