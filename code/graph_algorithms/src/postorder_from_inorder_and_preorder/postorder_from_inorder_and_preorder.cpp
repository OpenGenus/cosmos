#include <iostream>
using namespace std;

int search(int in[], int k, int n)
{
    for (int i = 0; i < n; i++)
        if (in[i] == k)
            return i;

    return -1;

}

void postorder(int in[], int pre[], int n)
{
    int root = search(in, pre[0], n);

    if (root != 0)
        postorder(in, pre + 1, root);

    if (root != n - 1)
        postorder(in + root + 1, pre + root + 1, n - root - 1);

    cout << pre[0] << " ";

}

int main()
{
    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    postorder(in, pre, n);
    return 0;
}
