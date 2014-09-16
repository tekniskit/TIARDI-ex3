#pragma once
#include "EventHandlerInterface.h"

class WriteEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);

private:
	int counter_;
};