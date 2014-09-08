#include "SOCK_Stream.h"

SOCK_Stream::~SOCK_Stream(){
	close();
}

void SOCK_Stream::set_handle(SOCKET h)
{
	handle_ = h;
}

SOCKET SOCK_Stream::get_handle() const
{
	return handle_;
}

//Regular I/O operations
int	SOCK_Stream::recv(char *buf, size_t len, int flags){
	int iResult = _WINSOCKAPI_::recv(handle_, buf, len, flags);
	if (iResult == SOCKET_ERROR) {
		closesocket(handle_);
		WSACleanup();
		return 0;
	}
	return iResult;
}

int SOCK_Stream::send(const char *buf, size_t len, int flags){

	int iResult = _WINSOCKAPI_::send(handle_, buf, (int)len, flags);
	if (iResult == SOCKET_ERROR) {
		closesocket(handle_);
		WSACleanup();
		return 0;
	}

	return iResult;
}

void SOCK_Stream::close(){
	int iResult = closesocket(handle_);
	if (iResult == SOCKET_ERROR) {

		WSACleanup();
	}
}