#ifndef ARTISTS_H
#define ARTISTS_H

#include <QObject>
#include <QList>

class Artists : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QList<QObject *> artists READ artists WRITE setArtists NOTIFY artistsChanged)

	public:
		QList<QObject *> artists() const;
		void setArtists(const QList<QObject *> &artists);

	private:
		QList<QObject *> m_artists;

	signals:
		void artistsChanged();
};

#endif // ARTISTS_H
