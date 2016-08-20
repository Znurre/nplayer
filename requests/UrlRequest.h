#ifndef URLREQUEST_H
#define URLREQUEST_H

#include "IRequest.h"

class UrlRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // URLREQUEST_H
