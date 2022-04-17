#include "PromoteEvent.h"
PromoteEvent::PromoteEvent()
{

}
PromoteEvent::PromoteEvent(int id, int day, int hour, char Etype, double Em):Event(id,day,hour,Etype)
{
	setEm(Em);
}
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