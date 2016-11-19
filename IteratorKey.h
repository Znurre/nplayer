#ifndef ITERATORKEY_H
#define ITERATORKEY_H

#include <QHash>

class IteratorKey
{
	friend uint qHash(const IteratorKey &key);

	public:
		IteratorKey(const QString &key);

		bool operator ==(const IteratorKey &other) const;

	private:
		QString m_key;
};

uint qHash(const IteratorKey &key);

#endif // ITERATORKEY_H
