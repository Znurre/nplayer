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

	public:
		Q_INVOKABLE SpotifySearchResult();

		SpotifyTrackSearchFragment *tracks() const;
		void setTracks(SpotifyTrackSearchFragment *tracks);

	private:
		SpotifyTrackSearchFragment *m_tracks;
};

#endif // SPOTIFYSEARCHRESULT_H
