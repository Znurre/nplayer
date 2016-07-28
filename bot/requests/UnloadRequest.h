#ifndef UNLOADREQUEST_H
#define UNLOADREQUEST_H

#include "IRequest.h"

class UnloadRequest : public IRequest
{
	public:
		UnloadRequest();

		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // UNLOADREQUEST_H
