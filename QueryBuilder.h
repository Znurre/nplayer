#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QList>
#include <QStringList>

#include "KeyValue.h"

class SignatureBuilder;

class QueryBuilder
{
	public:
		void setParameters(const QList<as::KeyValue> &values, bool &valid);

		QString build(const SignatureBuilder &signatureBuilder) const;

	private:
		QStringList m_parameters;
};

#endif // QUERYBUILDER_H
