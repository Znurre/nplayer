#include "AlbumsEnvelope.h"

Array<Album *> AlbumsEnvelope::albums() const
{
	return m_albums;
}

void AlbumsEnvelope::setAlbums(const Array<Album *> &albums)
{
	m_albums = albums;
}

bool AlbumsEnvelope::isValid() const
{
	return !m_albums.isEmpty();
}
