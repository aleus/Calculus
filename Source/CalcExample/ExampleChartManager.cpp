#include "ExampleChartManager.h"
#include "Core/Calc.h"

namespace sp {

ExampleChartManager::ExampleChartManager(QObject * parent/* = nullptr*/)
    : QObject(parent)
    , _top(std::make_shared<ExampleChartEntity>())
    , _middle(std::make_shared<ExampleChartEntity>())
    , _right(std::make_shared<ExampleChartEntity>())
{
    // Здесь приведён пример расчёта через механизм Calc
    const size_t debugCount = 10000;

    _top->hasSin(true)
        ->count(debugCount);
    _middle->hasSin(true)
           ->hasRand(true)
           ->setCount(debugCount);
    _right->hasRand(true)
          ->setCount(debugCount);

    CalcI.calc({_top, _middle, _right});
}

} // namespace sp
