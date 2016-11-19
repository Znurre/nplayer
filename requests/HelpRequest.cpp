#include "HelpRequest.h"
#include "RequestInvocationContext.h"
#include "RequestRepository.h"

#include "entities/Triggers.h"

QString HelpRequest::trigger() const
{
	return ".help";
}

RequestResponse HelpRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);

	RequestRepository &requestRepository = context.requestRepository();

	Array<QString> triggers;

	for (IRequest *request : requestRepository.requests())
	{
		triggers << request->trigger();
	}

	Triggers *envelope = new Triggers();
	envelope->setTriggers(triggers);

	return RequestResponse("templates/Triggers.qml", envelope);
}
