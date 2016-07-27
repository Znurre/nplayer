TEMPLATE = lib
CONFIG += c++11 plugin jsonserializer
QT += network quick

DEPENDPATH += ../shared
INCLUDEPATH += ../shared

HEADERS += \
    RequestProvider.h \
    HelloWorldRequest.h \
    NowPlayingRequest.h \
    RecentTracksResponse.h \
    Artist.h

SOURCES += \
    RequestProvider.cpp \
    HelloWorldRequest.cpp \
    NowPlayingRequest.cpp \
    RecentTracksResponse.cpp \
    Artist.cpp

LIBS += -L../shared -lshared

QMAKE_CXXFLAGS += -Werror
