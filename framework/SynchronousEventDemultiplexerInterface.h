#pragma once
#include "NetworkEvent.h"

class SynchronousEventDemultiplexerInterface {
public:
	virtual NetworkEvent getNetworkEvent() = 0;
};