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
    RequestResult.h

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
    RequestResult.cpp

QMAKE_CXXFLAGS += -Werror

DISTFILES += \
    templates/NowPlaying.qml
