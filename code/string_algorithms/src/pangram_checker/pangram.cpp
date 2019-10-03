/*
 *      pangram.cpp
 *      by Charles (@c650)
 *
 *      Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>

#include <string>
#include <vector>

#include <cctype>

/*
 *      Return whether or not str is a pangram, in O(n) time.
 */
static bool is_pangram(const std::string& str);

static void test_pangram(const std::string& test_string, const bool should_be_pangram);

int main(void)
{

    /* test for correct ones */
    test_pangram("We promptly judged antique ivory buckles for the next prize.", true);
    test_pangram("How razorback jumping frogs can level six piqued gymnasts.", true);
    test_pangram("Sixty zippers were quickly picked from the woven jute bag.", true);
    test_pangram("The quick brown fox jumps over a lazy dog.", true);
    test_pangram("Waltz, nymph, for quick jigs vex bud.", true);

    /* test to make sure it doesn't false flag */
    test_pangram("", false);
    test_pangram("I love C++", false);
    test_pangram("The alphabet", false);
    test_pangram("131;1)_()[]", false);

    return 0;
}


static bool is_pangram(const std::string& str)
{
    const int ALPHA_LEN = 'z' - 'a' + 1;
    const char ALPHA_BASE = 'a';
    std::vector<bool> alphabet(ALPHA_LEN, false);     /* we'll flag each character. */

    int count = 0;
    for (const auto& c : str)
    {

        /* if the character c isn't alphabetical, or if we've already seen that character, skip it. */
        if (!std::isalpha(c) || alphabet[std::tolower(c) - ALPHA_BASE])
            continue;

        /* denote that we saw this character. */
        alphabet[std::tolower(c) - ALPHA_BASE] = true;

        /* increment count. */
        ++count;
    }

    return count == ALPHA_LEN;
}

static void test_pangram(const std::string& test_string, const bool should_be_pangram)
{
    std::cout << "Testing if \"" << test_string << "\" is a pangram.\n\t";
    if (is_pangram(test_string) == should_be_pangram)
        std::cout << "Success!";
    else
        std::cout << "WRONG!";
    std::cout << "\n";
}
