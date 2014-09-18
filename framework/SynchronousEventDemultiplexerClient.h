#pragma once
#include "SynchronousEventDemultiplexerInterface.h"
#include "NetworkHandle.h"
#include "HandleSock.h"

class SynchronousEventDemultiplexerClient : public SynchronousEventDemultiplexerInterface {
public:
	SynchronousEventDemultiplexerClient(SOCK_Stream* stream);
	NetworkEvent getNetworkEvent();

private:		
	SOCK_Stream *stream_; 
	NetworkHandle handle;
};