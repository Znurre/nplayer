#include <QRegularExpression>

#include "StringUtils.h"
#include "QStringEx.h"

QString StringUtils::cleanup(QString string)
{
	static QRegularExpression regex("(<.+(>|/>))", QRegularExpression::InvertedGreedinessOption);

	return string
		.remove(regex)
		.replace("&quot;", "\"")
		.simplified();
}

QString StringUtils::elide(QString string, int length)
{
	if (string.size() > length)
	{
		string.truncate(length);

		return QStringEx::format("%1...", string);
	}

	return string;
}
