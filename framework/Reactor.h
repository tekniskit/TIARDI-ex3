#pragma once
#include "IReactor.h"
#include "DemuxTable.h" 
#include "SynchronousEventDemultiplexer.h"

class Reactor:IReactor
{

public:
	void registerHandler(EventHandler* handler, Event_Type type);
	void removeHandler(Event_Type type);
	void handleEvents(Time_Value* = 0);
	Reactor(SynchronousEventDemultiplexer* _demultiplexer);

private:
	// variables 

	SynchronousEventDemultiplexer* demultiplexer; 
	DemuxTable handlerTabel;


};