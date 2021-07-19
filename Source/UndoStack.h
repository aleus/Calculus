/// @author M. A. Serebrennikov
#pragma once

#ifndef UNDOSTACK_H
#define UNDOSTACK_H

#include "Command.h"

#include <QObject>
#include <vector>

namespace sp {

#define UndoStackI UndoStackI::instance();

/***************************************************************************//**
 * @brief CommandManager хранит стек комманд. Позволяет отменить и восстановить комманду
 ******************************************************************************/
class UndoStack: public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool canUndo READ canUndo NOTIFY canUndoChanged)
    Q_PROPERTY(bool canRedo READ canRedo NOTIFY canRedoChanged)

    public:
        UndoStack() = default;

        /** Добавляет в конец стека команду. */
        template<class T>
        void pushBack(T && command);

        /** Отменяет последнюю команду. */
        void undo();

        /** Повторяет последнюю отменённую команду. */
        void redo();

        /** Возвращает true, если можно отменить команду. */
        bool canUndo();

        /** Возвращает true, если можно вернуть отменённую комунду. */
        bool canRedo();

    signals:
        void canUndoChanged();
        void canRedoChanged();

    private:
        std::vector<CommandPtr> _stack;
        size_t _index = 0;
};

} // namespace sp

#include "UndoStack.hpp"

#endif
