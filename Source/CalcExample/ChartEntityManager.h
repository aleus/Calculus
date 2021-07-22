/// @author M. A. Serebrennikov
#pragma once

#include "ChartEntity.h"

#include <QObject>
#include <vector>

namespace sp {

/***************************************************************************//**
 * @brief Класс ChartEntityManager.
 ******************************************************************************/
class ChartEntityManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ChartEntity * top READ topRaw CONSTANT)
    Q_PROPERTY(ChartEntity * middle READ middleRaw CONSTANT)
    Q_PROPERTY(ChartEntity * right READ rightRaw CONSTANT)

    public:
        explicit ChartEntityManager(QObject * parent = nullptr);

        inline ChartEntity * topRaw() const { return _top.get(); }
        inline ChartEntity * middleRaw() const { return _middle.get(); }
        inline ChartEntity * rightRaw() const { return _right.get(); }

    private:
        ChartEntityPtr _top;
        ChartEntityPtr _middle;
        ChartEntityPtr _right;
};

} // namespace sp
