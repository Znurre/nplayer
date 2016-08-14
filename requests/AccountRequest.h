#ifndef ACCOUNTREQUEST_H
#define ACCOUNTREQUEST_H

#include "IRequest.h"

class AccountRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // ACCOUNTREQUEST_H
