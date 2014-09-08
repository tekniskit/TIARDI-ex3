#pragma once
#include "Event.h"
#include <string>

using namespace std;

class PatientEvent : public Event{
public:
	PatientEvent();
	~PatientEvent();

	string getValue();
	void setValue(string v);

	string getType();
	void setType(string t);

private:
	string value_;
	string type_;
};

