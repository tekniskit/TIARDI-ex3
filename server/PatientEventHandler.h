#pragma once
#include "EventHandlerInterface.h"

class PatientEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);

private:
	Event* parseEvent(Handle* handle);
};