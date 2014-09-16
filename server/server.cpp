// server.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "SynchronousEventDemultiplexerSock.h"
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

	INET_Addr addr(5500, 0x7F000001); 

	Reactor reactor;
	SynchronousEventDemultiplexerSock *stub = new SynchronousEventDemultiplexerSock(addr, &reactor);
	reactor.setSynchronousEventDemultiplexer(stub); 
	
	reactor.registerHandler((EventHandlerInterface*)logEventHandler, 1);
	reactor.registerHandler((EventHandlerInterface*)alarmEventHandler, 2);
	reactor.registerHandler((EventHandlerInterface*)patientEventHandler, 3);

	while (true)
	{
		reactor.handleEvents();
	}
	
	return 0;
}

