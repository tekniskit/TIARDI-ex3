#pragma once
#include "SynchronousEventDemultiplexerInterface.h"
#include "HandleSock.h"

class SynchronousEventDemultiplexerClient : public SynchronousEventDemultiplexerInterface {
public:
	SynchronousEventDemultiplexerClient(SOCK_Stream* stream);
	NetworkEvent getNetworkEvent();

private:		
	SOCK_Stream *stream_;
};