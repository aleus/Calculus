/// @author M. A. Serebrennikov
#pragma once

#include <vector>

namespace sp {

/***************************************************************************//**
 * @brief Body class.
 ******************************************************************************/
class Body
{
    public:
        Body();

    private:
        std::vector<double> _measurements;

};

} // namespace sp
