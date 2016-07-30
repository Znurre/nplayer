#ifndef TRACKREQUEST_H
#define TRACKREQUEST_H

#include <QRegularExpression>

#include "IRequest.h"

class TrackRequest : public IRequest
{
	public:
		TrackRequest();

		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;

	private:
		QRegularExpression m_regex;
};

#endif // TRACKREQUEST_H
