#include "Track.h"

Track::Track()
	: m_nowPlaying(false)
	, m_fetched(false)
	, m_userPlayCount(0)
{

}

bool Track::nowPlaying() const
{
	return m_nowPlaying;
}

void Track::setNowPlaying(bool nowPlaying)
{
	m_nowPlaying = nowPlaying;
}

QString Track::artist() const
{
	return m_artist;
}

void Track::setArtist(const QString &artist)
{
	m_artist = artist;
}

QString Track::name() const
{
	return m_name;
}

void Track::setName(const QString &name)
{
	m_name = name;
}

QString Track::album() const
{
	return m_album;
}

void Track::setAlbum(const QString &album)
{
	m_album = album;
}

Array<QString> Track::tags()
{
	return property<Array<QString>>([](Track &track)
	{
		return track.m_tags;
	});
}

void Track::setTags(const Array<QString> &tags)
{
	m_tags = tags;
}

int Track::userPlayCount()
{
	return property<int>([](Track &track)
	{
		return track.m_userPlayCount;
	});
}

void Track::setUserPlayCount(int userPlayCount)
{
	m_userPlayCount = userPlayCount;
}
