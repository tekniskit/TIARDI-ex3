#pragma once 
#include <winsock2.h> 
#include "INET_Addr.h"

class SOCK_Connector{
	
public:

	SOCK_Connector(); 
	~SOCK_Connector();

	// connect to a socket; 
	bool connect(INET_Addr addr);

	SOCKET getSocket(); 

	bool isRunning = true; 

private:
	SOCKET socket_ = INVALID_SOCKET;
};