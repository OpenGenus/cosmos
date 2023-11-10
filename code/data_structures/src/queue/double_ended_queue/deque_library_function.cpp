#include <iostream>
#include <deque>

using namespace std;

void showdq (deque <int> g)
{
    deque <int> :: iterator it;                                 // Iterator to iterate over the deque .

    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;

    cout << "\n";
}

int main ()
{
    deque <int> que;
    int option, x;
    do
    {


        cout << "\n\n DEQUEUE USING STL C++ ";
        cout << "\n 1.Insert front";
        cout << "\n 2.Insert Back";
        cout << "\n 3.Delete front";
        cout << "\n 4.Delete Back";
        cout << "\n 5.Display ";

        cout << "\n Enter your option : ";
        cin >> option;

        switch (option)
        {
        case 1: cout << "\n Enter number : ";
            cin >> x;
            que.push_front(x);
            break;

        case 2: cout << "\n Enter number : ";
            cin >> x;
            que.push_back(x);
            break;

        case 3: que.pop_front();
            break;

        case 4: que.pop_back();
            break;
        case 5: showdq(que);
            break;
        }
    } while (option != 6);

    return 0;
}
