#include<iostream>
#include<string>
#include<vector>

unsigned long int hash1(std::string value, int size) {
	unsigned long int hash = 0;
	for (int i = 0; i < value.size(); i++) {
		hash += (int)value[i];
		hash = (hash * 7);
	}
	return hash % size;
}

unsigned long int hash2(std::string value, int size) {
	unsigned long int hash = 0;
	for (int i = 0; i < value.size(); i++) {
		hash += (int)value[i];
		hash = (hash + 3) * 31;
	}
	return hash % size;
}

unsigned long int hash3(std::string value, int size) {
	unsigned long int hash = 0;
	for (int i = 0; i < value.size(); i++) {
		hash += (int)value[i];
		hash = (hash + (int)value[0]) * hash;
	}
	return hash % size;
}

unsigned long int hash4(std::string value, int size) {
	unsigned long int hash = 0;
	for (int i = 0; i < value.size(); i++) {
		hash += (int)value[i];
		hash = (hash + 2) * (hash + 5);
	}
	return hash % size;
}

void insert(int* filter, int arrSize, std::string value) {
	std::cout << value << std::endl;
	int i1 = hash1(value, arrSize);
	int i2 = hash2(value, arrSize);
	int i3 = hash3(value, arrSize);
	int i4 = hash4(value, arrSize);
	std::cout << i1 << " " << i2 << " " << i3 << " " << i4 << std::endl;

	if (filter[i1] == 1 && filter[i2] == 1 && filter[i3] == 1 && filter[i4] == 1) {
		std::cout << value << " is probably in here!" << std::endl;;
	}
	else {
		filter[i1] = 1;
		filter[i2] = 1;
		filter[i3] = 1;
		filter[i4] = 1;
		std::cout << value << " has been inserted!" << std::endl;
	}
}

int main() {
	int bloomFilter[200] = { 0 };
	int arrSize = 200;
	std::vector<std::string> values = { "test", "test", "maxed", "dragon", "pleats", "future", "dynamite", "waxing", "waning", "categorical", "astronomical", "absurdist" };
	for (int i = 0; i < values.size(); i++) {
		insert(bloomFilter, arrSize, values[i]);
	}
	return 0;
}