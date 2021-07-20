/// @author M.Serebrennikov
#pragma once

#include <QtGlobal>

namespace sp {

/***************************************************************************//**
 *  @brief Платформенно-зависимый код общего характера.
 ******************************************************************************/
class Platform {
    public:
        static Platform& instance();

        static qreal dp();

    private:
        Platform() = default;
        Platform(Platform &) = delete;
        Platform(Platform &&) = delete;
};

} // namespace sp {
