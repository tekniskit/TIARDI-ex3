#include "PatientEventHandler.h"
#include "PatientEvent.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

void PatientEventHandler::handleEvent(Handle* handle)
{
	PatientEvent* patientEvent = static_cast<PatientEvent*>(parseEvent(handle));
	std::cout << "Type: " << patientEvent->getType() << " Value: " << patientEvent->getValue() << '\n';
}

Event* PatientEventHandler::parseEvent(Handle* handle)
{
	//Expected protocol "id;type;value"
	string input = handle->receive();

	std::string delimiter = ";";
	size_t pos = 0;
	std::string token;
	PatientEvent *event = new PatientEvent();
	int count = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		//type
		if (count == 1)
		{
			event->setType(token);
		}

		std::cout << token << std::endl;
		input.erase(0, pos + delimiter.length());
		count++;
	}
	//value
	event->setValue(input);

	return event;
}