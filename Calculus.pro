QT += quick
CONFIG += c++17

include($$PWD/3rdparty/qnanopainter/libqnanopainter/include.pri)
include($$PWD/3rdparty/FramelessHelper/FramelessHelper.pri)

INCLUDEPATH += $$PWD/Source
SOURCES += \
    Source/CalcExample/ChartEntity.cpp \
    Source/CalcExample/ChartEntityManager.cpp \
    Source/CalcExample/InitCalcBlock.cpp \
    Source/CalcExample/RandCalcBlock.cpp \
    Source/CalcExample/SinCalcBlock.cpp \
    Source/Chart/ChartData.cpp \
    Source/Chart/ChartItem.cpp \
    Source/Chart/ChartItemPainter.cpp \
    Source/Core/Calc.cpp \
    Source/Core/CalcBlock.cpp \
    Source/Core/CalcCommand.cpp \
    Source/Core/CalcEntity.cpp \
    Source/Core/Command.cpp \
    Source/Core/FunctionalCommand.cpp \
    Source/Core/Platform.cpp \
    Source/Core/UndoStack.cpp \
    Source/Main.cpp \

RESOURCES += \
        $$PWD/Images/Images.qrc \
        $$PWD/Qml/Qml.qrc

QML_IMPORT_PATH = $$PWD/qml/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Source/CalcExample/ChartEntity.h \
    Source/CalcExample/ChartEntityManager.h \
    Source/CalcExample/InitCalcBlock.h \
    Source/CalcExample/RandCalcBlock.h \
    Source/CalcExample/SinCalcBlock.h \
    Source/Chart/ChartData.h \
    Source/Chart/ChartItem.h \
    Source/Chart/ChartItemPainter.h \
    Source/Core/Calc.h \
    Source/Core/CalcBlock.h \
    Source/Core/CalcCommand.h \
    Source/Core/CalcEntity.h \
    Source/Core/CalcForward.h \
    Source/Core/Command.h \
    Source/Core/FunctionalCommand.h \
    Source/Core/Platform.h \
    Source/Core/TypeHash.h \
    Source/Core/UndoStack.h \
