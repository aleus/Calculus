/// @author M. A. Serebrennikov
#pragma once

#include <memory>
#include <vector>

namespace sp {

class CalcBlock;
class CalcEntity;

using CalcBlockUPtr = std::unique_ptr<CalcBlock>;
using CalcEntityPtr = std::shared_ptr<CalcEntity>;
using CalcEntityWeak = std::weak_ptr<CalcEntity>;

/** Конвеер расчётов. */
using CalcPipeline = std::vector<CalcBlockUPtr>;

} // namespace sp
