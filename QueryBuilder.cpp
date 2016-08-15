#include "QueryBuilder.h"
#include "SignatureBuilder.h"
#include "QStringEx.h"

void QueryBuilder::setParameters(const QList<as::KeyValue> &values, bool &valid)
{
	for(const as::KeyValue &value : values)
	{
		m_parameters << value.asQueryParameter(valid);
	}
}

QString QueryBuilder::build(const SignatureBuilder &signatureBuilder) const
{
	const QString &signature = signatureBuilder.signature();
	const QString &parameterPart = m_parameters.join("&");
	const QString &signaturePart = QStringEx::format("api_sig=%1", signature);

	const QStringList query = { parameterPart, signaturePart };

	return query.join("&");
}
