#include "PatientEvent.h"


PatientEvent::PatientEvent()
{
}


PatientEvent::~PatientEvent()
{
}


string PatientEvent::getValue(){
	return value_;
}

void PatientEvent::setValue(string v){
	value_ = v;
}

string PatientEvent::getType(){
	return type_;
}

void PatientEvent::setType(string t){
	type_ = t;
}