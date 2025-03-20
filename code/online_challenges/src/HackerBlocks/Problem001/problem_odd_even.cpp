    /* Problem: Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi. The scheme is as follows, each car will be allowed to run on Sunday if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. However to check every car for the above criteria can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car numbered N will be allowed to run on Sunday?
    */

    // Input : The first line contains N , then N integers follow each denoting the number of the car.

    // Output: N lines each denoting "Yes" or "No" depending upon whether that car will be allowed on Sunday or Not !

    /*
    Sample Input:
    2
    12345
    12134

    Sample Output:
    Yes
    No
    */


    #include<iostream>

    using namespace std;
    int main() {

        int n;
        cin>>n;

        long long number;


        while(n>0)
        {
            int even_sum = 0;
            int odd_sum = 0;
            cin>>number;
            while(number != 0)
            {
                int p = number%10;

                if(p % 2 == 0)
                {
                    even_sum += p;
                }
                else
                {
                    odd_sum += p;
                }

                number = number/10;


            }
            if((even_sum % 4 == 0) || (odd_sum % 3 == 0))
            {
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            n--;
        }

        return 0;
    }