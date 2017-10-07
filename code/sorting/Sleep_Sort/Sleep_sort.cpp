#include <unistd.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int i;
	for (i = 1; i < argc; i++) {
		if (fork() != 0) {
			break;
		}
	}
	int value = std::stoi(argv[i]);
	sleep(value);
	std::cout << value << "\n";
	wait(0);
	return 0;
}
