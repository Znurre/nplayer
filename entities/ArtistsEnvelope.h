#ifndef ARTISTSENVELOPE_H
#define ARTISTSENVELOPE_H

#include <QObject>
#include <QJsonSerializer>

#include "Artist.h"

class ArtistsEnvelope : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<Artist *> artists READ artists WRITE setArtists NOTIFY artistsChanged)

	public:
		Q_INVOKABLE ArtistsEnvelope();

		Array<Artist *> artists() const;
		void setArtists(const Array<Artist *> &artists);

	private:
		Array<Artist *> m_artists;

	signals:
		void artistsChanged();
};

#endif // ARTISTSENVELOPE_H
