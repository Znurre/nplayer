#ifndef TAGREQUEST_H
#define TAGREQUEST_H

#include "IRequest.h"

class TagRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // TAGREQUEST_H
