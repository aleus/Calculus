/// @author M. A. Serebrennikov
#pragma once

#include "CalcForward.h"
#include "Command.h"

#include <functional>

namespace sp {

/***************************************************************************//**
 * @brief Класс CalcCommand представляет комманду, где redo и undo
 * задаются лямбда-функциями. В отличии от FunctionalCommand после выполнения
 * вызова функций redo и undo отправляет связанные сущности на расчёт Calc.
 *
 * @example
 * auto lastValue = object->value();
 * auto command = std::make_unique<CalcCommand>(
 *            [=]() { setValue(newValue); },
 *            [=]() { setValue(lastValue); });
 ******************************************************************************/
class CalcCommand : public Command
{
    public:
        CalcCommand(const std::vector<CalcEntityPtr> & entities,
                    const std::function<void()> &redoFunction,
                    const std::function<void()> &undoFunction);
        CalcCommand(const CalcEntityPtr & entity,
                    const std::function<void()> &redoFunction,
                    const std::function<void()> &undoFunction);

        bool redo() override;
        void undo() override;

    private:
        std::vector<CalcEntityPtr> _entities;
        std::function<void()> _redoFunction;
        std::function<void()> _undoFunction;
};

} // namespace sp
