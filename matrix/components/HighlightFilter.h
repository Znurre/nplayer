#ifndef HIGHLIGHTFILTER_H
#define HIGHLIGHTFILTER_H

#include "ITemplateComponent.h"

class HighlightFilter : public ITemplateComponent
{
	public:
		QString render() override;
};

#endif // HIGHLIGHTFILTER_H
