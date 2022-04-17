#include "PromoteEvent.h"
bool PromoteEvent::setEm(double e)		//sets the extra money for promotion
{
	if (e >= 0)
	{
		Em = e; return 1;
	}
	return 0;
}

double PromoteEvent::getEm() const		//gets the extra money for promotion
{
	return Em;
}