QT += winextras

INCLUDEPATH += $$PWD
LIBS += -lUser32

HEADERS += \
    $$PWD/WindowFramelessHelper.h \
    $$PWD/WindowFramelessHelper_p.h
SOURCES += \
    $$PWD/WindowFramelessHelper.cpp

HEADERS += \
    $$PWD/Kernels/NativeWindowFilter.h \
    $$PWD/Kernels/NativeWindowFilter_p.h \
    $$PWD/Kernels/NativeWindowHelper.h \
    $$PWD/Kernels/NativeWindowHelper_p.h
SOURCES += \
    $$PWD/Kernels/NativeWindowFilter.cpp \
    $$PWD/Kernels/NativeWindowHelper.cpp
