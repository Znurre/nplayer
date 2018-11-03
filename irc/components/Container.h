#ifndef CONTAINER_H
#define CONTAINER_H

#include "ITemplateComponent.h"

class Container : public ITemplateComponent
{
	public:
		QString render() override;
};

#endif // CONTAINER_H
