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
    entities/Artist.cpp \
    IdGenerator.cpp \
    RequestResponse.cpp \
    entities/NotPlaying.cpp \
    requests/HelloWorldRequest.cpp \
    requests/NowPlayingRequest.cpp \
    requests/AlbumRequest.cpp \
    RequestRepository.cpp \
    TriggerWalker.cpp \
    requests/ArtistRequest.cpp \
    StringUtils.cpp \
    iterators/ArtistTrackIterator.cpp \
    requests/TrackRequest.cpp \
    iterators/ArtistAlbumIterator.cpp \
    entities/TracksEnvelope.cpp \
    entities/AlbumsEnvelope.cpp \
    entities/Album.cpp \
    iterators/TrackAlbumIterator.cpp \
    entities/Tag.cpp \
    requests/TagRequest.cpp \
    iterators/TagArtistIterator.cpp \
    entities/ArtistsEnvelope.cpp \
    iterators/TagTrackIterator.cpp \
    iterators/AlbumTrackIterator.cpp \
    UserMapper.cpp \
    requests/AccountRequest.cpp \
    iterators/TrackArtistIterator.cpp \
    requests/UserRequest.cpp \
    components/HighlightFilter.cpp \
    entities/User.cpp \
    Utility.cpp \
    requests/UrlRequest.cpp \
    iterators/ArtistArtistIterator.cpp \
    iterators/TrackTrackIterator.cpp \
    requests/ArtistsRequest.cpp \
    entities/Artists.cpp \
    components/Url.cpp \
    iterators/UserArtistIterator.cpp \
    components/ListNg.cpp \
    components/Container.cpp

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
    entities/Artist.h \
    IdGenerator.h \
    RequestResponse.h \
    entities/NotPlaying.h \
    requests/HelloWorldRequest.h \
    requests/NowPlayingRequest.h \
    requests/AlbumRequest.h \
    TriggerWalker.h \
    requests/ArtistRequest.h \
    StringUtils.h \
    IIterator.h \
    iterators/ArtistTrackIterator.h \
    requests/TrackRequest.h \
    iterators/ArtistAlbumIterator.h \
    entities/TracksEnvelope.h \
    entities/AlbumsEnvelope.h \
    entities/Album.h \
    iterators/TrackAlbumIterator.h \
    entities/Tag.h \
    requests/TagRequest.h \
    iterators/TagArtistIterator.h \
    entities/ArtistsEnvelope.h \
    iterators/TagTrackIterator.h \
    iterators/AlbumTrackIterator.h \
    UserMapper.h \
    requests/AccountRequest.h \
    iterators/TrackArtistIterator.h \
    requests/UserRequest.h \
    components/HighlightFilter.h \
    entities/User.h \
    Utility.h \
    requests/UrlRequest.h \
    iterators/ArtistArtistIterator.h \
    iterators/TrackTrackIterator.h \
    requests/ArtistsRequest.h \
    entities/Artists.h \
    components/Url.h \
    iterators/UserArtistIterator.h \
    components/ListNg.h \
    components/Container.h

OTHER_FILES += \
    templates/NowPlaying.qml \
    templates/NotPlaying.qml \
    templates/Album.qml

gcc:QMAKE_CXXFLAGS += -Werror

DISTFILES += \
    templates/Artist.qml \
    templates/Track.qml \
    templates/Tag.qml \
    templates/AccountRegistered.qml \
    templates/NoMoreData.qml \
    templates/User.qml \
    templates/Url.qml \
    templates/Artists.qml
