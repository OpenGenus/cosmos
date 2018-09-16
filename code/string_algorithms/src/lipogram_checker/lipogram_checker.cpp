// Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <string>

const std::string alphabets = "abcdefghijklmnopqrstuvwxyz";

void
panLipogramChecker(std::string phrase)
{
    using std::cout;
    using std::endl;

    for (unsigned int i = 0; i < phrase.length(); i++)
        phrase[i] = tolower(phrase[i]);
    int counter = 0;
    for (unsigned int i = 0; i < 26; i++)
    {
        auto pos = phrase.find(alphabets[i]);

        if (pos > phrase.length())
            counter += 1;
    }

    if (counter == 0)
        cout << "Pangram" << endl;
    else if (counter >= 2)
        cout << "Not a pangram but might be a lipogram" << endl;
    else
        cout << "Pangrammatic Lipogram" << endl;
}

int
main()
{
    std::string str = "The quick brown fox jumped over the lazy dog";
    panLipogramChecker(str);

    str = "The quick brown fox jumps over the lazy dog";
    panLipogramChecker(str);

    str = "The quick brown fox jum over the lazy dog";
    panLipogramChecker(str);
}
