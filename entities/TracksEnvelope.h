#ifndef RECENTTRACKS_H
#define RECENTTRACKS_H

#include <QObject>

#include "Track.h"

class TracksEnvelope
	: public QObject
	, public IVerifiable
{
	Q_OBJECT

	Q_PROPERTY(Array<Track *> tracks READ tracks WRITE setTracks)

	public:
		Q_INVOKABLE TracksEnvelope() = default;

		Array<Track *> tracks() const;
		void setTracks(const Array<Track *> &tracks);

		bool isValid() const override;

	private:
		Array<Track *> m_tracks;
};

Q_DECLARE_METATYPE(TracksEnvelope *)

#endif // RECENTTRACKS_H
