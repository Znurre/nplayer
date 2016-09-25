QT += quick

CONFIG += c++14 communi
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
    components/Container.cpp \
    requests/PingRequest.cpp \
    iterators/UserTrackIterator.cpp \
    iterators/UserTagIterator.cpp \
    entities/TagsEnvelope.cpp \
    entities/Tags.cpp \
    requests/TagsRequest.cpp \
    providers/LastFmUrlProvider.cpp \
    requests/LastFmUrlRequest.cpp \
    entities/UrlContext.cpp \
	providers/spotify/SpotifySearchResult.cpp \
	providers/spotify/SpotifyTrack.cpp \
    requests/SpotifyUrlRequest.cpp \
	providers/spotify/SpotifyExternalUrl.cpp \
    providers/TrackSpotifyUrlProvider.cpp \
    providers/ArtistSpotifyUrlProvider.cpp \
    providers/AlbumSpotifyUrlProvider.cpp \
    providers/YouTubeUrlProvider.cpp \
    providers/youtube/YouTubeSearchResult.cpp \
    providers/youtube/YouTubeSearchResultItem.cpp \
    providers/youtube/YouTubeSearchResultId.cpp \
    requests/YouTubeUrlRequest.cpp \
    requests/LastPlayedRequest.cpp \
    requests/RecentTracksRequest.cpp \
    entities/UserPeriod.cpp \
    requests/WeekRequest.cpp \
    requests/MonthRequest.cpp \
    requests/PeriodRequest.cpp \
    requests/YearRequest.cpp \
    iterators/UserAlbumIterator.cpp \
    iterators/TagAlbumIterator.cpp \
    iterators/AlbumArtistIterator.cpp

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
    components/Container.h \
    requests/PingRequest.h \
    iterators/UserTrackIterator.h \
    iterators/UserTagIterator.h \
    entities/TagsEnvelope.h \
    entities/Tags.h \
    requests/TagsRequest.h \
    IUrlProvider.h \
    providers/LastFmUrlProvider.h \
    requests/LastFmUrlRequest.h \
    entities/UrlContext.h \
    providers/SpotifyUrlProvider.h \
	providers/spotify/SpotifySearchResult.h \
	providers/spotify/SpotifyTrack.h \
	providers/spotify/SpotifySearchFragment.h \
    requests/SpotifyUrlRequest.h \
	providers/spotify/SpotifyExternalUrl.h \
    providers/TrackSpotifyUrlProvider.h \
    providers/ArtistSpotifyUrlProvider.h \
    providers/AlbumSpotifyUrlProvider.h \
    providers/YouTubeUrlProvider.h \
    providers/youtube/YouTubeSearchResult.h \
    providers/youtube/YouTubeSearchResultItem.h \
    providers/youtube/YouTubeSearchResultId.h \
    requests/YouTubeUrlRequest.h \
    requests/LastPlayedRequest.h \
    requests/RecentTracksRequest.h \
    entities/IUser.h \
    entities/UserPeriod.h \
    requests/WeekRequest.h \
    requests/MonthRequest.h \
    requests/PeriodRequest.h \
    requests/YearRequest.h \
    iterators/UserAlbumIterator.h \
    iterators/TagAlbumIterator.h \
    iterators/AlbumArtistIterator.h

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
    templates/Artists.qml \
    templates/Pong.qml \
    templates/Tags.qml \
    templates/LastPlayed.qml
