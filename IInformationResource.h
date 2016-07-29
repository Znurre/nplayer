#ifndef IINFORMATIONRESOURCE_H
#define IINFORMATIONRESOURCE_H

#include <QObject>
#include <QString>

#include "IIterator.h"

template<class TResource>
class IteratorResolverBase;

class IIteratorResolver
{
	public:
		virtual ~IIteratorResolver() = default;

		template<class TResource>
		IIterator<TResource> *resolve()
		{
			auto resolver = dynamic_cast<IteratorResolverBase<TResource> *>(this);

			if (resolver)
			{
				return resolver->resolve();
			}

			return nullptr;
		}
};

template<class TResource>
class IteratorResolverBase : public IIteratorResolver
{
	public:
		virtual IIterator<TResource> *resolve() = 0;
};

template<class TInstance, class TIterator>
class IteratorResolver : public IteratorResolverBase<typename TIterator::TResource>
{
	public:
		IteratorResolver(TInstance *instance)
			: m_iterator(instance)
		{

		}

		IIterator<typename TIterator::TResource> *resolve() override
		{
			return &m_iterator;
		}

	private:
		TIterator m_iterator;
};

class IInformationResource : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString id READ id CONSTANT)

	public:
		virtual QString id() const = 0;

		template<class TResource>
		IIterator<TResource> *iterator()
		{
			for (IIteratorResolver *resolver : m_iterators)
			{
				IIterator<TResource> *iterator = resolver->resolve<TResource>();

				if (iterator)
				{
					return iterator;
				}
			}

			return nullptr;
		}

	protected:
		QList<IIteratorResolver *> m_iterators;
};

template<class T>
class InformationResource : public IInformationResource
{
	protected:
		template<class TIterator>
		void registerIterator()
		{
			m_iterators << new IteratorResolver<T, TIterator>((T *)this);
		}
};

#endif // IINFORMATIONRESOURCE_H
