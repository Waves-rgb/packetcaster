#include "net/net.h"
#include <fmt/format.h>

bool serving = false;
int port = 5454;
const char* ip = nullptr;

// ./packetcaster [-s, --server] <ip>
int main(const int argc, const char** argv) {
	fmt::print("Initializing network...\n");
	if (net::init() != 0) {
		fmt::print("Failed to initialize network!\n");
		return 1;
	}

	// check if we are a server or a client, assume client if no arguments
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--server") == 0) {
			serving = true;
		} else {
			ip = argv[i];
		}
	}

	fmt::print("Starting in {} mode...\n", serving ? "server" : "client");

	return 0;
}
