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
    MessageHandler.cpp \
    OutputHandler.cpp \
    Channel.cpp \
    RequestInvocationContext.cpp \
        QStringEx.cpp \
        RequestHandler.cpp \
        Key.cpp \
        KeyValue.cpp \
        QueryBuilder.cpp \
        UrlBuilder.cpp \
        SignatureBuilder.cpp \
    components/Template.cpp \
    components/Section.cpp \
    components/Text.cpp \
    RequestResult.cpp \
    components/StringModel.cpp \
    components/List.cpp \
    components/Conditional.cpp \
    ObjectFactory.cpp \
    entities/Track.cpp \
    InformationResourceRepository.cpp \
    entities/RecentTracks.cpp \
    entities/Artist.cpp \
    IdGenerator.cpp \
    RequestResponse.cpp \
    entities/NotPlaying.cpp \
    requests/HelloWorldRequest.cpp \
    requests/NowPlayingRequest.cpp \
    requests/AlbumRequest.cpp \
    RequestRepository.cpp

HEADERS += \
    IrcHandler.h \
    MessageHandler.h \
    QMutableListIteratorEx.h \
    OutputHandler.h \
    Channel.h \
    IRequest.h \
    RequestRepository.h \
    RequestInvocationContext.h \
        QStringEx.h \
    IOutputHandler.h \
    IResponse.h \
        RequestHandler.h \
        Key.h \
        KeyValue.h \
        QueryBuilder.h \
        UrlBuilder.h \
        SignatureBuilder.h \
    components/Template.h \
    components/Section.h \
    components/ITemplateComponent.h \
    components/Text.h \
    RequestResult.h \
    components/StringModel.h \
    components/List.h \
    components/Conditional.h \
    ObjectFactory.h \
    entities/Track.h \
    IInformationResource.h \
    InformationResourceRepository.h \
    entities/RecentTracks.h \
    entities/Artist.h \
    IdGenerator.h \
    RequestResponse.h \
    entities/NotPlaying.h \
    requests/HelloWorldRequest.h \
    requests/NowPlayingRequest.h \
    requests/AlbumRequest.h

gcc:QMAKE_CXXFLAGS += -Werror
