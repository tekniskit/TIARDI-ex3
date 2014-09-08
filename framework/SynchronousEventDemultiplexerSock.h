#pragma once
#include "SynchronousEventDemultiplexerInterface.h"

class SynchronousEventDemultiplexerSock : public SynchronousEventDemultiplexerInterface {
public:
	NetworkEvent getNetworkEvent();
};