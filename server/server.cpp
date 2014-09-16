// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynchronousEventDemultiplexerSock.h"
#include "SynchronousEventDemultiplexerInterface.h"
#include "PatientEventHandler.h"
#include "AlarmEventHandler.h"
#include "LogEventHandler.h"
#include "Reactor.h"
#include "INET_Addr.h"


int _tmain(int argc, _TCHAR* argv[])
{
	AlarmEventHandler *alarmEventHandler= new AlarmEventHandler();
	PatientEventHandler *patientEventHandler = new PatientEventHandler();
	LogEventHandler *logEventHandler = new LogEventHandler();

	INET_Addr addr(5500,NULL); 

	SynchronousEventDemultiplexerSock *stub = new SynchronousEventDemultiplexerSock(;

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

