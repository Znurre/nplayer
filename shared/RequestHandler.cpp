#include "RequestHandler.h"

RequestHandler::RequestHandler(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
	: m_objectFactory(informationResourceRepository, idGenerator)
{

}
