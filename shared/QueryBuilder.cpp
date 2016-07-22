#include "QueryBuilder.h"
#include "SignatureBuilder.h"
#include "QStringEx.h"

void QueryBuilder::setParameters(const QList<as::KeyValue> &values)
{
	for(const as::KeyValue &value : values)
	{
		m_parameters << value.asQueryParameter();
	}
}

QString QueryBuilder::build(const SignatureBuilder &signatureBuilder) const
{
	const QString &parameters = m_parameters.join("&");
	const QString &signature = signatureBuilder.signature();
	const QString &query = QStringEx::format("%1&api_sig=%2", parameters, signature);

	return query;
}
