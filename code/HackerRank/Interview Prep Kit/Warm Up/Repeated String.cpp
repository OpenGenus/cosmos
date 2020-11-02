#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long l=s.length();
    long c=0;
        for(long i=0;i<l;i++)
        {
            if(s[i]=='a')
            c++;
        }
        c=c*(n/l);
        for(long i=0;i<n%l;i++)
        {
            if(s[i]=='a')
            c++;
        }
        return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
