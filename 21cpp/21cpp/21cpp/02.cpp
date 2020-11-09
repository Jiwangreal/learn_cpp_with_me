#include "Television.h"
#include "TeleController.h"
#include <iostream>
using namespace std;


int main(void)
{
	Television tv(1, 1);

	TeleController tc;
	tc.VolumeUp(tv);

	return 0;
}