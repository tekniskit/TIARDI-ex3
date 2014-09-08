#pragma once
#include "../framework/EventHandlerInterface.h"

class AlarmEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);
private:
	Event* parseEvent(Handle* handle);
};