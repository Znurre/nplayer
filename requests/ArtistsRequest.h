#ifndef ARTISTSREQUEST_H
#define ARTISTSREQUEST_H

#include "IRequest.h"

class ArtistsRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // ARTISTSREQUEST_H
