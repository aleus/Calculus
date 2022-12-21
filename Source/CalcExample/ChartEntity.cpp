#include "ChartEntity.h"
#include "Core/UndoStack.h"
#include "Core/CalcCommand.h"
#include "InitCalcBlock.h"
#include "RandCalcBlock.h"
#include "SinCalcBlock.h"

namespace sp {

CalcPipeline ChartEntity::pipeline() const
{
    CalcPipeline result;
    result.emplace_back(new InitCalcBlock);
    result.emplace_back(new SinCalcBlock);
    result.emplace_back(new RandCalcBlock);

    return result;
}

//------------------------------------------------------------------------------
ChartEntity::ChartEntity()
{
    // Debug!!! ChartData должна храниться в другом месте
    _chartData = std::make_shared<ChartData>();
    // Debug!!! Отладочное значение
    _count = 10000;
}

//------------------------------------------------------------------------------
void ChartEntity::setCount(size_t count)
{
    _count = count;
}


//------------------------------------------------------------------------------
void ChartEntity::setHasSin(bool hasSin)
{
    if (_hasSin != hasSin) {
        _hasSin = hasSin;
        emit hasSinChanged();
    }
}

//------------------------------------------------------------------------------
void ChartEntity::setHasSinUser(bool hasSin)
{
    auto lastValue = _hasSin;
    auto command = std::make_unique<CalcCommand>(
              shared_from_this(),
              [=]() { setHasSin(hasSin); },
              [=]() { setHasSin(lastValue); });

    UndoStackI.add(std::move(command));
}

//------------------------------------------------------------------------------
void ChartEntity::setHasRand(bool hasRand)
{
    if (_hasRand != hasRand) {
        _hasRand = hasRand;
        emit hasRandChanged();
    }
}

//------------------------------------------------------------------------------
void ChartEntity::setHasRandUser(bool hasRand)
{
    auto lastValue = _hasRand;
    auto command = std::make_unique<CalcCommand>(
              shared_from_this(),
              [=]() { setHasRand(hasRand); },
              [=]() { setHasRand(lastValue); });

    UndoStackI.add(std::move(command));
}

} // namespace sp
