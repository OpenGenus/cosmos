#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
int limit;
int N;
int counter;
void Backtracking(int position, int left, int right, int depth)
{
    if (depth == N)
    {
        counter++;
        return;
    }
    int currentPos = position | left | right;
    int newPos;
    while (currentPos < limit)
    {
        newPos = (currentPos + 1) & ~currentPos;
        Backtracking( position | newPos, limit & ((left | newPos) << 1),
                      limit & ((right | newPos) >> 1), depth + 1);
        currentPos = currentPos | newPos;
    }
}

int main()
{
    cout << "Please Enter the size of board" << endl;
    cin >> N;
    counter = 0;
    limit = (1 << (N)) - 1;
    Backtracking(0, 0, 0, 0);
    cout << "There are " << counter << " ways" << endl;
}
