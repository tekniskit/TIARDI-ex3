#pragma once
#include <string>

class Handle {
public:
	virtual void send(std::string data) = 0;
	virtual std::string receive() = 0;
};