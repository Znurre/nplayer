TEMPLATE = lib
CONFIG += staticlib c++11 jsonserializer
QT += network quick

HEADERS += \
	IRequestProvider.h \
    IRequest.h \
    RequestRepository.h \
    RequestInvocationContext.h \
    IPluginLoader.h \
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
    IdGenerator.h \
    RequestResponse.h

SOURCES += \
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
    IdGenerator.cpp \
    RequestResponse.cpp

gcc:QMAKE_CXXFLAGS += -Werror

DISTFILES += \
    templates/NowPlaying.qml \
    templates/Album.qml
