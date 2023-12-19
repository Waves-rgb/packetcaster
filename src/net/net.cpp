#include "net.h"


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
	int init() {
		#ifdef _WIN32
			WSADATA wsaData;
			return WSAStartup(MAKEWORD(2, 2), &wsaData);
		#else
			// init is not needed on linux
			return 0;
		#endif
	}

	int shutdown() {
		#ifdef _WIN32
			return WSACleanup();
		#else
			// shutdown is not needed on linux
			return 0;
		#endif
	}

	uniSocket createSocket() {
		return socket(AF_INET, SOCK_STREAM, IPPROTO_UDP);
	}

	int bindSocket(uniSocket socket, int port) {
		sockaddr_in addr{};
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = INADDR_ANY;

		return bind(socket, (sockaddr*)&addr, sizeof(addr));
	}

	int listenSocket(uniSocket socket) {
		return listen(socket, SOMAXCONN);
	}

	uniSocket acceptSocket(uniSocket socket) {
		return accept(socket, nullptr, nullptr);
	}

	int connectSocket(uniSocket socket, const char* ip, int port) {
		sockaddr_in addr{};
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		inet_pton(AF_INET, ip, &addr.sin_addr);

		return connect(socket, (sockaddr*)&addr, sizeof(addr));
	}

	int sendSocket(uniSocket socket, const char* data, int size) {
		return send(socket, data, size, 0);
	}

	int recvSocket(uniSocket socket, char* data, int size) {
		return recv(socket, data, size, 0);
	}

	int closeSocket(uniSocket socket) {
		#ifdef _WIN32
			return closesocket(socket);
		#else
			return close(socket);
		#endif
	}
}
