/// @author M. A. Serebrennikov
#pragma once

#include "ExampleChartEntity.h"

#include <QObject>
#include <vector>

namespace sp {

/***************************************************************************//**
 * @brief Класс ExampleChartManager.
 ******************************************************************************/
class ExampleChartManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ExampleChartEntity * top READ topRaw CONSTANT)
    Q_PROPERTY(ExampleChartEntity * middle READ middleRaw CONSTANT)
    Q_PROPERTY(ExampleChartEntity * right READ rightRaw CONSTANT)

    public:
        ExampleChartManager(QObject * parent = nullptr);

        inline ExampleChartEntity * topRaw() const { return _top.get(); }
        inline ExampleChartEntity * middleRaw() const { return _middle.get(); }
        inline ExampleChartEntity * rightRaw() const { return _right.get(); }

    private:
        ExampleChartEntityPtr _top;
        ExampleChartEntityPtr _middle;
        ExampleChartEntityPtr _right;
};

} // namespace sp
