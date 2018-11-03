#include "AccountRequest.h"
#include "RequestInvocationContext.h"
#include "UserMapper.h"

QString AccountRequest::trigger() const
{
	return ".account";
}

RequestResponse AccountRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	const QString &nickname = who;
	const QString &username = arguments.join(QChar::Space);

	UserMapper &userMapper = context.userMapper();
	userMapper.store(nickname, username);

	return RequestResponse("templates/AccountRegistered.qml", nullptr);
}
