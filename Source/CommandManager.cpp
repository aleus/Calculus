#include "CalcManager.h"
#include "CommandManager.h"

namespace sp {

CommandManager & CommandManager::instance()
{
    static CommandManager result;
    return result;
}

//------------------------------------------------------------------------------
CommandManager::CommandManager()
    : _calc(std::make_unique<CalcManager>())
{

}

} // namespace sp
