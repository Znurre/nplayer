#ifndef ALBUMSENVELOPE_H
#define ALBUMSENVELOPE_H

#include <QObject>
#include <QJsonSerializer>

#include "Album.h"

class AlbumsEnvelope
	: public QObject
	, public IVerifiable
{
	Q_OBJECT

	Q_PROPERTY(Array<Album *> albums READ albums WRITE setAlbums NOTIFY albumsChanged)

	public:
		Q_INVOKABLE AlbumsEnvelope() = default;

		Array<Album *> albums() const;
		void setAlbums(const Array<Album *> &albums);

		bool isValid() const override;

	private:
		Array<Album *> m_albums;

	signals:
		void albumsChanged();
};

#endif // ALBUMSENVELOPE_H
