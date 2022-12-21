#include "ChartEntityManager.h"
#include "Core/Calc.h"

namespace sp {

ChartEntityManager::ChartEntityManager(QObject * parent/* = nullptr*/)
    : QObject(parent)
    , _top(std::make_shared<ChartEntity>())
    , _middle(std::make_shared<ChartEntity>())
    , _right(std::make_shared<ChartEntity>())
{
    // Здесь приведён пример расчёта через механизм Calc
    const size_t debugCount = 10000;

    _top->hasSin(true)
        ->count(debugCount);

    _middle->hasSin(true)
           ->hasRand(true)
           ->count(debugCount);

    _right->hasRand(true)
          ->count(debugCount);

    CalcI.calc({_top, _middle, _right});
}

} // namespace sp
