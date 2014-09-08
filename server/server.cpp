// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynchronousEventDemultiplexerStub.h"
#include "SynchronousEventDemultiplexerInterface.h"
#include "PatientEventHandler.h"
#include "AlarmEventHandler.h"
#include "LogEventHandler.h"
#include "Reactor.h"


int _tmain(int argc, _TCHAR* argv[])
{
	AlarmEventHandler *alarmEventHandler= new AlarmEventHandler();
	PatientEventHandler *patientEventHandler = new PatientEventHandler();
	LogEventHandler *logEventHandler = new LogEventHandler();
	SynchronousEventDemultiplexerStub *stub = new SynchronousEventDemultiplexerStub();

	Reactor reactor(stub);
	reactor.registerHandler((EventHandlerInterface*)logEventHandler, 1);
	reactor.registerHandler((EventHandlerInterface*)alarmEventHandler, 2);
	reactor.registerHandler((EventHandlerInterface*)patientEventHandler, 3);
	while (true)
	{
		reactor.handleEvents();
	}
	
	return 0;
}

