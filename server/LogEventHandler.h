#pragma once
#include "EventHandlerInterface.h"

class LogEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);

private:
	Event* parseEvent(Handle* handle);
};