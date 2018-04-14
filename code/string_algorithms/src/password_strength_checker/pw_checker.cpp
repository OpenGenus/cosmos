//  C++ program for check password strength
//
//  main.cpp
//  pw_checker
//


#include <iostream>
#include <string>
using namespace std;

int main()
{

    // criteria
    bool has_upper_letter = false;
    bool has_lower_letter = false;
    bool has_digits_letter = false;
    bool has_approved_length = false;
    bool storng_password = false;

    // password input
    string input_password = "XmkA78Ji";


    // check password
    has_approved_length = input_password.length() >= 8 ? true : false;

    if (has_approved_length)
    {

        for (size_t i = 0; i < input_password.length(); i++)
        {

            if (isupper(input_password[i]) && has_upper_letter == false)
                has_upper_letter = true;
            else if (islower(input_password[i]) && has_lower_letter == false)
                has_lower_letter = true;
            else if (isdigit(input_password[i]) && has_digits_letter == false)
                has_digits_letter = true;

            // handle all valid
            if (has_upper_letter && has_lower_letter && has_digits_letter && has_approved_length)
            {
                storng_password = true;
                break;
            }

        }

        // displaying error
        if (storng_password)
            cout << "Password is strong\n";
        else
        {
            cout << "Password is week\n";
            if (!has_upper_letter)
                cout << "You must have one upper case letter\n";
            if (!has_lower_letter)
                cout << "You must have one lower case letter\n";
            if (!has_digits_letter)
                cout << "You must have one digits case letter\n";
        }

    }
    else
        cout << "You must have 8 digits lenght\n";



    return 0;
}
