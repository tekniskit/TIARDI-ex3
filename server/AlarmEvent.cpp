#include "AlarmEvent.h"





string AlarmEvent::getPriority(){
	return priority_;
}

void AlarmEvent::setPriority(string i){
	priority_ = i;
}

string AlarmEvent::getComment(){
	return comment_;
}

void AlarmEvent::setComment(string c){
	comment_ = c;
}