#include "FunctionalCommand.h"

namespace sp {

FunctionalCommand::FunctionalCommand(const std::function<void ()> & redoFunction, const std::function<void ()> & undoFunction)
    : _redoFunction(redoFunction)
    , _undoFunction(undoFunction)
{
}

//------------------------------------------------------------------------------
bool FunctionalCommand::redo()
{
    _redoFunction();
    return true;
}

//------------------------------------------------------------------------------
void FunctionalCommand::undo()
{
    _undoFunction();
}

} // namespace sp
