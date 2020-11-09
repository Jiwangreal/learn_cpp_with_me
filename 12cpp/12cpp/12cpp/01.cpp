#include "Clock.h"

int main(void)
{
	Clock c(10,10,10);
	c.Display();
	//c.second_ += 1;
	c.Update();
	c.Display();

	//c.hour_ = 11;
	c.SetHour(11);
	c.Display();

	return 0;
}