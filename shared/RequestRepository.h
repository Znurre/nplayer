#ifndef REQUESTREPOSITORY_H
#define REQUESTREPOSITORY_H

#include <QSet>
#include <QDebug>

#include "IRequest.h"

class RequestRepository
{
	public:
		template<class TRequest>
		void attach()
		{
			TRequest *request = new TRequest();

			qDebug() << "Attaching request with trigger" << request->trigger();

			m_requests << request;
		}

		template<class TRequest>
		void detach()
		{
			QSet<IRequest *> toRemove;

			for (IRequest *request : m_requests)
			{
				TRequest *casted = dynamic_cast<TRequest *>(request);

				if (casted)
				{
					toRemove << casted;
				}
			}

			m_requests -= toRemove;
		}

		IRequest *resolve(const QString &trigger)
		{
			for (IRequest *request : m_requests)
			{
				if (request->trigger() == trigger)
				{
					return request;
				}
			}

			return nullptr;
		}

	private:
		QSet<IRequest *> m_requests;
};

#endif // REQUESTREPOSITORY_H
