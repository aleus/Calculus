/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcBlock.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс RandCalcBlock добавляет к точками ChartEntity случайное смещение.
 * @sa ChartEntity, ChartData
 ******************************************************************************/
class RandCalcBlock : public CalcBlock
{
    public:
        void calc(const std::vector<CalcEntityPtr> & entities) const override;
};

} // namespace sp
