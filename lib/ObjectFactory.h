#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <QJsonSerializer>

class InformationResourceRepository;
class IdGenerator;

class IInformationResourceFactory
{
	public:
		virtual bool canHandle(const QMetaObject *metaObject) = 0;

		virtual QObject *create(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) = 0;
};

template<class T>
class InformationResourceFactory : public IInformationResourceFactory
{
	public:
		bool canHandle(const QMetaObject *metaObject)
		{
			return metaObject == &T::staticMetaObject;
		}

		QObject *create(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
		{
			return new T(informationResourceRepository, idGenerator);
		}
};

class ObjectFactory : public DefaultObjectFactory
{
	public:
		ObjectFactory(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator);
		~ObjectFactory();

		void *create(const QMetaObject *metaObject) const override;

	private:
		InformationResourceRepository &m_informationResourceRepository;
		IdGenerator &m_idGenerator;

		QList<IInformationResourceFactory *> m_factories;
};

#endif // OBJECTFACTORY_H
