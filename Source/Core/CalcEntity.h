/// @author M. A. Serebrennikov
#pragma once

#include "CalcForward.h"

namespace sp {

/***************************************************************************//**
 * @brief CalcEntity абстрактный класс, над которым проводятся расчёты в CalcManager.
 * @sa CalcBlock, CalcManager
 ******************************************************************************/
class CalcEntity : public std::enable_shared_from_this<CalcEntity>
{
    public:
        virtual ~CalcEntity() = 0;

        /** Возвращает цепочку расчётных блоков для этого типа сущности. */
        virtual CalcPipeline pipeline() const = 0;
};

} // namespace sp
