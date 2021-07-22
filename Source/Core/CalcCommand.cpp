#include "Calc.h"
#include "CalcCommand.h"

namespace sp {

CalcCommand::CalcCommand(const std::vector<CalcEntityPtr> & entities, const std::function<void ()> & redoFunction, const std::function<void ()> & undoFunction)
    : _entities(entities)
    , _redoFunction(redoFunction)
    , _undoFunction(undoFunction)
{

}

//------------------------------------------------------------------------------
CalcCommand::CalcCommand(const CalcEntityPtr & entity, const std::function<void ()> & redoFunction, const std::function<void ()> & undoFunction)
    : _entities({entity})
    , _redoFunction(redoFunction)
    , _undoFunction(undoFunction)
{

}

//------------------------------------------------------------------------------
bool CalcCommand::redo()
{
    _redoFunction();
    return CalcI.calc(_entities);
}

//------------------------------------------------------------------------------
void CalcCommand::undo()
{
    _undoFunction();
    CalcI.calc(_entities);
}

} // namespace sp
