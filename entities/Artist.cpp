#include "StringUtils.h"
#include "Artist.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"
#include "QStringEx.h"

#include "iterators/ArtistTrackIterator.h"
#include "iterators/ArtistAlbumIterator.h"

Artist::Artist(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
	: m_id(idGenerator)
{
	informationResourceRepository.add(this);

	registerIterator<ArtistTrackIterator>();
	registerIterator<ArtistAlbumIterator>();
}

QString Artist::id() const
{
	return m_id;
}

QString Artist::name() const
{
	return m_name;
}

void Artist::setName(const QString &name)
{
	m_name = name;
}

QString Artist::bio() const
{
	return m_bio;
}

void Artist::setBio(const QString &bio)
{
	m_bio = StringUtils::cleanup(bio);
}

Array<QString> Artist::tags() const
{
	return m_tags;
}

void Artist::setTags(const Array<QString> &tags)
{
	m_tags = tags;
}

int Artist::listeners() const
{
	return m_listeners;
}

void Artist::setListeners(int listeners)
{
	m_listeners = listeners;
}
