#pragma once
#include <winsock2.h>
#include "INET_Addr.h"
#include "SOCK_Stream.h"
#pragma comment(lib, "Ws2_32.lib")

class SOCK_Acceptor {
	public:
		SOCK_Acceptor (const INET_Addr &addr);
		void accept (SOCK_Stream &s);
		SOCKET* getSocket();

	private:
		SOCKET handle_;
};