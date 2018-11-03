#include "HighlightFilter.h"

const QString CHARACTER = QString::fromUtf8("\342\200\213");

QString HighlightFilter::render()
{
	QString content = ITemplateComponent::assemble();

	return content.insert(2, CHARACTER);
}
