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

        virtual void undo() = 0;
        virtual void redo() = 0;

    private:
        Q_DISABLE_COPY_MOVE(Command)
};

using CommandPtr = std::shared_ptr<Command>;
using CommandWeak = std::weak_ptr<Command>;

} // namespace sp
