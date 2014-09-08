#include <iostream>
#include "HandleStub.h"

HandleStub::HandleStub(std::string data) {
	data_ = data;
}

void HandleStub::send(std::string data) {
	std::cout << "HandleStub: " << data << std::endl;

}

std::string HandleStub::receive() {
	return data_;
}