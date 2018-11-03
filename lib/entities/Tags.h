#ifndef TAGS_H
#define TAGS_H

#include <QObject>
#include <QList>

class Tags : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QList<QObject *> tags READ tags WRITE setTags NOTIFY tagsChanged)

	public:
		QList<QObject *> tags() const;
		void setTags(const QList<QObject *> &tags);

	private:
		QList<QObject *> m_tags;

	signals:
		void tagsChanged();
};

#endif // TAGS_H
