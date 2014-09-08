#pragma once
#include "IReactor.h"
#include "DemuxTable.h" 
#include "SynchronousEventDemultiplexerInterface.h"

class Reactor:IReactor
{

public:
	void registerHandler(EventHandler* handler, Event_Type type);
	void removeHandler(Event_Type type);
	void handleEvents(Time_Value* = 0);
	Reactor(SynchronousEventDemultiplexerInterface* _demultiplexer);

private:
	// variables 

	SynchronousEventDemultiplexerInterface* demultiplexer; 
	DemuxTable handlerTabel;


};