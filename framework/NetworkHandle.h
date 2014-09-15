#pragma once 
#include "Handle.h"
#include "SOCK_Stream.h"

class NetworkHandle : public Handle {
public:

	NetworkHandle();

	NetworkHandle(SOCK_Stream* stream_);

	void send(std::string data_);

	void setData(std::string data_);

	std::string receive();

private:
	SOCK_Stream* stream = nullptr;
	std::string data; 
	
};

