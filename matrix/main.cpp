#include <QCoreApplication>
#include <QQmlComponent>

#include "MatrixHandler.h"
#include "Utility.h"

#include "components/Template.h"
#include "components/Section.h"
#include "components/Text.h"
#include "components/StringModel.h"
#include "components/List.h"
#include "components/Conditional.h"
#include "components/HighlightFilter.h"
#include "components/Url.h"
#include "components/ListNg.h"
#include "components/Container.h"

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	if (argc < 4)
	{
		qDebug() << "Usage: nplayer-matrix <user> <password> <device_name>";

		return -1;
	}

	qmlRegisterSingletonType<Utility>("NowPlaying", 1, 0, "Utility", Utility::instance);

	qmlRegisterType<Template>("NowPlaying", 1, 0, "Template");
	qmlRegisterType<Section>("NowPlaying", 1, 0, "Section");
	qmlRegisterType<Text>("NowPlaying", 1, 0, "Text");
	qmlRegisterType<StringModel>("NowPlaying", 1, 0, "StringModel");
	qmlRegisterType<List>("NowPlaying", 1, 0, "List");
	qmlRegisterType<Conditional>("NowPlaying", 1, 0, "Conditional");
	qmlRegisterType<HighlightFilter>("NowPlaying", 1, 0, "HighlightFilter");
	qmlRegisterType<Url>("NowPlaying", 1, 0, "Url");
	qmlRegisterType<ListNg>("NowPlaying", 1, 0, "ListNg");
	qmlRegisterType<Container>("NowPlaying", 1, 0, "Container");

	MatrixHandler matrixHandler;
	matrixHandler.setHomeserver(QUrl("https://matrix.znurre.com"));
	matrixHandler.connectToServer(argv[1], argv[2], argv[3]);

	return application.exec();
}
