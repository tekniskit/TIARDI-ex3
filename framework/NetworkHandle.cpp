#include "NetworkHandle.h"

NetworkHandle::NetworkHandle()
{
	stream = nullptr;
}

NetworkHandle::NetworkHandle(SOCK_Stream* stream_)
{
	stream = stream_;
}

void NetworkHandle::send(std::string data_)
{
	if (stream != nullptr)
		stream->send(data.c_str(), data.length() + 1, 0);
}

void NetworkHandle::setData(std::string data_)
{
	data = data_;
}

std::string NetworkHandle::receive()
{
	return data;
}