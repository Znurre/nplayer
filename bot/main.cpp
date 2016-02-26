#include <QCoreApplication>

#include "IrcHandler.h"

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	IrcHandler ircHandler;
	ircHandler.open();

	return application.exec();
}
