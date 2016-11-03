#ifndef STATUSREQUEST_H
#define STATUSREQUEST_H

#include "IRequest.h"

class StatusRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // STATUSREQUEST_H
