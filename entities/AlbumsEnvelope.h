#ifndef ALBUMSENVELOPE_H
#define ALBUMSENVELOPE_H

#include <QObject>
#include <QJsonSerializer>

#include "Album.h"

class AlbumsEnvelope : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<Album *> albums READ albums WRITE setAlbums NOTIFY albumsChanged)

	public:
		Q_INVOKABLE AlbumsEnvelope();

		Array<Album *> albums() const;
		void setAlbums(const Array<Album *> &albums);

	private:
		Array<Album *> m_albums;

	signals:
		void albumsChanged();
};

#endif // ALBUMSENVELOPE_H
