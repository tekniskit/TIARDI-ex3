#include "LogEvent.h"


LogEvent::LogEvent()
{
}


LogEvent::~LogEvent()
{
}

string LogEvent::getText(){
	return text_;
}

void LogEvent::setText(string t){
	text_ = t;
}
