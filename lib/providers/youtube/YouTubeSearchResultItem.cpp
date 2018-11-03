#include "YouTubeSearchResultItem.h"

YouTubeSearchResultItem::YouTubeSearchResultItem()
	: m_id(nullptr)
{

}

YouTubeSearchResultId *YouTubeSearchResultItem::id() const
{
	return m_id;
}

void YouTubeSearchResultItem::setId(YouTubeSearchResultId *id)
{
	m_id = id;
}
