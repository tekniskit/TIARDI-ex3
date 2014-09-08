#include "SynchronousEventDemultiplexerStub.h"
#include "HandleStub.h"

NetworkEvent SynchronousEventDemultiplexerStub::getNetworkEvent() {
	NetworkEvent networkEvent;
	_sleep(500);
	calledCounter_++;

	if (calledCounter_ == 1) {
		// Log: Expected protocol "id;text"
		handle_ = HandleStub("1;TEXT to log!");

		networkEvent.setEventType(1);
		networkEvent.setHandle((Handle*) &handle_);

		return networkEvent;
	}

	if (calledCounter_ == 2) {
		// Alarm: Expected protocol "id;comment;priority"
		handle_ = HandleStub("2;Alarm comment;HIGH priority");

		networkEvent.setEventType(2);
		networkEvent.setHandle((Handle*) &handle_);

		return networkEvent;
	}

	if (calledCounter_ == 3) {
		// Patient
		handle_ = HandleStub("3;dame;Kirsten");

		networkEvent.setEventType(3);
		networkEvent.setHandle((Handle*) &handle_);

		calledCounter_ = 0;

		return networkEvent;
	}
}