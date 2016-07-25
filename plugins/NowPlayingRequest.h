#ifndef NOWPLAYINGREQUEST_H
#define NOWPLAYINGREQUEST_H

#include "IRequest.h"

class Track;

class NowPlayingRequest : public IRequest
{
	public:
		NowPlayingRequest();

		QString trigger() const override;

		void invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;

	private:
		Track *getNowPlaying(const QString &user) const;
};

#endif // NOWPLAYINGREQUEST_H
