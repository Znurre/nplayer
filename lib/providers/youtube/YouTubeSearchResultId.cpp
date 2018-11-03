#include "YouTubeSearchResultId.h"

QString YouTubeSearchResultId::videoId() const
{
	return m_videoId;
}

void YouTubeSearchResultId::setVideoId(const QString &videoId)
{
	m_videoId = videoId;
}
