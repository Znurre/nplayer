#ifndef NOWPLAYINGREQUEST_H
#define NOWPLAYINGREQUEST_H

#include "IRequest.h"

class Track;
class InformationResourceRepository;
class IdGenerator;

class NowPlayingRequest : public IRequest
{
	public:
		NowPlayingRequest();

		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;

	private:
		Track *getNowPlaying(const QString &user, InformationResourceRepository &repository, IdGenerator &idGenerator) const;
};

#endif // NOWPLAYINGREQUEST_H
