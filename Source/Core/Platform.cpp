/// @author M.Serebrennikov
#include "Platform.h"

#include <QGuiApplication>
#include <QScreen>

using namespace sp;

Platform &Platform::instance()
{
    static Platform result;
    return result;
}

//------------------------------------------------------------------------------
qreal Platform::dp()
{
    static const double dp = qApp->screens().first()->devicePixelRatio();

    #if defined(Q_OS_MAC)
        static double const standardDPI = 72;
    #elif defined(Q_OS_WIN)
        static double const standardDPI = 96;
    #else
        static double const standardDPI = qApp->screens().first()->logicalDotsPerInch();
    #endif

    static const double dpi = qApp->screens().first()->logicalDotsPerInch() / standardDPI;
    return dp*dpi;
}
