/// @author M. A. Serebrennikov
#pragma once

#include <memory>

namespace sp {

/***************************************************************************//**
 * @brief CalcEntity абстрактный класс, над которым проводятся расчёты в CalcManager.
 * @sa CalcBlock, CalcManager
 ******************************************************************************/
class CalcEntity
{
    public:
        virtual ~CalcEntity() = 0;
};

using CalcEntityPtr = std::shared_ptr<CalcEntity>;
using CalcEntityWeak = std::weak_ptr<CalcEntity>;

} // namespace sp
