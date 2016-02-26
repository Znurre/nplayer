TEMPLATE = lib
CONFIG += c++11 plugin

DEPENDPATH += ../shared
INCLUDEPATH += ../shared

HEADERS += \
    RequestProvider.h \
    HelloWorldRequest.h

SOURCES += \
    RequestProvider.cpp \
    HelloWorldRequest.cpp

LIBS += -L../shared -lshared

QMAKE_CXXFLAGS += -Werror
