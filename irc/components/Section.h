#ifndef SECTION_H
#define SECTION_H

#include "ITemplateComponent.h"

class Section : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

	public:
		Section();

		QString title() const;
		void setTitle(const QString &title);

		QString render() override;

	private:
		QString m_title;

	signals:
		void titleChanged();
};

#endif // SECTION_H
