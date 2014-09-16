#include "SynchronousEventDemultiplexerClient.h"

SynchronousEventDemultiplexerClient::SynchronousEventDemultiplexerClient(SOCK_Stream* stream){
	stream_ = stream;
}

NetworkEvent SynchronousEventDemultiplexerClient::getNetworkEvent() {
	NetworkEvent networkEvent;
	_sleep(500);

	// SELECT

	//HandleSock sock;
	//sock.setSock(stream_);
	//networkEvent.setHandle((Handle*)&sock);
	return networkEvent;
}