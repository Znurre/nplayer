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
    Artist.h \
    AlbumRequest.h

SOURCES += \
    RequestProvider.cpp \
    HelloWorldRequest.cpp \
    NowPlayingRequest.cpp \
    RecentTracksResponse.cpp \
    Artist.cpp \
    AlbumRequest.cpp

win32:LIBS += -L../shared/debug -lshared
unix:LIBS += -L../shared -lshared

gcc:QMAKE_CXXFLAGS += -Werror
