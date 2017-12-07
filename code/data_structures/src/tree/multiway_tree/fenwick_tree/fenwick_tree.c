#include<stdio.h>
// Part of Cosmos by OpenGenus Foundation
int getSum(int bit_tree[], int index)
{
    int sum = 0; // Iniialize result

    // index in bit_tree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of bit_tree[index]
    while (index>0)
    {
        // Add current element of bit_tree to sum
        sum += bit_tree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void update(int bit_tree[], int n, int index, int val){
    // index in bit_tree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while(index <=n){
        // Add 'val' to current node of BI Tree
       bit_tree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
    return;
}

void constructBITtree(int arr[], int bit_tree[], int n){
    //initialise bit_tree to 0
    for(int i=1;i<=n;i++)
        bit_tree[i] =   0;

    //store value in bit_tree usin update
    for(int i=0;i<n;i++)
        update(bit_tree, n, i, arr[i]);

    return;
}

int main(){
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n =sizeof(freq)/sizeof(freq[0]);
    int bit_tree[n+1];

    constructBITtree(freq, bit_tree, n);

    printf("Sum of elements in arr[0..5] is %d\n",getSum(bit_tree, 5));

    // Let use test the update operation
    freq[3] += 6;
    update(bit_tree, n, 3, 6); //Update BIT for above change in arr[]

    printf("Sum of elements in arr[0..5] after the update is %d\n",getSum(bit_tree, 5));
    return 0;
}

