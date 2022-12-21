/// @author M. A. Serebrennikov
#pragma once

#include <QtGlobal>
#include <memory>

namespace sp {

/***************************************************************************//**
 * @brief Command производит изменение чего-либо, либо отменяет. Хранится в стеке
 * CommandManager.
 ******************************************************************************/
class Command
{
    public:
        Command() = default;
        virtual ~Command() = 0;

        /** Проводит действие. Если действие провести невозможно, возвращает false. */
        virtual bool redo() = 0;
        virtual void undo() = 0;

    private:
        Q_DISABLE_COPY_MOVE(Command)
};

using CommandUPtr = std::unique_ptr<Command>;

} // namespace sp
