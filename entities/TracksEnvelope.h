#ifndef RECENTTRACKS_H
#define RECENTTRACKS_H

#include <QObject>

#include "Track.h"

class TracksEnvelope : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<Track *> tracks READ tracks WRITE setTracks)

	public:
		Q_INVOKABLE TracksEnvelope();

		Array<Track *> tracks() const;
		void setTracks(const Array<Track *> &tracks);

	private:
		Array<Track *> m_tracks;
};

#endif // RECENTTRACKS_H
