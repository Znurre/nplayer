#include "PeriodRequest.h"
#include "RequestInvocationContext.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"

#include "entities/User.h"
#include "entities/UserPeriod.h"

RequestResponse PeriodRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &periodName = period();
	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	User *user = repository.get<User>(id);

	if (user)
	{
		UserPeriod *period = new UserPeriod(user, repository, idGenerator);
		period->setPeriod(periodName	);

		return RequestResponse(period);
	}

	return RequestResponse();
}
