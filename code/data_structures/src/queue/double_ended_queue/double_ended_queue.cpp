#include <iostream>
using namespace std;
#define MAX 10

int deque[MAX];
int leftt = -1;
int rightt = -1;

void inputdeque(void);
void outputdeque(void);
void insertleft(void);
void insertright(void);
void deleteleft(void);
void deleteright(void);
void display(void);

int main( )
{
    int option;
    cout << "\n *****MAIN MENU*****";
    cout << "\n 1.Input restricted deque";
    cout << "\n 2.Output restricted deque";
    cout << "\n Enter your option : ";
    cin >> option;

    switch (option)
    {
    case 1:   inputdeque();
        break;
    case 2:   outputdeque();
        break;
    } return 0;
}

void inputdeque( )
{
    int option;
    do
    {
        cout << "\n\n INPUT RESTRICTED DEQUE";
        cout << "\n 1.Insert at right";
        cout << "\n 2.Delete from left";
        cout << "\n 3.Delete from right";
        cout << "\n 4.Display";
        cout << "\n 5.Quit";
        cout << "\n Enter your option : ";

        cin >> option;
        switch (option)
        {
        case 1:    insertright();
            break;
        case 2:    deleteleft();
            break;
        case 3:    deleteright();
            break;
        case 4:    display();
            break;
        }

    } while (option != 5);
}

void outputdeque( )
{
    int option;
    do
    {
        cout << "\n\n OUTPUT RESTRICTED DEQUE";
        cout << "\n 1.Insert at right";
        cout << "\n 2.Insert at left";
        cout << "\n 3.Delete from left";
        cout << "\n 4.Display";
        cout << "\n 5.Quit";
        cout << "\n Enter your option : ";

        cin >> option;
        switch (option)
        {
        case 1:    insertright();
            break;
        case 2:    insertleft();
            break;
        case 3:    deleteleft();
            break;
        case 4:    display();
            break;
        }
    } while (option != 5);
}

void insertright( )
{
    int val;
    cout << "\n Enter the value to be added:";
    cin >> val;
    if ( (leftt == 0 && rightt == MAX - 1 ) || (leftt == rightt + 1) )
    {
        cout << "\n OVERFLOW";
        return;
    }
    if (leftt == -1)                                                                    // Queue is Empty Inititally
    {
        leftt = 0;
        rightt = 0;
    }
    else
    {
        if (rightt == MAX - 1)                                                          //rightt is at last position of queue
            rightt = 0;
        else
            rightt = rightt + 1;
    }
    deque[rightt] = val;
}

void insertleft( )
{
    int val;
    cout << "\n Enter the value to be added:";
    cin >> val;

    if ( (leftt == 0 && rightt == MAX - 1) || (leftt == rightt + 1) )
    {
        cout << "\n OVERFLOW";
        return;
    }
    if (leftt == -1)                                                                                            //If queue is initially empty
    {
        leftt = 0;
        rightt = 0;
    }
    else
    {
        if (leftt == 0)
            leftt = MAX - 1;
        else
            leftt = leftt - 1;
    }
    deque[leftt] = val;
}

void deleteleft( )
{
    if (leftt == -1)
    {
        cout << "\n UNDERFLOW";
        return;
    }

    cout << "\n The deleted element is : " << deque[leftt];

    if (leftt == rightt)                                                                                /*Queue has only one element */
    {
        leftt = -1;
        rightt = -1;
    }
    else
    {
        if (leftt == MAX - 1)
            leftt = 0;
        else
            leftt = leftt + 1;
    }
}

void deleteright()
{
    if (leftt == -1)
    {
        cout << "\n UNDERFLOW";
        return;
    }

    cout << "\n The element deleted is : " << deque[rightt];

    if (leftt == rightt)                                                                                        /*queue has only one element*/
    {
        leftt = -1;
        rightt = -1;
    }
    else
    {
        if (rightt == 0)
            rightt = MAX - 1;
        else
            rightt = rightt - 1;
    }
}

void display( )
{
    int front = leftt, rear = rightt;
    if (front == -1)
    {
        cout << "\n QUEUE IS EMPTY";
        return;
    }
    cout << "\n The elements of the queue are : ";
    if (front <= rear)
        while (front <= rear)
        {
            cout << deque[front] << " ";
            front++;
        }
    else
    {
        while (front <= MAX - 1)
        {
            cout << deque[front] << " ";
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            cout << deque[front] << " ";
            front++;
        }
    }
    cout << endl;                                                                                       //NEW LINE
}
