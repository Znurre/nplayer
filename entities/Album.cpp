#include "Album.h"
#include "InformationResourceRepository.h"
#include "IdGenerator.h"

#include "iterators/AlbumTrackIterator.h"

Album::Album(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_requestHandler(repository, idGenerator)
	, m_id(idGenerator)
	, m_userPlayCount(0)
{
	repository.add(this);

	registerIterator<AlbumTrackIterator>();
}

QString Album::id() const
{
	return m_id;
}

QString Album::name() const
{
	return m_name;
}

void Album::setName(const QString &name)
{
	m_name = name;
}

QString Album::artist() const
{
	return m_artist;
}

void Album::setArtist(const QString &artist)
{
	m_artist = artist;
}

QString Album::user() const
{
	return m_user;
}

void Album::setUser(const QString &user)
{
	m_user = user;
}

QString Album::url() const
{
	return m_url;
}

void Album::setUrl(const QString &url)
{
	m_url = url;
}

Array<QString> Album::tags()
{
	return property(&Album::m_tags);
}

void Album::setTags(const Array<QString> &tags)
{
	m_tags = tags;
}

Array<Track *> Album::tracks() const
{
	return m_tracks;
}

void Album::setTracks(const Array<Track *> &tracks)
{
	m_tracks = tracks;
}

int Album::userPlayCount() const
{
	return m_userPlayCount;
}

void Album::setUserPlayCount(int userPlayCount)
{
	m_userPlayCount = userPlayCount;
}

void Album::fetchExtendedInfo()
{
	m_requestHandler
			.get(this, "album.getInfo"
			, as::artist = m_artist
			, as::album = m_name
			, as::user = m_user
		);
}
