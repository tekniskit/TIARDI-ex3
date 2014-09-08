#pragma once
#include <winsock2.h>
#include "INET_Addr.h"
#include "SOCK_Stream.h"

class SOCK_Acceptor {
	public:
		SOCK_Acceptor (const INET_Addr &addr);
		void accept (SOCK_Stream &s);

	private:
		SOCKET handle_;
};