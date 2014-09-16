// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynchronousEventDemultiplexerClient.h"
#include "INET_Addr.h"
#include "SOCK_Connector.h"
#include "Reactor.h"
#include "WriteEventHandler.h"

int _tmain(int argc, _TCHAR* argv[])
{
	 u_long ip = 0x7F000001; // 127.0.0.1
	u_short port = 5500;

	INET_Addr address(port, ip);
	SOCK_Connector client;
	SOCK_Stream stream;

	client.connect(address);
	stream.set_handle(client.getSocket());
	
	SynchronousEventDemultiplexerClient *demuxClient = new SynchronousEventDemultiplexerClient(&stream);
	Reactor reactor(demuxClient);
	WriteEventHandler *writeEventHandler = new WriteEventHandler();

	reactor.registerHandler((EventHandlerInterface*)writeEventHandler, 4); // 4 is write
	
	while (true)
	{
		 reactor.handleEvents();
	}

	return 0;
}

