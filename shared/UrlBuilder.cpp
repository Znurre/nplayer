#include "UrlBuilder.h"
#include "SignatureBuilder.h"
#include "QStringEx.h"

UrlBuilder::UrlBuilder(const QString &baseUrl)
	: m_baseUrl(baseUrl)
{

}

void UrlBuilder::setParameters(const QList<as::KeyValue> &values)
{
	m_queryBuilder.setParameters(values);
}

QString UrlBuilder::url(const SignatureBuilder &signatureBuilder) const
{
	const QString &query = m_queryBuilder.build(signatureBuilder);
	const QString &url = QStringEx::format("%1/?%2", m_baseUrl, query);

	return url;
}
