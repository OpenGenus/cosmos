#include <iostream>
#include <vector>

/* Part of Cosmos by OpenGenus Foundation */
void selection_sort(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		int minIndex = i;
		for (int j = i + 1; j < v.size(); j++) { // find ("select") the index of the element with the minimum value
			if (v[j] < v[minIndex]) minIndex = j;
		}
		std::swap(v[i], v[minIndex]); // put the found element at position i
	}
}

int main() {
	std::vector<int> v{1, 5, 2, 3, 4};
	selection_sort(v);
	for (auto num : v) {
		std::cout << num << " ";
	}
	return 0;
}