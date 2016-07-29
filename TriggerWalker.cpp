#include <QRegularExpression>

#include "TriggerWalker.h"
#include "RequestRepository.h"

TriggerWalker::TriggerWalker(const RequestRepository &requestRepository, const RequestInvocationContext &requestInvocationContext)
	: m_requestRepository(requestRepository)
	, m_requestInvocationContext(requestInvocationContext)
	, m_regex("^(?'trigger'\\.\\w+)")
{

}

RequestResponse TriggerWalker::walk(const QString &string, const QString &who, const QStringList &arguments) const
{
	RequestResponse response;

	return walk(response, string, who, arguments);
}

RequestResponse TriggerWalker::walk(const RequestResponse &response, const QString &string, const QString &who, const QStringList &arguments) const
{
	const QRegularExpressionMatch &match = m_regex.match(string);
	const QString &trigger = match.captured("trigger");

	if (!trigger.isEmpty())
	{
		IRequest *request = m_requestRepository.resolve(trigger);

		if (request)
		{
			const RequestResponse &response = request->invoke(arguments, who, m_requestInvocationContext);

			if (response.isValid())
			{
				IInformationResource *resource = response.resource();

				if (resource)
				{
					const int length = match.capturedLength();

					const QString &remaining = string.mid(length);
					const QStringList id =
					{
						resource->id()
					};

					return walk(response, remaining, who, id);
				}

				return response;
			}
		}
	}

	return response;
}
