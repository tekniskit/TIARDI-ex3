#include "DemuxTable.h"


DemuxTable::DemuxTable(){
	// Init anything?
}
DemuxTable::~DemuxTable(){
	table_.clear();
}

EventHandlerInterface* DemuxTable::getHandler(unsigned int eventType){
	EventHandlerInterface* EventHandlerInterface = table_[eventType];
	if (EventHandlerInterface != NULL)
	{
		return EventHandlerInterface;
	}
	else
	{
		return nullptr;
	}
}
void DemuxTable::addHandler(unsigned int eventType, EventHandlerInterface* EventHandlerInterface){
	table_.insert(std::make_pair(eventType, EventHandlerInterface));
}

void DemuxTable::removeHandler(unsigned int eventType){
	table_.erase(eventType);
}