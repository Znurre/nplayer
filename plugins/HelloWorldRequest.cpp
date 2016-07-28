#include <QDebug>

#include "HelloWorldRequest.h"
#include "RequestInvocationContext.h"
#include "IOutputHandler.h"

HelloWorldRequest::HelloWorldRequest()
{

}

QString HelloWorldRequest::trigger() const
{
	return "!hello";
}

RequestResponse HelloWorldRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);

	const IOutputHandler &outputHandler = context.outputHandler();

	outputHandler.say("Hello %1!", who);

	return RequestResponse();
}
