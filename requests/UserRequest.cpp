#include "UserRequest.h"

QString UserRequest::trigger() const
{
	return ".user";
}

RequestResponse UserRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);
	Q_UNUSED(context);

	return RequestResponse();
}
