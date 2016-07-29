#include "ArtistTrackIterator.h"

#include "entities/Artist.h"
#include "entities/Track.h"
#include "entities/RecentTracks.h"

ArtistTrackIterator::ArtistTrackIterator(Artist *artist)
	: m_artist(artist)
{

}

QList<Track *> ArtistTrackIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	RecentTracks *envelope = requestHandler
		.get<RecentTracks>("artist.getTopTracks"
			, as::artist = m_artist->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}
