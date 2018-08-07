#include <iostream>
#include <thread>
#include <vector>

void routine(int value) {
	std::chrono::milliseconds timespan(value);
	std::this_thread::sleep_for(timespan);
	std::cout << value << "\n";
}

int main(int argc, char *argv[]) {
	std::vector<int> arr = {12, 23, 42, 3};
	std::vector<std::thread> threads;
	for (int value : arr) {
		threads.push_back(std::thread(routine, value));
	}
	for (auto& thread : threads) {
		thread.join();
	}
	return 0;
}
