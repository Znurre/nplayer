#ifndef HELLOWORLDREQUEST_H
#define HELLOWORLDREQUEST_H

#include "IRequest.h"

class HelloWorldRequest : public IRequest
{
	public:
		HelloWorldRequest();

		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // HELLOWORLDREQUEST_H
