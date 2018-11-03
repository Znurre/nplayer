#include "HighlightFilter.h"

const QString CHARACTER = QString::fromUtf8("\342\200\213");

QString HighlightFilter::render()
{
	return ITemplateComponent::assemble();
}
