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
	Q_PROPERTY(SpotifyAlbumSearchFragment *albums READ albums WRITE setAlbums)

	public:
		Q_INVOKABLE SpotifySearchResult();

		SpotifyTrackSearchFragment *tracks() const;
		void setTracks(SpotifyTrackSearchFragment *tracks);

		SpotifyArtistSearchFragment *artists() const;
		void setArtists(SpotifyArtistSearchFragment *artists);

		SpotifyAlbumSearchFragment* albums() const;
		void setAlbums(SpotifyAlbumSearchFragment* albums);

	private:
		SpotifyTrackSearchFragment *m_tracks;
		SpotifyArtistSearchFragment *m_artists;
		SpotifyAlbumSearchFragment *m_albums;
};

#endif // SPOTIFYSEARCHRESULT_H
