#include "StringUtils.h"
#include "Artist.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"
#include "QStringEx.h"

#include "iterators/ArtistTrackIterator.h"
#include "iterators/ArtistAlbumIterator.h"
#include "iterators/ArtistArtistIterator.h"

Artist::Artist(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_requestHandler(repository, idGenerator)
	, m_id(idGenerator)
	, m_listeners(0)
{
	repository.add(this);

	registerIterator<ArtistTrackIterator>();
	registerIterator<ArtistAlbumIterator>();
	registerIterator<ArtistArtistIterator>();
}

QString Artist::id() const
{
	return m_id;
}

QString Artist::key() const
{
	return m_name;
}

QString Artist::name() const
{
	return m_name;
}

void Artist::setName(const QString &name)
{
	m_name = name;
}

QString Artist::bio()
{
	return property(&Artist::m_bio);
}

void Artist::setBio(const QString &bio)
{
	m_bio = StringUtils::cleanup(bio);
}

QString Artist::url() const
{
	return m_url;
}

void Artist::setUrl(const QString &url)
{
	m_url = url;
}

Array<QString> Artist::tags()
{
	return property(&Artist::m_tags);
}

void Artist::setTags(const Array<QString> &tags)
{
	m_tags = tags;
}

int Artist::listeners()
{
	return property(&Artist::m_listeners);
}

void Artist::setListeners(int listeners)
{
	m_listeners = listeners;
}

void Artist::fetchExtendedInfo()
{
	m_requestHandler
		.get(this, "artist.getInfo"
			, as::artist = m_name
		);
}
