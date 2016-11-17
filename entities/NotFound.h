#ifndef NOTFOUND_H
#define NOTFOUND_H

#include <QObject>

class NotFound : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString typeName READ typeName WRITE setTypeName NOTIFY typeNameChanged)

	public:
		QString typeName() const;
		void setTypeName(const QString &typeName);

	private:
		QString m_typeName;

	signals:
		void typeNameChanged();
};

#endif // NOTFOUND_H
