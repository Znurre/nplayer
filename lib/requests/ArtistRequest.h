#ifndef ARTISTREQUEST_H
#define ARTISTREQUEST_H

#include "IRequest.h"

class ArtistRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // ARTISTREQUEST_H
