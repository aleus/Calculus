/// @author M. A. Serebrennikov
#pragma once

#include "CalcEntity.h"
#include "Command.h"

#include <memory>
#include <vector>

namespace sp {

class CalcManager;

/***************************************************************************//**
 * @brief CommandManager class.
 ******************************************************************************/
class CommandManager
{
    public:
        static CommandManager & instance();

    private:
        CommandManager();

        void add(CommandPtr && command);
        void add(CommandPtr && command, const std::vector<CalcEntityPtr> & entities);

    private:
        std::unique_ptr<CalcManager> _calc;
};

} // namespace sp
