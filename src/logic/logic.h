#pragma once

#include "../net/net.h"

namespace logic {
	void execServer(uniSocket socket);
	void execClient(uniSocket socket, const char* ip);
}
