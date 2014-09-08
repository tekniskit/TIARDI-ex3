// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynchronousEventDemultiplexerStub.h"
#include "SynchronousEventDemultiplexer.h"
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
	reactor.registerHandler((EventHandler*)logEventHandler, 1);
	reactor.registerHandler((EventHandler*)alarmEventHandler, 2);
	reactor.registerHandler((EventHandler*)patientEventHandler, 3);
	while (true)
	{
		reactor.handleEvents();
	}
	
	return 0;
}

