#include "StatusResponse.h"

QString StatusResponse::message() const
{
	return m_message;
}

void StatusResponse::setMessage(const QString &message)
{
	m_message = message;

	emit messageChanged();
}
