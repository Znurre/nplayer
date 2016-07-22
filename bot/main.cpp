#include <QCoreApplication>
#include <QQmlComponent>

#include "IrcHandler.h"

#include "components/Template.h"
#include "components/Section.h"
#include "components/Text.h"

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	qmlRegisterType<Template>("NowPlaying", 1, 0, "Template");
	qmlRegisterType<Section>("NowPlaying", 1, 0, "Section");
	qmlRegisterType<Text>("NowPlaying", 1, 0, "Text");

	IrcHandler ircHandler;
	ircHandler.open();

	return application.exec();
}
