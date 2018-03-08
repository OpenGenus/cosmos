#include <iostream>
#include <vector>
//prints input number of teerms of Newman-Conway Sequence
vector<int> NewmanConwaySequence(int number)
{
    std::vector<int> arr(number + 1);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= number; ++i)
        arr[i] = arr[arr[i - 1]] + arr[i - arr[i - 1]];
    return arr;
}

int main()
{
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;
    vector<int> sequence(number + 1);
    sequence = NewmanConwaySequence(number); 
    for(int i = 1; i <= number; ++i)
    	cout << sequence[i] << " ";
    return 0;
}