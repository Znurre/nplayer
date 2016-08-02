#include "Tag.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"

#include "iterators/TagArtistIterator.h"

Tag::Tag(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_id(idGenerator)
{
	repository.add(this);

	registerIterator<TagArtistIterator>();
}

QString Tag::id() const
{
	return m_id;
}

QString Tag::name() const
{
	return m_name;
}

void Tag::setName(const QString &name)
{
	m_name = name;
}

QString Tag::description() const
{
	return m_description;
}

void Tag::setDescription(const QString &description)
{
	m_description = description;
}
