#include "ArtistsEnvelope.h"

ArtistsEnvelope::ArtistsEnvelope()
{

}

Array<Artist *> ArtistsEnvelope::artists() const
{
	return m_artists;
}

void ArtistsEnvelope::setArtists(const Array<Artist *> &artists)
{
	m_artists = artists;
}
