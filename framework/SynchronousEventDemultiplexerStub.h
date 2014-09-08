#pragma once
#include "SynchronousEventDemultiplexerInterface.h"
#include "HandleStub.h"

class SynchronousEventDemultiplexerStub : public SynchronousEventDemultiplexerInterface {
public:
	NetworkEvent getNetworkEvent();

private:
	unsigned int calledCounter_ = 0;
	HandleStub handle_;
};