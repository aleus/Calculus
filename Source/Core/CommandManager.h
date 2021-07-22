/// @author M. A. Serebrennikov
#pragma once

#include "CalcEntity.h"
#include "Command.h"
#include "UndoStack.h"

#include <memory>
#include <vector>

namespace sp {

/** Короткое обращение к синглетону CommandManager. */
#define CommandManagerI CommandManager::instance()

/***************************************************************************//**
 * @brief CommandManager кладёт команды в стек отмен, а также отправляет
 * на расчёт в Calc, если команда затронула сущности.

 * @sa Command, UndoStack, Calc
 ******************************************************************************/
class CommandManager
{
    public:
        static CommandManager & instance();

    private:
        CommandManager() = default;

        /** Добавляет команду в стек отмен. Перед добавлением, выполняет redo. */
        void add(CommandUPtr && command);

        /**
         * Добавляет команду в стек отмен. Перед добавлением, выполняет redo
         * и отправляет на расчёт связанные entities.
         */
        void add(CommandUPtr && command, const std::vector<CalcEntityPtr> & entities);

    private:
        UndoStack _undoStack;
};

} // namespace sp
