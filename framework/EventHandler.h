#pragma once
#include "Handle.h"
#include "Event.h"

class EventHandler{
public:
	virtual void handleEvent(Handle* handle) = 0;
private:
	virtual Event* parseEvent(Handle* handle) = 0;
};