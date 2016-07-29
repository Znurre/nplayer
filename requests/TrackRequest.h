#ifndef TRACKREQUEST_H
#define TRACKREQUEST_H

#include "IRequest.h"

class TrackRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // TRACKREQUEST_H
