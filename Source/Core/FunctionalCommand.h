/// @author M. A. Serebrennikov
#pragma once

#include "Command.h"
#include <functional>

namespace sp {

/***************************************************************************//**
 * @brief Класс FunctionalCommand представляет комманду, где redo и undo
 * задаются лямбда-функциями.
 *
 * @example
 * auto lastValue = object->value();
 * auto command = std::make_unique<FunctionalCommand>(
 *            [=]() { setValue(newValue); },
 *            [=]() { setValue(lastValue); });
 ******************************************************************************/
class FunctionalCommand : public Command
{
    public:
        FunctionalCommand(const std::function<void()> &redoFunction,
                          const std::function<void()> &undoFunction);
        bool redo() override;
        void undo() override;

    private:
        std::function<void()> _redoFunction;
        std::function<void()> _undoFunction;
};

} // namespace sp
