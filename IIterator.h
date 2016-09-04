#ifndef IITERATOR_H
#define IITERATOR_H

#include <QList>
#include <QQueue>

class InformationResourceRepository;
class IdGenerator;
class IInformationResource;

template<class T>
class IIterator
{
	public:
		typedef T TResource;

		virtual T *next(IInformationResource *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) = 0;
};

template<class TResource, class T>
class IteratorBase : public IIterator<T>
{
	public:
		T *next(IInformationResource *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override
		{
			return next((TResource *)resource, informationResourceRepository, idGenerator);
		}

	protected:
		virtual T *next(TResource *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) = 0;
};

template<class TResource, class T>
class PagingIterator : public IteratorBase<TResource, T>
{
	public:
		PagingIterator()
			: m_page(1)
		{

		}

		T *next(TResource *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override
		{
			for (int i = false; m_queue.isEmpty(); i++)
			{
				if (i)
				{
					return nullptr;
				}

				m_queue << fetchMore(resource, informationResourceRepository, idGenerator, m_page++);
			}

			return m_queue.dequeue();
		}

	protected:
		virtual QList<T *> fetchMore(TResource *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) = 0;

	private:
		int m_page;

		QQueue<T *> m_queue;
};

#endif // IITERATOR_H
