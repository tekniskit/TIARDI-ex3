#include "Reactor.h"
#include "NetworkEvent.h"
#include "EventHandler.h"

void Reactor::registerHandler(EventHandler* handler, Event_Type type)
{
	handlerTabel.addHandler(type, handler);
}

void Reactor::removeHandler(Event_Type type)
{
	handlerTabel.removeHandler(type);
}


void Reactor::handleEvents(Time_Value* time)
{
	NetworkEvent event = demultiplexer->getNetworkEvent();
	EventHandler* handler = handlerTabel.getHandler(event.getEventType());

	if (handler != nullptr)
	{
		handler->handleEvent(event.getHandle()); 
	}
}

Reactor::Reactor(SynchronousEventDemultiplexerInterface* _demultiplexer)
{
	demultiplexer = _demultiplexer;
}