#pragma once
#include "Event.h"
#include <string>

using namespace std;

class AlarmEvent : public Event {
public:
	string getPriority();
	void setPriority(string i);

	string getComment();
	void setComment(string c);

private:
	string priority_;
	string comment_;
};
