#include "SOCK_Acceptor.h"
#include "INET_Addr.h"
#include "SOCK_Stream.h"
#include <winsock2.h>

// Initialize a passive-mode acceptor socket.
SOCK_Acceptor::SOCK_Acceptor(const INET_Addr &addr) {
	WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Create a local endpoint of communication.
	handle_ = socket(PF_INET, SOCK_STREAM, 0);

	// Associate address with endpoint.
	bind(handle_, addr.addr(), addr.size());

	// Make endpoint listen for connections.
	listen(handle_, 5);
}

// Accept a connection and initialize the <stream>.
void SOCK_Acceptor::accept(SOCK_Stream &s) {
	s.set_handle(_WINSOCKAPI_::accept(handle_, 0, 0));
}