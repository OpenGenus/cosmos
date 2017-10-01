#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arraySize;
    cin>>arraySize;
    
    //Array to store input numbers
    vector<int> inputArray(arraySize);
    for(int i=0;i<arraySize;i++)
    {
        cin>>inputArray[i];
    }

    //Bubble Sort
    for(int i=0;i<arraySize-1;i++)
    {
        for(int j=0;j<arraySize-i-1;j++)
        {
            if(inputArray[j]>inputArray[j+1])
            {
                swap(inputArray[j],inputArray[j+1]);
            }


        }
    }

    //Printing the array
    for(int i=0;i<arraySize;i++)
    {
        cout<<inputArray[i]<<" ";
    }
    cout<<endl;
    return 0;
}
