#ifndef URLBUILDER_H
#define URLBUILDER_H

#include <QStringList>
#include <QString>

#include "KeyValue.h"
#include "QueryBuilder.h"

class SignatureBuilder;

class UrlBuilder
{
	public:
		UrlBuilder(const QString &baseUrl);

		void setParameters(const QList<as::KeyValue> &values);

		QString url(const SignatureBuilder &signatureBuilder) const;

		bool valid() const;

	private:
		QString m_baseUrl;
		QueryBuilder m_queryBuilder;

		bool m_valid;
};
#endif // URLBUILDER_H
