#ifndef NOWPLAYINGREQUEST_H
#define NOWPLAYINGREQUEST_H

#include "RecentTracksRequest.h"

class InformationResourceRepository;
class IdGenerator;

class NowPlayingRequest : public RecentTracksRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // NOWPLAYINGREQUEST_H
