// Part of Cosmos by OpenGenus
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
int i,sum=0,count;

for(i=0;i<n;i++)
{
    if(s[i]=='U')
    
    {
        sum+=1;
        if(sum==0)
        count++;
        }
    else {
    sum-=1;
    }
}
return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
