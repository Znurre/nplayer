#ifndef ALBUMREQUEST_H
#define ALBUMREQUEST_H

#include "IRequest.h"

class AlbumRequest : public IRequest
{
	public:
		AlbumRequest();

		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // ALBUMREQUEST_H
