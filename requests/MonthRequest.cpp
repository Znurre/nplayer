#include "MonthRequest.h"

QString MonthRequest::trigger() const
{
	return ".month";
}

QString MonthRequest::period() const
{
	return "1month";
}
