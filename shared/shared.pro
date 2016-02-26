TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += \
	IRequestProvider.h \
    IRequest.h \
    RequestRepository.h \
    RequestInvocationContext.h \
    IPluginLoader.h \
	QStringEx.h

SOURCES += \
    RequestInvocationContext.cpp \
	QStringEx.cpp

QMAKE_CXXFLAGS += -Werror
