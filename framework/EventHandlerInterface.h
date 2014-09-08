#pragma once
#include "Handle.h"
#include "Event.h"

class EventHandlerInterface{
public:
	virtual void handleEvent(Handle* handle) = 0;
};