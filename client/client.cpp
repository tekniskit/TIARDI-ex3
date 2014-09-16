// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SynchronousEventDemultiplexerClient.h"


int _tmain(int argc, _TCHAR* argv[])
{
	long ip = 0x7F000001; // 127.0.0.1
	u_short port = 5500;

	//INET_Addr address(port, ip);

	//SOCK_Connector client;
	//SOCK_Stream stream;

	//client.connect(address);
	//stream.set_handle(client.getSocket());
	//
	//SynchronousEventDemultiplexerClient *demux = new SynchronousEventDemultiplexerClient(&stream);

	// var writeEventHandler = ...

	// Reactor reactor(demux);
	//reactor.registerHandler((EventHandler*)writeEventHandler, 5); // 5 is write
	
	//while (true)
	//{
		// reactor.handleEvents();
	//}

	return 0;
}

