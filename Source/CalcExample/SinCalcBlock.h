/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcBlock.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс SinCalcBlock заполняет точки ChartData функцией синуса.
 ******************************************************************************/
class SinCalcBlock : public CalcBlock
{
    public:
        void calc(const std::vector<CalcEntityPtr> & entities) const override;
};

} // namespace sp
