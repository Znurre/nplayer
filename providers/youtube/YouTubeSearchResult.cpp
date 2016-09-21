#include "YouTubeSearchResult.h"

Array<YouTubeSearchResultItem *> YouTubeSearchResult::items() const
{
	return m_items;
}

void YouTubeSearchResult::setItems(const Array<YouTubeSearchResultItem *> &items)
{
	m_items = items;
}
