#include "DemuxTable.h"


DemuxTable::DemuxTable(){
	// Init anything?
}
DemuxTable::~DemuxTable(){
	table_.clear();
}

EventHandler* DemuxTable::getHandler(unsigned int eventType){
	EventHandler* eventHandler = table_[eventType];
	if (eventHandler != NULL)
	{
		return eventHandler;
	}
	else
	{
		return nullptr;
	}
}
void DemuxTable::addHandler(unsigned int eventType, EventHandler* eventHandler){
	table_.insert(std::make_pair(eventType, eventHandler));
}

void DemuxTable::removeHandler(unsigned int eventType){
	table_.erase(eventType);
}