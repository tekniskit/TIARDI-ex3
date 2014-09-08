#pragma once
#include "EventHandler.h"
#include "Handle.h"

class PatientEventHandler : EventHandler
{
public:
	void handleEvent(Handle* handle);
private:
	Event* parseEvent(Handle* handle);
};