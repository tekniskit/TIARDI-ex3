#pragma once
#include "Handle.h"
#include "SOCK_Stream.h"

class HandleSock : public Handle {
public:
	HandleSock();
	HandleSock(std::string data);

	void send(std::string data);
	std::string receive();

	void setSock(SOCK_Stream* stream);
private:
	std::string data_;
	SOCK_Stream *stream_;
};