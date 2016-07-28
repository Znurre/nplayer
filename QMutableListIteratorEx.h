#ifndef QMUTABLELISTITERATOREX_H
#define QMUTABLELISTITERATOREX_H

#include <QMutableListIterator>

template<class T>
class QMutableListIteratorEx : public QMutableListIterator<T>
{
	public:
		QMutableListIteratorEx(QList<T> &container)
			: QMutableListIterator<T>(container)
		{

		}

		operator bool() const
		{
			return QMutableListIterator<T>::hasNext();
		}
};

#endif // QMUTABLELISTITERATOREX_H
