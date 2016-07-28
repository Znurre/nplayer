#ifndef TEXT_H
#define TEXT_H

#include "ITemplateComponent.h"

class Text : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

	public:
		Text();

		QString text() const;
		void setText(const QString &text);

		QString render() override;

	private:
		QString m_text;

	signals:
		void textChanged();
};

#endif // TEXT_H
