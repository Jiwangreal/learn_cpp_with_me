#include "TeleController.h"
#include "Television.h"

void TeleController::VolumeUp(Television& tv)
{
	tv.volume_ += 1;
}

void TeleController::VolumeDown(Television& tv)
{
	tv.volume_ -= 1;
}

void TeleController::ChanelUp(Television& tv)
{
	tv.chanel_ += 1;
}

void TeleController::ChanelDown(Television& tv)
{
	tv.volume_ -= 1;
}