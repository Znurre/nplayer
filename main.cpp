#include <QCoreApplication>
#include <QQmlComponent>

#include "IrcHandler.h"
#include "Utility.h"

#include "components/Template.h"
#include "components/Section.h"
#include "components/Text.h"
#include "components/StringModel.h"
#include "components/List.h"
#include "components/Conditional.h"
#include "components/HighlightFilter.h"

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	qmlRegisterSingletonType<Utility>("NowPlaying", 1, 0, "Utility", Utility::instance);

	qmlRegisterType<Template>("NowPlaying", 1, 0, "Template");
	qmlRegisterType<Section>("NowPlaying", 1, 0, "Section");
	qmlRegisterType<Text>("NowPlaying", 1, 0, "Text");
	qmlRegisterType<StringModel>("NowPlaying", 1, 0, "StringModel");
	qmlRegisterType<List>("NowPlaying", 1, 0, "List");
	qmlRegisterType<Conditional>("NowPlaying", 1, 0, "Conditional");
	qmlRegisterType<HighlightFilter>("NowPlaying", 1, 0, "HighlightFilter");

	IrcHandler ircHandler;
	ircHandler.open();

	return application.exec();
}
