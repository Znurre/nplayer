#include "PingRequest.h"

QString PingRequest::trigger() const
{
	return ".ping";
}

RequestResponse PingRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);
	Q_UNUSED(context);

	return RequestResponse("templates/Pong.qml", nullptr);
}
