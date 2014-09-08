#pragma once
#include <string>
#include "Handle.h"

class HandleStub : Handle {
public:
	HandleStub(){};
	HandleStub(std::string data);

	void send(std::string data);
	std::string receive();

private:
	std::string data_;
};