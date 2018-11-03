#ifndef USERREQUEST_H
#define USERREQUEST_H

#include "IRequest.h"

class UserRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // USERREQUEST_H
