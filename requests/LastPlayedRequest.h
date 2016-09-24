#ifndef LASTPLAYEDREQUEST_H
#define LASTPLAYEDREQUEST_H

#include "RecentTracksRequest.h"

class LastPlayedRequest : public RecentTracksRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // LASTPLAYEDREQUEST_H
