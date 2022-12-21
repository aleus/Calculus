/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcBlock.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс SinCalcBlock заполняет точки ChartEntity функцией синуса.
 * @sa ChartEntity, ChartData
 ******************************************************************************/
class SinCalcBlock : public CalcBlock
{
    public:
        void calc(const std::vector<CalcEntityPtr> & entities) const override;
};

} // namespace sp
