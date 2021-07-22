/// @author M. A. Serebrennikov
#pragma once

#include "CalcForward.h"

#include <memory>
#include <vector>

namespace sp {

/***************************************************************************//**
 * @brief CalcBlock абстрактный класс проведения расчётов.
 * @sa CalcManager
 ******************************************************************************/
class CalcBlock
{
    public:
        virtual ~CalcBlock() = 0;

        /**
         * @brief Возвращает список сущностей, которые будут затронуты расчётом
         * (кроме переданных в аргументе сущностей).
         *
         * @details Реализация расчётного блока должна самостоятельно
         * найти все рекурсивно затронутые расчётами сущности.
         * По-умолчанию возвращает пустой массив.
         */
        virtual std::vector<CalcEntityPtr> connectedEntities(const std::vector<CalcEntityPtr> & entities) const;

        /** Проводит расчёты над сущностями. */
        virtual void calc(const std::vector<CalcEntityPtr> & entities) const = 0;
};

} // namespace sp
