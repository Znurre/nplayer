#ifndef KEYVALUE_H
#define KEYVALUE_H

#include <QString>

namespace as
{
	class KeyValue
	{
		public:
			KeyValue(const QString &name, const QString &value);

			QString asQueryParameter() const;
			QString asJoined() const;

			bool operator <(const KeyValue &other) const;

		private:
			QString m_name;
			QString m_value;
	};
}

#endif // KEYVALUE_H
