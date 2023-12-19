
#include "../../../net/net.h"

class Connection {
private:
	uniSocket socket;
public:
	explicit Connection(uniSocket sock) : socket(sock) {}
	~Connection() {
		net::closeSocket(socket);
	}
	uniSocket getSocket() const {
		return socket;
	}
};
