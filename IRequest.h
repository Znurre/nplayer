#ifndef IREQUEST_H
#define IREQUEST_H

#include <QString>

#include "RequestResponse.h"

class RequestInvocationContext;

class IRequest
{
	public:
		virtual QString trigger() const = 0;

		virtual RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) = 0;
};

#endif // IREQUEST_H
