#include "ObjectFactory.h"

#include "entities/Track.h"

ObjectFactory::ObjectFactory(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
	: m_informationResourceRepository(informationResourceRepository)
	, m_idGenerator(idGenerator)
{
	m_factories =
	{
		new InformationResourceFactory<Track>()
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
