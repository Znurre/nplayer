#include "Track.h"
#include "InformationResourceRepository.h"
#include "IdGenerator.h"
#include "QStringEx.h"

#include "iterators/TrackAlbumIterator.h"

Track::Track(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_requestHandler(repository, idGenerator)
	, m_nowPlaying(false)
	, m_fetched(false)
	, m_userLoved(false)
	, m_id(idGenerator)
	, m_userPlayCount(0)
{
	repository.add(this);

	registerIterator<TrackAlbumIterator>();
}

QString Track::id() const
{
	return m_id;
}

bool Track::nowPlaying() const
{
	return m_nowPlaying;
}

void Track::setNowPlaying(bool nowPlaying)
{
	m_nowPlaying = nowPlaying;
}

bool Track::userLoved()
{
	return property<bool>([](Track &track)
	{
		return track.m_userLoved;
	});
}

void Track::setUserLoved(bool userLoved)
{
	m_userLoved = userLoved;
}

bool Track::hasTags()
{
	return !tags().isEmpty();
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

QString Track::album()
{
	return property<QString>([](Track &track)
	{
		return track.m_album;
	});
}

void Track::setAlbum(const QString &album)
{
	m_album = album;
}

QString Track::user() const
{
	return m_user;
}

void Track::setUser(const QString &user)
{
	m_user = user;
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

QString Track::formattedTitle() const
{
	return QStringEx::format("%1 - %2", m_artist, m_name);
}
