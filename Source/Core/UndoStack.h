/// @author M. A. Serebrennikov
#pragma once

#include "Command.h"

#include <QObject>
#include <vector>

namespace sp {

#define UndoStackI UndoStack::instance()

/***************************************************************************//**
 * @brief UndoStack хранит стек комманд для отмены.
 ******************************************************************************/
class UndoStack: public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool canUndo READ canUndo NOTIFY canUndoChanged)
    Q_PROPERTY(bool canRedo READ canRedo NOTIFY canRedoChanged)

    public:
        static UndoStack & instance();

        /** Добавляет в конец стека команду. */
        void add(CommandUPtr && command);

        /** Возвращает true, если можно отменить команду. */
        bool canUndo();

        /** Возвращает true, если можно вернуть отменённую комунду. */
        bool canRedo();

        /** Отменяет последнюю команду. */
        Q_INVOKABLE void undo();

        /** Повторяет последнюю отменённую команду. */
        Q_INVOKABLE void redo();

        /** Очищает стек отмен. */
        void clear();

    private:
        UndoStack() = default;
        Q_DISABLE_COPY_MOVE(UndoStack);

    signals:
        void canUndoChanged();
        void canRedoChanged();

    private:
        std::vector<CommandUPtr> _stack;
        int _index = -1;
};

} // namespace sp
