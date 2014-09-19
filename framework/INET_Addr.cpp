#include "INET_Addr.h"

INET_Addr::INET_Addr(u_short port, u_long addr) {
	memset(&addr_, 0, sizeof addr_);
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_addr.s_addr = htonl(addr);
}

u_short INET_Addr::get_port() const{
	return addr_.sin_port;
}

u_long INET_Addr::get_ip_addr() const
{
	return addr_.sin_addr.s_addr;
}


sockaddr *INET_Addr::addr() const
{
	return reinterpret_cast <sockaddr *>(&addr_); // addr_ is mutable to allow this
}

size_t INET_Addr::size() const {
	return sizeof(addr_);
}