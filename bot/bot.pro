QT += quick

CONFIG += c++11 communi
COMMUNI += core

TARGET = nplayer
CONFIG += console jsonserializer

TEMPLATE = app

DEPENDPATH += ../shared
INCLUDEPATH += ../shared

SOURCES += main.cpp \
    IrcHandler.cpp \
    requests/LoadRequest.cpp \
    MessageHandler.cpp \
    RequestProvider.cpp \
    PluginLoader.cpp \
	requests/UnloadRequest.cpp \
	PluginScanner.cpp \
    OutputHandler.cpp \
    Channel.cpp

HEADERS += \
    IrcHandler.h \
    requests/LoadRequest.h \
    MessageHandler.h \
	RequestProvider.h \
    PluginLoader.h \
	requests/UnloadRequest.h \
	PluginScanner.h \
    QMutableListIteratorEx.h \
    OutputHandler.h \
    Channel.h

LIBS += -L../shared -lshared

QMAKE_CXXFLAGS += -Werror
