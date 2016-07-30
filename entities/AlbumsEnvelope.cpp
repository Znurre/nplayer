#include "AlbumsEnvelope.h"

AlbumsEnvelope::AlbumsEnvelope()
{

}

Array<Album *> AlbumsEnvelope::albums() const
{
	return m_albums;
}

void AlbumsEnvelope::setAlbums(const Array<Album *> &albums)
{
	m_albums = albums;
}
