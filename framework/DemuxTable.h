#pragma once
#include <map>
#include "EventHandler.h"

using namespace std;

class DemuxTable{
public:
	DemuxTable();
	~DemuxTable();
	EventHandler* getHandler(unsigned int eventType);
	void addHandler(unsigned int eventType, EventHandler* eventHandler);
	void removeHandler(unsigned int eventType);	

private:
	map<unsigned int, EventHandler*> table_;
};