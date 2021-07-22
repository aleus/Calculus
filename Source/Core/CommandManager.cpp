#include "Calc.h"
#include "CommandManager.h"

namespace sp {

CommandManager & CommandManager::instance()
{
    static CommandManager result;
    return result;
}

//------------------------------------------------------------------------------
void CommandManager::add(CommandUPtr && command)
{
    command->redo();
    _undoStack.add(std::move(command));
}

//------------------------------------------------------------------------------
void CommandManager::add(CommandUPtr && command, const std::vector<CalcEntityPtr> & entities)
{
    command->redo();

    if (CalcI.calc(entities)) {
        _undoStack.add(std::move(command));
    } else {
        command->undo();
    }
}

} // namespace sp
