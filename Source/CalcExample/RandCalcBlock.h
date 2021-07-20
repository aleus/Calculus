/// @author M. A. Serebrennikov
#pragma once

#include "Core/CalcBlock.h"

namespace sp {

/***************************************************************************//**
 * @brief Класс RandCalcBlock добавляет к точками ChardData случайное смещение.
 ******************************************************************************/
class RandCalcBlock : public CalcBlock
{
    public:
        void calc(const std::vector<CalcEntityPtr> & entities) const override;
};

} // namespace sp
