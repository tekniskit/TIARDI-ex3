#include "WriteEventHandler.h"
void WriteEventHandler::handleEvent(Handle* handle){
	counter_++;

	if (counter_ == 1) {
		handle->send("1;TEXT to log!"); // TODO: Make class with serializer
	}

	if (counter_ == 2) {
		// Alarm: Expected protocol "id;comment;priority"
		handle->send("2; Alarm comment; HIGH priority"); // TODO: Make class with serializer
	}

	if (counter_ == 3) {
		// Patient
		handle->send("3;dame;Kirsten"); // TODO: Make class with serializer
		counter_ = 0;
	}
}