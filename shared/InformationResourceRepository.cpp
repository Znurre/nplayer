#include "InformationResourceRepository.h"
#include "IInformationResource.h"

InformationResourceRepository::InformationResourceRepository()
{

}

void InformationResourceRepository::add(IInformationResource *resource)
{
	const QString &id = resource->id();

	m_resources[id] = resource;
}
