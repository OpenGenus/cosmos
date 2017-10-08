#include<iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
//Pre Condition n should not be equal to 0 
int gcd(int m,int n){
  if(m%n==0){
    return n;}
   return gcd(n,m%n):
}
bool coPrime(int m,int n){
   if(m<n){
    m=m+n-(n=m);}
    if(gcd(m,n)==1){
    return true;}
   return false;
}
int main(){
 int m,n;
 cout<<"Please Enter Two Integers";
cin>>m>>n;
if(coPrime(m,n)){
cout<<"The given integers are CoPrime Interger";}
else{
cout<<"The given integers are not CoPrime Integers";}

return 0;
}

 
