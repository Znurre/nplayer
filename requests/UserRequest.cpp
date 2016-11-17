#include "UserRequest.h"
#include "RequestHandler.h"
#include "UserMapper.h"
#include "RequestInvocationContext.h"
#include "InformationResourceRepository.h"

#include "entities/User.h"
#include "entities/NotFound.h"

QString UserRequest::trigger() const
{
	return ".user";
}

RequestResponse UserRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();
	UserMapper &userMapper = context.userMapper();

	RequestHandler requestHandler(repository, idGenerator);

	User *user = requestHandler
		.get<User>("user.getInfo"
			, as::user = userMapper.map(arguments, who)
		);

	if (user)
	{
		return RequestResponse("templates/User.qml", user);
	}

	NotFound *notFound = new NotFound();
	notFound->setTypeName("User");

	return RequestResponse("templates/NotFound.qml", notFound);
}
