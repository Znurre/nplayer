#ifndef ARTISTS_H
#define ARTISTS_H

#include <QObject>
#include <QJsonSerializer>

class Artists : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<QString> artists READ artists WRITE setArtists NOTIFY artistsChanged)

	public:
		Array<QString> artists() const;
		void setArtists(const Array<QString> &artists);

	private:
		Array<QString> m_artists;

	signals:
		void artistsChanged();
};

#endif // ARTISTS_H
