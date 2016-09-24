#ifndef RECENTTRACKSREQUEST_H
#define RECENTTRACKSREQUEST_H

#include <QString>

#include "IRequest.h"

class Track;

using TrackPredicate = bool (*)(Track *track);

class RecentTracksRequest : public IRequest
{
	protected:
		Track *getRecentTrack(const QString &nick, const RequestInvocationContext &context, TrackPredicate predicate) const;
};

#endif // RECENTTRACKSREQUEST_H
