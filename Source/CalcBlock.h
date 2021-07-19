/// @author M. A. Serebrennikov
#pragma once

#include "CalcEntity.h"

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

        virtual void calc(const std::vector<CalcEntityPtr> & entities) const = 0;
};

using CalcBlockUPtr = std::unique_ptr<CalcBlock>;

} // namespace sp
