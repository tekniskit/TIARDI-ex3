#pragma once 
#include <winsock2.h>

class INET_Addr {
public:
	INET_Addr(u_short port, u_long addr);
	u_short get_port() const;
	u_long get_ip_addr() const;
	sockaddr *addr() const;
	size_t size() const;
		
private:
	mutable sockaddr_in addr_; // Mutable needed for addr() method to compile
	
	friend class SOCK_Connector;
};