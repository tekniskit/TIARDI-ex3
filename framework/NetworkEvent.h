#pragma once
#include "Handle.h"

class NetworkEvent {
public:
	Handle* getHandle();
	void setHandle(Handle* h);
	
	unsigned int getEventType();
	void setEventType(unsigned int eventType);

private:
	Handle* handle_;
	unsigned int eventType_;
};