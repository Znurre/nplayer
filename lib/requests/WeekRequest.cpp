#include "WeekRequest.h"
#include "RequestInvocationContext.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"

#include "entities/User.h"
#include "entities/UserPeriod.h"

QString WeekRequest::trigger() const
{
	return ".week";
}

QString WeekRequest::period() const
{
	return "7day";
}
