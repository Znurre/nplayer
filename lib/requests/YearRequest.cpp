#include "YearRequest.h"

QString YearRequest::trigger() const
{
	return ".year";
}

QString YearRequest::period() const
{
	return "12month";
}
