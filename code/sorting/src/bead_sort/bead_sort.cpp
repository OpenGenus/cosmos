#include <vector>
#include <algorithm>
#include <iostream>

#define BEAD(i, j) beads[i * max + j]

// Part of Cosmos by OpenGenus Foundation
// function to perform the above algorithm
void beadSort(std::vector<int>& Vector)
{
    // Finding the maximum element.
    const int max = *std::max_element(Vector.begin(), Vector.end());
    const size_t VectorSize = Vector.size();

    // allocating memory
    std::vector<unsigned char> beads(max * VectorSize, 0);

    // mark the beads
    for (size_t rowIndex = 0; rowIndex < VectorSize; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < Vector[rowIndex]; ++columnIndex) {
        BEAD(rowIndex, columnIndex) = 1;
      }
    }

    // mark the beads
    for (size_t rowIndex = 0; rowIndex < VectorSize; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < Vector[rowIndex]; ++columnIndex) {
        BEAD(rowIndex, columnIndex) = 1;
      }
    }

    for (int columnIndex = 0; columnIndex < max; ++columnIndex)
    {
      // count how many beads are on each post/column
      int sum = 0;
      for (size_t rowIndex = 0; rowIndex < VectorSize; ++rowIndex)
      {
        sum += BEAD(rowIndex, columnIndex);
        BEAD(rowIndex, columnIndex) = 0;
      }

      // Move beads down
      for (size_t rowIndex = VectorSize - sum; rowIndex < VectorSize; ++rowIndex)
        BEAD(rowIndex, columnIndex) = 1;
    }

    // Put sorted values in array using beads
    for (size_t rowIndex = 0; rowIndex < VectorSize; ++rowIndex)
    {
        int beadCountInRow;
        //Counting the number of beads present in the row.
        for (beadCountInRow = 0; beadCountInRow < max && BEAD(rowIndex, beadCountInRow); ++beadCountInRow)
            ;

        Vector[rowIndex] = beadCountInRow;
    }
}

// driver function to test the algorithm
int main(int argc, char** argv)
{
  std::vector<int> testVector{5, 3, 1, 7, 4, 1, 1, 20};

  //The user can give his own values, if he/she wants, in the argument.
  if(argc > 1) {
    testVector.clear();
    for(int argIndex = 1; argIndex < argc; ++argIndex)
      testVector.push_back(std::stoi(argv[argIndex]));
  }

  std::cout << "\nBefore Sorting.. " << std::endl;

  for(const auto& element : testVector) {
    std::cout << element << " ";
  }

  beadSort(testVector);

  std::cout << "\n\nAfter Sorting.. " << std::endl;

  for(const auto& element : testVector) {
    std::cout << element << " ";
  }

  std::cout<<std::endl;

  return 0;
}
