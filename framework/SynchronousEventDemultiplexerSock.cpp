#include "SynchronousEventDemultiplexerSock.h"

SynchronousEventDemultiplexerSock::SynchronousEventDemultiplexerSock(INET_Addr addr)
{
	acceptorPtr = new SOCK_Acceptor(addr);
}

SynchronousEventDemultiplexerSock::~SynchronousEventDemultiplexerSock()
{
	delete acceptorPtr; 
}

NetworkEvent SynchronousEventDemultiplexerSock::getNetworkEvent()
{
	struct timeval tv;

	// wait until either socket has data ready to be recv()d (timeout 10.5 secs)
	tv.tv_sec = 10;
	tv.tv_usec = 500000;
	int n = socketList.size() > 0 ? (*socketList.back)->get_handle() + 1 : acceptorPtr->getSocket() + 1;

	int rv = select(n, &readfds, &writefds, &Errorfds, &tv);

	if (rv == -1) {
		perror("select"); // error occurred in select()
	}
	else if (rv == 0) {
		printf("Timeout occurred!  No data after 10.5 seconds.\n");
	}
	else 
	{
		// one or both of the descriptors have data
		if (FD_ISSET(s1, &readfds)) {
			recv(s1, buf1, sizeof buf1, 0);
		}
		if (FD_ISSET(s2, &readfds)) {
			recv(s1, buf2, sizeof buf2, 0);
		}
	}

	
	return NetworkEvent(); // temp return
}

void SynchronousEventDemultiplexerSock::prepFdsSet()
{
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&Errorfds);

	FD_SET(*acceptorPtr->getSocket(), &readfds);

	for (std::list<SOCK_Stream*>::iterator it = socketList.begin(); it != socketList.end(); it++)
	{
		SOCK_Stream* value = *it;
		FD_SET(value->get_handle(), &readfds);
		FD_SET(value->get_handle(), &writefds);
		FD_SET(value->get_handle(), &Errorfds);
	}

}


// Handle AcceptEvents Events
void SynchronousEventDemultiplexerSock::handleEvent(Handle* handle)
{
	SOCK_Stream* stream = new SOCK_Stream();
	acceptorPtr->accept(*stream);
	socketList.push_back(stream);
}