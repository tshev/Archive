#include <thread>
#include <chrono>
#include <cstdlib>

void shutdown(int delay) {
	std::this_thread::sleep_for(std::chrono::minutes(delay));
	system("shutdown down");
}

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	double minutes = atof(argv[1]);
	shutdown(minutes);
	return 0;
}
