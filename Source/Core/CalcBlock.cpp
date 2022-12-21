#include "CalcBlock.h"

namespace sp {

CalcBlock::~CalcBlock()
{
}

//------------------------------------------------------------------------------
std::vector<CalcEntityPtr> CalcBlock::connectedEntities(const std::vector<CalcEntityPtr> &/* entities */) const
{
    return {};
}

} // namespace sp
