/// @author M. A. Serebrennikov
#include "CalcExample/ChartEntityManager.h"
#include "Chart/ChartItem.h"
#include "Core/UndoStack.h"
#include "Core/Platform.h"

#include <WindowFramelessHelper.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace sp;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<WindowFramelessHelper>("QtShark.Window", 1, 0, "FramelessHelper");

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

    auto * exampleChartManager = new ChartEntityManager(&engine);

    context->setContextProperty("dp", Platform::dp());
    context->setContextProperty("ExampleChartManager", exampleChartManager);
    context->setContextProperty("UndoStack", &UndoStackI);

    qmlRegisterType<ChartItem>("Rogii", 1, 0, "ChartItem");

    engine.addImportPath("qrc:///");
    engine.load(QStringLiteral("qrc:/Root.qml"));

    app.exec();
    return 0;
}
