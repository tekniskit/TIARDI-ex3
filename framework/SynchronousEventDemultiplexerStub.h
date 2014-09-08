#pragma once
#include "SynchronousEventDemultiplexer.h"
#include "HandleStub.h"

class SynchronousEventDemultiplexerStub : public SynchronousEventDemultiplexer {
public:
	NetworkEvent getNetworkEvent();

private:
	unsigned int calledCounter_ = 0;
	HandleStub handle_;
};