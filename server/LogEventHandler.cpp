#include "LogEventHandler.h"
#include "LogEvent.h"
#include <iostream>

using namespace std;

void LogEventHandler::handleEvent(Handle* handle)
{
	LogEvent* logEvent = static_cast<LogEvent*>(parseEvent(handle));
	std::cout << "Text: " << logEvent->getText() << '\n';
}

Event* LogEventHandler::parseEvent(Handle* handle)
{
	//Expected protocol "id;text"
	string input = handle->receive();

	std::string delimiter = ";";
	size_t pos = 0;
	std::string token;
	LogEvent *event = new LogEvent();
	int count = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);		
		std::cout << token << std::endl;
		input.erase(0, pos + delimiter.length());
		count++;
	}
	//value
	event->setText(input);

	return event;

}
