/// @author M. A. Serebrennikov
#pragma once

#include "CalcForward.h"

namespace sp {

/***************************************************************************//**
 * @brief CalcEntity абстрактный класс, над которым проводятся расчёты в CalcManager.
 * @sa CalcBlock, CalcManager
 ******************************************************************************/
class CalcEntity
{
    public:
        virtual ~CalcEntity() = default;

        /** Возвращает цепочку расчётных блоков для этого типа сущности. */
        virtual CalcPipeline pipeline() const = 0;
};

} // namespace sp
