#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <QString>

class StringUtils
{
	public:
		static QString cleanup(QString string);
		static QString elide(QString string, int length);
};

#endif // STRINGUTILS_H
