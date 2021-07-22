/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcBlock.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс InitCalcBlock инициализирует ChartEntity.
 * @sa ChartEntity, ChartData
 ******************************************************************************/
class InitCalcBlock : public CalcBlock
{
    public:
        void calc(const std::vector<CalcEntityPtr> & entities) const override;
};

} // namespace sp
