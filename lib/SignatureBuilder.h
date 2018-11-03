#ifndef SIGNATUREBUILDER_H
#define SIGNATUREBUILDER_H

#include <QByteArray>
#include <QStringList>

#include "KeyValue.h"

class SignatureBuilder
{
	public:
		SignatureBuilder(const QByteArray &secret);

		void setParameters(const QList<as::KeyValue> &values);

		QString signature() const;

	private:
		QByteArray m_secret;
		QStringList m_parameters;
};
#endif // SIGNATUREBUILDER_H
