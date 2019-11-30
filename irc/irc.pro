######################################################################
# Automatically generated by qmake (3.1) Wed Oct 24 18:06:59 2018
######################################################################

QT += quick xml

CONFIG += c++14 communi jsonserializer
COMMUNI += core

TEMPLATE = app
TARGET = nplayer-irc

INCLUDEPATH += . ../lib
DEPENDPATH += . ../lib

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += IrcHandler.h \
    OutputHandler.h \
    components/Template.h \
    components/Section.h \
    components/Text.h \
    components/StringModel.h \
    components/List.h \
    components/Conditional.h \
    components/HighlightFilter.h \
    components/Url.h \
    components/ListNg.h \
    components/Container.h

SOURCES += main.cpp \
    IrcHandler.cpp \
    OutputHandler.cpp \
    components/Template.cpp \
    components/Section.cpp \
    components/Text.cpp \
    components/StringModel.cpp \
    components/List.cpp \
    components/Conditional.cpp \
    components/HighlightFilter.cpp \
    components/Url.cpp \
    components/ListNg.cpp \
    components/Container.cpp

LIBS += -L$$OUT_PWD/../lib/ -lnplayer
