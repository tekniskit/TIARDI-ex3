#pragma once
#include "Event.h"
#include <string>

using namespace std;

class LogEvent : public Event{
public:
	LogEvent();
	~LogEvent();

	string getText();
	void setText(string t);
private:
	string text_;
};

