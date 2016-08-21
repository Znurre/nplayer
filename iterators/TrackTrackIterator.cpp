#include "TrackTrackIterator.h"
#include "RequestHandler.h"

#include "entities/TracksEnvelope.h"
#include "entities/Track.h"

TrackTrackIterator::TrackTrackIterator(Track *track)
	: m_track(track)
{

}

QList<Track *> TrackTrackIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TracksEnvelope *envelope = requestHandler
		.get<TracksEnvelope>("track.getSimilar"
			, as::artist = m_track->artist()
			, as::track = m_track->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}
