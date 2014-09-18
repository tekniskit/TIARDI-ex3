#pragma once
#include "EventHandlerInterface.h"
#include <iostream>

class WriteEventHandler : EventHandlerInterface
{
public:
	void handleEvent(Handle* handle);

private:
	int counter_ = 0;
};