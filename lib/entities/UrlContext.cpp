#include <QDebug>

#include "UrlContext.h"
#include "IUrlProvider.h"

UrlContext::UrlContext(IUrlProvider *urlProvider, IInformationResource *resource)
	: m_urlProvider(urlProvider)
	, m_resource(resource)
{

}

QString UrlContext::url() const
{
	qDebug() << "UrlContext::url()";

	return m_urlProvider->url(m_resource);
}
