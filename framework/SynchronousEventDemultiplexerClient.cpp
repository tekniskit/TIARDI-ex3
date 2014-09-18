#include "SynchronousEventDemultiplexerClient.h"

SynchronousEventDemultiplexerClient::SynchronousEventDemultiplexerClient(SOCK_Stream* stream){
	stream_ = stream;
}

NetworkEvent SynchronousEventDemultiplexerClient::getNetworkEvent() {
	
	NetworkEvent networkEvent;
	
	struct timeval tv;
	// wait until either socket has data ready to be recv()d (timeout 10.5 secs)
	tv.tv_sec = 10;
	tv.tv_usec = 500000;

	fd_set writefds;
	FD_ZERO(&writefds);
	FD_SET(stream_->get_handle(), &writefds);

	int rv = select(stream_->get_handle() + 1, NULL, &writefds, NULL, &tv);

	if (rv == -1) {
		networkEvent.setEventType(0);
		return networkEvent;		
	}
	else if (rv == 0) {
		networkEvent.setEventType(0);
		return networkEvent;
	}

	//Create write Event 
	if (FD_ISSET(stream_->get_handle(), &writefds)) {
		networkEvent.setEventType(4);
		handle = NetworkHandle(stream_);
		networkEvent.setHandle(&handle);
		return networkEvent;
	}
	return networkEvent;
}