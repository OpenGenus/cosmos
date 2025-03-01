#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

typedef unsigned long long int ulli;

vector<ulli> collatz(ulli number){

        vector<ulli> seq;

        while(number > 1){

                if( number%2 == 1 ){
                      number = (3*number) + 1;
                      seq.push_back(number);
                }
                else{
                      number = number/2;
                      seq.push_back(number);
                }

        }

        return seq;
}


void printsequence(vector<ulli> &seq){

      for(int i = 0;i < seq.size();i++){
            cout<<seq[i]<<" ";
      }
      cout<<endl;

}
int main(){

        ios_base::sync_with_stdio(false);

        ulli number;
        cout<<"Enter the number for which collatz sequence is to be displayed : ";
        cin>>number;

        vector<ulli> sequence;
        sequence = collatz(number);

        printsequence(sequence);

        return 0;
}
