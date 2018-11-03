#include <QCryptographicHash>

#include "SignatureBuilder.h"

SignatureBuilder::SignatureBuilder(const QByteArray &secret)
	: m_secret(secret)
{

}

void SignatureBuilder::setParameters(const QList<as::KeyValue> &values)
{
	for(const as::KeyValue &value : values)
	{
		m_parameters << value.asJoined();
	}
}

QString SignatureBuilder::signature() const
{
	const QByteArray &joined = m_parameters
		.join(QString::null)
		.toUtf8();

	const QByteArray &hash = QCryptographicHash::hash(joined + m_secret, QCryptographicHash::Md5);
	const QByteArray &hex = hash.toHex();

	return hex;
}
