#include "HandleSock.h"

HandleSock::HandleSock(){}

HandleSock::HandleSock(std::string data){
	data_ = data;
}

void HandleSock::send(std::string data) {
	stream_->send(data.c_str(), data.length(), 0);
}

std::string HandleSock::receive() {
	char response[100];
	stream_->recv(response, 50, 0);
	return response;
}

void HandleSock::setSock(SOCK_Stream* stream){
	stream_ = stream;
}