#include <QDebug>

#include "HelloWorldRequest.h"

HelloWorldRequest::HelloWorldRequest()
{

}

QString HelloWorldRequest::trigger() const
{
	return "!hello";
}

void HelloWorldRequest::invoke(const QStringList &arguments, const RequestInvocationContext &context)
{
	Q_UNUSED(context);

	qDebug() << "hello world?" << arguments;
}
