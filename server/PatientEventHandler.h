#pragma once
#include "EventHandlerInterface.h"
#include "Handle.h"

class PatientEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);
private:
	Event* parseEvent(Handle* handle);
};