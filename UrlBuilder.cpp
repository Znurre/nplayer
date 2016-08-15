#include "UrlBuilder.h"
#include "SignatureBuilder.h"
#include "QStringEx.h"

UrlBuilder::UrlBuilder(const QString &baseUrl)
	: m_baseUrl(baseUrl)
	, m_valid(true)
{

}

void UrlBuilder::setParameters(const QList<as::KeyValue> &values)
{
	m_queryBuilder.setParameters(values, m_valid);
}

QString UrlBuilder::url(const SignatureBuilder &signatureBuilder) const
{
	const QString &query = m_queryBuilder.build(signatureBuilder);
	const QString &url = QStringEx::format("%1/?%2&format=json", m_baseUrl, query);

	return url;
}

bool UrlBuilder::valid() const
{
	return m_valid;
}
