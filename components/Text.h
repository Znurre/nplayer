#ifndef TEXT_H
#define TEXT_H

#include "ITemplateComponent.h"

class Text : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

	Q_PROPERTY(int maxLength READ maxLength WRITE setMaxLength NOTIFY maxLengthChanged)

	public:
		Text();

		QString text() const;
		void setText(QString text);

		int maxLength() const;
		void setMaxLength(int maxLength);

		QString render() override;

	private:
		int m_maxLength;

		QString m_text;

	signals:
		void textChanged();
		void maxLengthChanged();
};

#endif // TEXT_H
