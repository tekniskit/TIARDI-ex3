#pragma once
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

class SOCK_Stream {
public:
	//Default and copy construcotr
	SOCK_Stream() : handle_(INVALID_SOCKET){} // Changed to INVALID_SOCKET insted of the book's INVALID_HANDLE_VALUE
	SOCK_Stream(SOCKET h) : handle_(h){}

	//Automatically close the handle on destruction.
	~SOCK_Stream();

	//Set/get the underlying SOCKET handle.
	void set_handle(SOCKET h);
	SOCKET get_handle() const;

	//Regular I/O operations
	int	recv(char *buf, size_t len, int flags);
	int send(const char *buf, size_t len, int flags);

private:
	//Socket handle for exchanging socket data.
	SOCKET handle_;
	void close();
};