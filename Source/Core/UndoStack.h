/// @author M. A. Serebrennikov
#pragma once

#include "Command.h"

#include <QObject>
#include <vector>

namespace sp {

#define UndoStackI UndoStackI::instance();

/***************************************************************************//**
 * @brief UndoStack хранит стек комманд для отмены.
 ******************************************************************************/
class UndoStack: public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool canUndo READ canUndo NOTIFY canUndoChanged)
    Q_PROPERTY(bool canRedo READ canRedo NOTIFY canRedoChanged)

    public:
        /** Добавляет в конец стека команду. */
        void add(CommandPtr && command);

        /** Возвращает true, если можно отменить команду. */
        bool canUndo();

        /** Возвращает true, если можно вернуть отменённую комунду. */
        bool canRedo();

        /** Отменяет последнюю команду. */
        void undo();

        /** Повторяет последнюю отменённую команду. */
        void redo();

        /** Очищает стек отмен. */
        void clear();

    signals:
        void canUndoChanged();
        void canRedoChanged();

    private:
        std::vector<CommandPtr> _stack;
        int _index = -1;
};

} // namespace sp
