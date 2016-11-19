#ifndef HELPREQUEST_H
#define HELPREQUEST_H

#include "IRequest.h"

class HelpRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // HELPREQUEST_H
