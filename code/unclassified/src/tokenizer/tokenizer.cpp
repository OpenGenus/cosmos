#include <iostream>
#include <cstring>
// Part of Cosmos by OpenGenus Foundation

using namespace std;

char *myStrTok(char *input, char delim)
{

    static char* ptr;
    if (input != nullptr)
        ptr = input;
    if (ptr == nullptr)
        return nullptr;

    char* output = new char[strlen(ptr) + 1]; //1 for '\0'

    int i;
    for (i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == delim)
        {

            output[i] = '\0';

            // for the case that the delimiter occurs multiple times.
            while (ptr[i] == delim)
                i++;

            ptr = ptr + i;
            return output;
        }
        output[i] = ptr[i];
    }
    output[i] = '\0'; //for last when delim is not found
    ptr = nullptr;
    return output;
}


int main()
{
    char in[] = "Hello   this is a string tokenizer!";

    char *ans = myStrTok(in, ' ');

    while (ans != nullptr)
    {
        cout << ans << endl;
        ans = myStrTok(nullptr, ' ');
    }
    char arr[] = "Hello world!";
    ans = myStrTok(arr, ' ');
    cout << endl << ans << endl;
    ans = myStrTok(nullptr, ' ');
    cout << endl << ans << endl;

    delete ans;

    return 0;
}
