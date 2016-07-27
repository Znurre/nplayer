#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <QJsonSerializer>

class InformationResourceRepository;

class IInformationResourceFactory
{
	public:
		virtual bool canHandle(const QMetaObject *metaObject) = 0;

		virtual QObject *create(InformationResourceRepository &informationResourceRepository) = 0;
};

template<class T>
class InformationResourceFactory : public IInformationResourceFactory
{
	public:
		bool canHandle(const QMetaObject *metaObject)
		{
			return metaObject == &T::staticMetaObject;
		}

		QObject *create(InformationResourceRepository &informationResourceRepository)
		{
			return new T(informationResourceRepository);
		}
};

class ObjectFactory : public DefaultObjectFactory
{
	public:
		ObjectFactory(InformationResourceRepository &informationResourceRepository);

		QObject *create(const QMetaObject *metaObject) const override;

	private:
		InformationResourceRepository &m_informationResourceRepository;

		QList<IInformationResourceFactory *> m_factories;
};

#endif // OBJECTFACTORY_H
