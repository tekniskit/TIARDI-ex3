#pragma once
#include "EventHandler.h"

class LogEventHandler : EventHandler
{
public:
	void handleEvent(Handle* handle);
private:
	Event* parseEvent(Handle* handle);
};