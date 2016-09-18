#include "SpotifyTrack.h"

SpotifyItem::SpotifyItem()
	: m_externalUrls(nullptr)
{

}

SpotifyExternalUrl *SpotifyItem::externalUrls() const
{
	return m_externalUrls;
}

void SpotifyItem::setExternalUrls(SpotifyExternalUrl *externalUrls)
{
	m_externalUrls = externalUrls;
}
