#include "Tag.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"

#include "iterators/TagArtistIterator.h"
#include "iterators/TagTrackIterator.h"

#include "providers/LastFmUrlProvider.h"

Tag::Tag(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_requestHandler(repository, idGenerator)
	, m_repository(repository)
	, m_id(idGenerator)
{
	m_repository.add(this);

	registerIterator<TagArtistIterator>();
	registerIterator<TagTrackIterator>();

	registerUrlProvider<LastFmUrlProvider>();
}

Tag::~Tag()
{
	m_repository.remove(this);
}

QString Tag::id() const
{
	return m_id;
}

QString Tag::key() const
{
	return m_name;
}

QString Tag::name() const
{
	return m_name;
}

void Tag::setName(const QString &name)
{
	m_name = name;
}

QString Tag::description()
{
	return property(&Tag::m_description);
}

void Tag::setDescription(const QString &description)
{
	m_description = description;
}

QString Tag::url() const
{
	return m_url;
}

void Tag::setUrl(const QString &url)
{
	m_url = url;
}

void Tag::fetchExtendedInfo()
{
	m_requestHandler
		.get(this, "tag.getInfo"
			, as::tag = m_name
		);
}
