#include "Artists.h"

QList<QObject *> Artists::artists() const
{
	return m_artists;
}

void Artists::setArtists(const QList<QObject *> &artists)
{
	m_artists = artists;
}
