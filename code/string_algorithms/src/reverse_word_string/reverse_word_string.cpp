// Reverse the words in a given string
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

std::vector<std::string> reverseWords(std::string s) {
    std::string temp;
    int c = 1;
    temp.resize(s.length());
    for (char ch : s) {
        if (isspace(ch))
            c++;
    }
    std::vector<std::string> str(c);
    int k = 0, ind = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (!isspace(s[i])) {
            temp[k] = (s[i]);
            k++;
        }

        if ((isspace(s[i])) || i == s.length() - 1) {
            str[ind] = temp;
            // std::cout<<"temp is :"<<temp;
            temp.clear();
            temp.resize(s.length());
            ind++;
            k = 0;
        }
    }
    std::reverse(str.begin(), str.end());
    return str;
}

int main() {
    std::string s;
    std::cout << "Enter the sentence :  ";
    getline(std::cin, s);
    std::cout << "After Reversal of Words in String : \n";
    std::vector<std::string> str = reverseWords(s);
    for (std::string s : str)
        std::cout << s << " ";
    return 0;
}

/*Sample Input-Output
Enter the sentence :  I still know what you did last summer
After Reversal of Words in String :
summer last  did  you  what  know  still  I
*/
// summer last did you what know still I
// summer last did you what know still I
