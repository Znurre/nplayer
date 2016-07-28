#ifndef REQUESTREPOSITORY_H
#define REQUESTREPOSITORY_H

#include <QSet>
#include <QDebug>

#include "IRequest.h"
#include "RequestInvocationContext.h"

class RequestRepository
{
	public:
		RequestRepository();

		template<class TRequest>
		void attach()
		{
			IRequest *request = new TRequest();

			qDebug() << "Attaching request with trigger" << request->trigger();

			m_requests << request;
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
