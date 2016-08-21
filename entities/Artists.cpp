#include "Artists.h"

Array<QString> Artists::artists() const
{
	return m_artists;
}

void Artists::setArtists(const Array<QString> &artists)
{
	m_artists = artists;
}
