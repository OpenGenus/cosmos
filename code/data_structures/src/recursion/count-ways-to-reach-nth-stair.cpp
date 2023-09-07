/* 
Question
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.
*/

#include<iostream>
using namespace std;

int noOfWays(int n){
    //base case
    if(n<0)
        return 0;
    if(n == 0)
        return 1;

    //recursive realtion
    return noOfWays(n-1)+noOfWays(n-2);
}

int main(){
    int n;  cin>>n;
    cout<<noOfWays(n)<<endl;
 return 0;
}