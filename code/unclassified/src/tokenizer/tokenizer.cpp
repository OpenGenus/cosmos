#include <iostream>
#include <string>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

string myStrTok(char *input, char delim)
{
    static char* ptr;
    if (input != nullptr)
        ptr = input;
    if (ptr == nullptr)
        return "";

    string output = "";

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
        output += ptr[i];
    }
    ptr = nullptr;
    return output;
}


int main()
{
    char in[] = "Hello   this is a string tokenizer!";

    string ans = myStrTok(in, ' ');

    while (ans != "")
    {
        std::cout << ans << "\n";
        ans = myStrTok(nullptr, ' ');
    }

    char arr[] = "Hello world!";
    ans = myStrTok(arr, ' ');
    cout << "\n" << ans << "\n";
    ans = myStrTok(nullptr, ' ');
    cout << "\n" << ans << "\n";

    return 0;
}
