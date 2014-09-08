#pragma once
#include "../framework/EventHandler.h"

class AlarmEventHandler : EventHandler
{
public:
	void handleEvent(Handle* handle);
private:
	Event* parseEvent(Handle* handle);
};