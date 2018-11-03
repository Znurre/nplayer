#ifndef TRIGGERWALKER_H
#define TRIGGERWALKER_H

#include <QRegularExpression>
#include <QString>

#include "RequestResponse.h"

class RequestRepository;
class RequestInvocationContext;

class TriggerWalker
{
	public:
		TriggerWalker(const RequestRepository &requestRepository, const RequestInvocationContext &requestInvocationContext);

		RequestResponse walk(const QString &string, const QString &who, const QStringList &arguments) const;

	private:
		RequestResponse walk(const RequestResponse &candidate, const QString &string, const QString &who, const QStringList &arguments) const;

		const RequestRepository &m_requestRepository;
		const RequestInvocationContext &m_requestInvocationContext;

		QRegularExpression m_regex;
};

#endif // TRIGGERWALKER_H
