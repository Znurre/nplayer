#ifndef IREQUEST_H
#define IREQUEST_H

#include <QString>

class RequestInvocationContext;

class IRequest
{
	public:
		virtual QString trigger() const = 0;

		virtual void invoke(const QStringList &arguments, const RequestInvocationContext &context) = 0;
};

#endif // IREQUEST_H
