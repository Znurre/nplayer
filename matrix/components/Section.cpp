#include "Section.h"
#include "QStringEx.h"

Section::Section()
{

}

QString Section::title() const
{
	return m_title;
}

void Section::setTitle(const QString &title)
{
	m_title = title;

	emit titleChanged();
}

QString Section::render()
{
	const QString &content = ITemplateComponent::assemble();
	const QString &string = QStringEx::format("<b>%1:</b> %2", m_title, content);

	return string;
}
