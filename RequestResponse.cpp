#include "RequestResponse.h"

#include <QString>

RequestResponse::RequestResponse()
	: m_dataContext(nullptr)
{

}

RequestResponse::RequestResponse(const QString &templateName, QObject *dataContext)
	: m_templateName(templateName)
	, m_dataContext(dataContext)
{

}

RequestResponse::RequestResponse(QObject *dataContext)
	: m_dataContext(dataContext)
{

}

QString RequestResponse::templateName() const
{
	return m_templateName;
}

QObject *RequestResponse::dataContext() const
{
	return m_dataContext;
}

IInformationResource *RequestResponse::resource() const
{
	return dynamic_cast<IInformationResource *>(m_dataContext);
}

bool RequestResponse::isValid() const
{
	return !m_templateName.isEmpty() || m_dataContext;
}
