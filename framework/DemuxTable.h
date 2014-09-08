#pragma once
#include <map>
#include "EventHandlerInterface.h"

using namespace std;

class DemuxTable{
public:
	DemuxTable();
	~DemuxTable();
	EventHandlerInterface* getHandler(unsigned int eventType);
	void addHandler(unsigned int eventType, EventHandlerInterface* EventHandlerInterface);
	void removeHandler(unsigned int eventType);	

private:
	map<unsigned int, EventHandlerInterface*> table_;
};