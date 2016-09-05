#ifndef PINGREQUEST_H
#define PINGREQUEST_H

#include "IRequest.h"

class PingRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // PINGREQUEST_H
