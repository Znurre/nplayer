#ifndef IINFORMATIONRESOURCE_H
#define IINFORMATIONRESOURCE_H

#include <QObject>
#include <QString>

#include "IIterator.h"

template<class TResource>
class IteratorResolverBase;

class IInformationResource;

class IIteratorResolver
{
	public:
		virtual ~IIteratorResolver() = default;

		virtual void unregister(IInformationResource *resource) = 0;

		template<class TResource>
		IIterator<TResource> *resolve(IInformationResource *resource)
		{
			auto resolver = dynamic_cast<IteratorResolverBase<TResource> *>(this);

			if (resolver)
			{
				return resolver->resolve(resource);
			}

			return nullptr;
		}
};

class IInformationResource : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString id READ id CONSTANT)

	public:
		virtual QString id() const = 0;
		virtual QString key() const = 0;
		virtual QString url() const = 0;

		template<class TResource>
		IIterator<TResource> *iterator()
		{
			for (IIteratorResolver *resolver : m_iterators)
			{
				IIterator<TResource> *iterator = resolver->resolve<TResource>(this);

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

template<class TResource>
class IteratorResolverBase : public IIteratorResolver
{
	public:
		virtual IIterator<TResource> *resolve(IInformationResource *resource) = 0;
};

template<class TInstance, class TIterator>
class IteratorResolver : public IteratorResolverBase<typename TIterator::TResource>
{
	public:
		IIterator<typename TIterator::TResource> *resolve(IInformationResource *resource) override
		{
			const QString &key = resource->key();
			
			return &s_iterators[key];
		}

		void unregister(IInformationResource *resource) override
		{
			const QString &key = resource->key();

			s_iterators.remove(key);
		}

	private:
		static QHash<QString, TIterator> s_iterators;
};

template<class TInstance, class TIterator>
QHash<QString, TIterator> IteratorResolver<TInstance, TIterator>::s_iterators;

template<class T>
class InformationResource : public IInformationResource
{
	public:
		InformationResource()
			: m_fetched(false)
		{
			startTimer(1000 * 60 * 5);
		}

	protected:
		template<class TIterator>
		void registerIterator()
		{
			m_iterators << new IteratorResolver<T, TIterator>();
		}

		template<class TReturn>
		TReturn property(TReturn T::*accessor)
		{
			static const TReturn DefaultValue = TReturn();

			const T *instance = static_cast<T *>(this);
			const TReturn &field = (instance->*accessor);

			if (field == DefaultValue)
			{
				if (!m_fetched)
				{
					m_fetched = true;

					fetchExtendedInfo();

					return (instance->*accessor);
				}
			}

			return field;
		}

		virtual void fetchExtendedInfo()
		{

		}

	private:
		void timerEvent(QTimerEvent *event) override
		{
			Q_UNUSED(event);

			for (IIteratorResolver *iterator : m_iterators)
			{
				iterator->unregister(this);

				delete iterator;
			}

			delete this;
		}

		bool m_fetched;
};

#endif // IINFORMATIONRESOURCE_H
