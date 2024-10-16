// Program to show optimised segment tree operations like construction, sum query and update
#include <iostream>
using namespace std;

/*Parameters for understanding code easily:
N = size of the array for which we are making the segment tree
arr= Given array, it can be of any size
tree=Array for the segment tree representation*/

void createTreeOp(int *arr, int *tree, int size)
{
    // First the array elements are fixed in the tree array from N index to 2N-1 index
    for (int i = size; i < 2 * size; i++)
    {
        tree[i] = arr[i - size];
    }
    // Now tree elements are inserted by taking sum of nodes on children index from index N-1 to 1
    for (int i = size - 1; i > 0; i--)
    {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    // This approach only requires atmost 2N elements to make segment tree of N sized array
}

int sumOp(int *tree, int start, int end, int size)
{
    start += size;
    end += size;
    int sum = 0;

    /*Range is set [size+start,size+end] in the beginning. At
    each step range is moved up and the value do not belonging
    to higher range are added.*/
    while (start <= end)
    {
        if (start % 2 == 1)
        {
            sum += tree[start++];
        }
        if (end % 2 == 0)
        {
            sum += tree[end--];
        }
        start = start / 2;
        end = end / 2;
    }
    return sum;
}

void update(int *tree, int index, int size, int newVal)
{
    index = size + index;
    int incr = newVal - tree[index];
    // First calculate the increase in the value required in the element after the updating
    while (index >= 1)
    {
        tree[index] += incr;
        index = index / 2;
    }
    // Loop to increment the value incr in the path from root to required indexed leaf node
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *tree = new int[20];
    /* In this approach we only require 2N sized tree array for storing the segment
    tree and all the operations can be achieved in iterative methods.*/
    createTreeOp(arr, tree, 10);
    cout<<"SEGMENT TREE"<<endl;
    for (int i = 1; i < 20; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl<<endl;
    cout <<"The sum of the segment from index to 3 to 5 "<<sumOp(tree, 3, 5, 10)<<endl;
    update(tree, 0, 10, -1);
    cout <<"Updating the value at index 0 with -1"<<endl;
    cout<<endl<<"SEGMENT TREE"<<endl;
    for (int i = 1; i < 20; i++)
    {
        cout << tree[i] << " ";
    }
}

