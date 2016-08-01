#ifndef KEY_H
#define KEY_H

#include <QString>
#include <QStringBuilder>

#include "KeyValue.h"

namespace as
{
	class Key
	{
		public:
			Key(const char *name);

			KeyValue operator =(const QString &value) const;
			KeyValue operator =(const QByteArray &value) const;
			KeyValue operator =(int value) const;

		private:
			QString m_name;
	};

	const Key token = "token";
	const Key api_key = "api_key";
	const Key method = "method";
	const Key format = "format";
	const Key limit = "limit";
	const Key page = "page";
	const Key user = "user";
	const Key username = "username";
	const Key artist = "artist";
	const Key track = "track";
	const Key album = "album";
	const Key sk = "sk";
	const Key artist0 = "artist[0]";
	const Key track0 = "track[0]";
	const Key timestamp0 = "timestamp[0]";

}

#endif // KEY_H
