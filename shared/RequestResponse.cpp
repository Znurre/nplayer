#include "RequestResponse.h"

#include <QString>

RequestResponse::RequestResponse(const QString &templateName, IInformationResource *resource)
	: m_templateName(templateName)
	, m_resource(resource)
{

}

QString RequestResponse::templateName() const
{
	return m_templateName;
}

IInformationResource *RequestResponse::resource() const
{
	return m_resource;
}
