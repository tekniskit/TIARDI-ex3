#include "AlarmEventHandler.h"
#include "AlarmEvent.h"
#include <iostream>


using namespace std;

void AlarmEventHandler::handleEvent(Handle* handle)
{
	AlarmEvent* alarmEvent = static_cast<AlarmEvent*>(parseEvent(handle));
	std::cout << "Comment: " << alarmEvent->getComment() << "Priority: " << alarmEvent->getPriority() << '\n';
}

Event* AlarmEventHandler::parseEvent(Handle* handle)
{
	//Expected protocol "id;comment;priority"
	string input = handle->receive();

	std::string delimiter = ";";
	size_t pos = 0;
	std::string token;
	AlarmEvent *event = new AlarmEvent();
	int count = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		//type
		if (count == 1)
		{
			event->setComment(token);
		}

		std::cout << token << std::endl;
		input.erase(0, pos + delimiter.length());
		count++;
	}
	//value
	event->setPriority(input);

	return event;
	
}