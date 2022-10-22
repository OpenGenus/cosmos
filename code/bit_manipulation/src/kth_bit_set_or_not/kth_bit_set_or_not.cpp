// Problem link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1?page=1&category[]=Bit%20Magic&sortBy=submissions

//Method 1:using bit manipulation

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
       if(n&(1<<(k)))  //or we can shift bits of the numbers to the right
       return true ; //if kth bit is set then it will return true else it will execute next line.
       else return false;
    }
};