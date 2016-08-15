#include "ObjectFactory.h"

#include "entities/Track.h"
#include "entities/Artist.h"
#include "entities/Album.h"
#include "entities/Tag.h"
#include "entities/User.h"

ObjectFactory::ObjectFactory(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
	: m_informationResourceRepository(informationResourceRepository)
	, m_idGenerator(idGenerator)
{
	m_factories =
	{
		new InformationResourceFactory<Track>(),
		new InformationResourceFactory<Artist>(),
		new InformationResourceFactory<Album>(),
		new InformationResourceFactory<Tag>(),
		new InformationResourceFactory<User>(),
	};
}

QObject *ObjectFactory::create(const QMetaObject *metaObject) const
{
	for (IInformationResourceFactory *factory : m_factories)
	{
		if (factory->canHandle(metaObject))
		{
			return factory->create(m_informationResourceRepository, m_idGenerator);
		}
	}

	return DefaultObjectFactory::create(metaObject);
}
