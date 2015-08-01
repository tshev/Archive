#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cctype>
#include <memory>
struct sleep {
	virtual void sleep_for(int val) = 0;
	virtual void operator()(int duration) {
		sleep_for(duration);
	}
};
struct sleep_for_seconds: sleep {
	void sleep_for(int val) {
		std::cout << "Seconds\n";
		std::this_thread::sleep_for(std::chrono::seconds(val));
	}
};

struct sleep_for_minutes: sleep {
	void sleep_for(int val) {

		std::cout << "Minutes\n";
		std::this_thread::sleep_for(std::chrono::minutes(val));
	}
};
std::map<std::string, std::unique_ptr<sleep> > durations;

bool valid_arguments(int argc, char *argv[]) {
			durations["minutes"] = std::unique_ptr<sleep>{ std::make_unique<sleep_for_minutes>(sleep_for_minutes()) };
			durations["seconds"] = std::unique_ptr<sleep>{ std::make_unique<sleep_for_seconds>(sleep_for_seconds()) };
std::cout << "Example of usage :\n"
							<< argv[0] << " " << "[minutes, seconds] DURATION_INT" << std::endl;

	if (argc < 3) {
				return false;
	}
	std::string current_duration = argv[1]; // boost::to_upper_copy(argv[1]);
	int duration = atoi(argv[2]);
	if (duration == 0) {
		return false;
	}
	if(current_duration != std::string("minutes") && current_duration != std::string("seconds")) 
		return false;
	return true;
}

int main(int argc, char *argv[]) {
	if (!valid_arguments(argc, argv)) {
		std::cout << "Bad input\n";
		return -1;
	}
	std::string current_duration = argv[1];
	int count_of_seconds = atoi(argv[2]);
	durations[current_duration]->operator()(count_of_seconds);
	//(*durations["minutes"])(10);
	system("shutdown now");
	return 0;
}
