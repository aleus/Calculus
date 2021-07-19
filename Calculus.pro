QT += quick
CONFIG += c++17

include($$PWD/3rdparty/qnanopainter/libqnanopainter/include.pri)
include($$PWD/3rdparty/FramelessHelper/FramelessHelper.pri)

INCLUDEPATH += $$PWD/Source
SOURCES += \
        $$PWD/Source/Main.cpp \
        Source/Body.cpp \
        Source/Calc.cpp \
        Source/CalcBlock.cpp \
        Source/CalcEntity.cpp \
        Source/ChartData.cpp \
        Source/ChartItem.cpp \
        Source/ChartItemPainter.cpp \
        Source/Command.cpp \
        Source/CommandManager.cpp \
        Source/Platform.cpp \
        Source/UndoStack.cpp

RESOURCES += \
        $$PWD/Images/Images.qrc \
        $$PWD/Qml/Qml.qrc

QML_IMPORT_PATH = $$PWD/qml/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Source/Body.h \
    Source/Calc.h \
    Source/CalcBlock.h \
    Source/CalcEntity.h \
    Source/ChartData.h \
    Source/ChartItem.h \
    Source/ChartItemPainter.h \
    Source/Command.h \
    Source/CommandManager.h \
    Source/Platform.h \
    Source/TypeHash.h \
    Source/UndoStack.h
