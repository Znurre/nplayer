#ifndef IITERATOR_H
#define IITERATOR_H

#include <QList>
#include <QQueue>

class InformationResourceRepository;
class IdGenerator;

template<class T>
class IIterator
{
	public:
		typedef T TResource;

		virtual T *next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) = 0;
};

template<class T>
class IteratorBase : public IIterator<T>
{
	public:
		IteratorBase()
			: m_page(0)
		{

		}

		T *next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override
		{
			for (int i = false; m_queue.isEmpty(); i++)
			{
				if (i)
				{
					return nullptr;
				}

				m_queue << fetchMore(informationResourceRepository, idGenerator, m_page++);
			}

			return m_queue.dequeue();
		}

	protected:
		virtual QList<T *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) = 0;

	private:
		int m_page;

		QQueue<T *> m_queue;
};

#endif // IITERATOR_H
