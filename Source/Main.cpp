/// @author M. A. Serebrennikov
#include "Platform.h"
#include "ChartItem.h"

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
    engine.addImportPath("qrc:///");

    context->setContextProperty("dp", Platform::dp());
    qmlRegisterType<ChartItem>("Rogii", 1, 0, "ChartItem");

    const QUrl url(QStringLiteral("qrc:/Root.qml"));
    engine.load(url);

    return app.exec();
}
