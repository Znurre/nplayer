#ifndef SPOTIFYSEARCHRESULT_H
#define SPOTIFYSEARCHRESULT_H

#include <QObject>
#include <QJsonSerializer>

#include "SpotifyTrack.h"
#include "SpotifySearchFragment.h"

class SpotifySearchResult : public QObject
{
	Q_OBJECT

	Q_PROPERTY(SpotifyTrackSearchFragment *tracks READ tracks WRITE setTracks)
	Q_PROPERTY(SpotifyArtistSearchFragment *artists READ artists WRITE setArtists)

	public:
		Q_INVOKABLE SpotifySearchResult();

		SpotifyTrackSearchFragment *tracks() const;
		void setTracks(SpotifyTrackSearchFragment *tracks);

		SpotifyArtistSearchFragment *artists() const;
		void setArtists(SpotifyArtistSearchFragment *artists);

	private:
		SpotifyTrackSearchFragment *m_tracks;
		SpotifyArtistSearchFragment *m_artists;
};

#endif // SPOTIFYSEARCHRESULT_H
