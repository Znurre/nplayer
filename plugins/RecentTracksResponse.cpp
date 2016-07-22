#include "RecentTracksResponse.h"

RecentTracksResponse::RecentTracksResponse()
	: m_recentTracks(nullptr)
{

}

RecentTracks *RecentTracksResponse::recentTracks() const
{
	return m_recentTracks;
}

void RecentTracksResponse::setRecentTracks(RecentTracks *recentTracks)
{
	m_recentTracks = recentTracks;
}
