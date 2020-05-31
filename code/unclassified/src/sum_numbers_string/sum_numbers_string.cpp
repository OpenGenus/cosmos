// Given a string containing alphanumeric characters, calculate sum of all
// numbers present in the string.
#include <cctype>
#include <cstdlib>
#include <iostream>

int sumNumbersString(std::string s) {
    int sum = 0;
    std::string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            str += s[i];
            if (!isdigit(s[i + 1])) {
                int n = std::stoi(str);
                sum += n;
                str = "";
            }
        }
    }
    return sum;
}

int main() {
    std::string s;
    std::cout << "Enter the string :  ";
    std::cin >> s;
    std::cout << "The sum of numbers present in the string :  "
              << sumNumbersString(s);
    return 0;
}

/*Sample Input-Output
Enter the string :  this12is3just67another1string2
The sum of numbers present in the string :  85
*/
