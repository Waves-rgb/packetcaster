#pragma once

// include windows sockets libraries if on windows
#ifdef _WIN32
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#pragma comment(lib, "ws2_32.lib")

	#define uniSocket SOCKET
#else
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <unistd.h>

	#define uniSocket int
#endif

namespace net {
	int init();
	int shutdown();

	uniSocket createSocket();
	int bindSocket(uniSocket socket, int port);
	int listenSocket(uniSocket socket);
	uniSocket acceptSocket(uniSocket socket);
	int connectSocket(uniSocket socket, const char* ip, int port);
	int sendSocket(uniSocket socket, const char* data, int size);
	int recvSocket(uniSocket socket, char* data, int size);
	int closeSocket(uniSocket socket);
}
