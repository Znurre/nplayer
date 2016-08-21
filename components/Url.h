#ifndef URL_H
#define URL_H

#include "ITemplateComponent.h"

class Url : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

	public:
		QString render() override;

		QString text() const;
		void setText(const QString &text);

	private:
		QString m_text;

	signals:
		void textChanged();
};

#endif // URL_H
