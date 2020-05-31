//double to String using C++’s std::to_string:
#include <iostream>
#include <string>
#include <sstream>  //to use ostringstream
#include <cstring>  //to use sprintf
#include <boost/lexical_cast.hpp>  //to use boost's lexical cast
using namespace std;
int main() 
{
    double d1 = 23.43;
    double d2 = 1e-9;
    double d3 = 1e40;
    double d4 = 1e-40;
    double d5 = 123456789;
    string d_str1 = to_string(d1);
    string d_str2 = to_string(d2); 
    string d_str3 = to_string(d3); 
    string d_str4 = to_string(d4); 
    string d_str5 = to_string(d5);
    cout << "Number: " << d1 << '\n'
    << "to_string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to_string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to_string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to_string: " << d_str4 << "\n\n"
    << "Number: " << d5 << '\n'
    << "to_string: " << d_str5 << '\n';


//double to String using ostringstream

    ostringstream ss1,ss2,ss3,ss4;
    double d1 = 23.43;
    double d2 = 6789898989.339994;
    double d3 = 1e40;
    double d4 = 1e-40;
    ss1<<d1;
    ss2<<d2;
    ss3<<d3;
    ss4<<d4;
    string d_str1 = ss1.str();
    string d_str2 = ss2.str(); 
    string d_str3 = ss3.str(); 
    string d_str4 = ss4.str(); 
    cout << "Number: " << d1 << '\n'
    << "to string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to string: " << d_str4 << "\n\n";
    
//Code to convert double to string with osstringstream to get the output as fixed-point notation inplace of scientific notation.

    ostringstream ss1,ss2,ss3,ss4;
    double d1 = 23.43;
    double d2 = 6789898989.339994;
    double d3 = 1e40;
    double d4 = 1e-40;
    ss1<<fixed<<d1;
    ss2<<fixed<<d2;
    ss3<<fixed<<d3;
    ss4<<fixed<<d4;
    string d_str1 = ss1.str();
    string d_str2 = ss2.str(); 
    string d_str3 = ss3.str(); 
    string d_str4 = ss4.str(); 
    cout << "Number: " << d1 << '\n'
    << "to string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to string: " << d_str4 << "\n\n";

//double to string with custom precision by setting the precision in stringstream as below

    ostringstream ss1,ss2,ss3,ss4;
    ss1.precision(2);
    ss2.precision(2);
    ss3.precision(2);
    ss4.precision(2);
    double d1 = 23.43;
    double d2 = 6789898989.339994;
    double d3 = 1e40;
    double d4 = 1e-40;
    ss1<<fixed<<d1;
    ss2<<fixed<<d2;
    ss3<<fixed<<d3;
    ss4<<fixed<<d4;
    string d_str1 = ss1.str();
    string d_str2 = ss2.str(); 
    string d_str3 = ss3.str(); 
    string d_str4 = ss4.str(); 
    cout << "Number: " << d1 << '\n'
    << "to string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to string: " << d_str4 << "\n\n";

//double to String/character array using sprintf


    double d1 = 23.43;
    double d2 = 6789898989.339994;
    double d3 = 1e40;
    double d4 = 1e-40;
    char s[200];
    sprintf(s," 23.43 converts to %.2f \n 6789898989.339994 converts to %.3f \n 1e40 converts to %.4f \n 1e-40 converts to %.5f",d1,d2,d3,d4);
    cout<<s<<"\nsize of the above string is:"<<strlen(s);


//double to String using boost’s lexical_cast

    double d1 = 23.43;
    double d2 = 1e-9;
    double d3 = 1e40;
    double d4 = 1e-40;
    double d5 = 123456789;
    string d_str1 = boost::lexical_cast<string>(d1);
    string d_str2 = boost::lexical_cast<string>(d2); 
    string d_str3 = boost::lexical_cast<string>(d3); 
    string d_str4 = boost::lexical_cast<string>(d4); 
    string d_str5 = boost::lexical_cast<string>(d5);
    cout << "Number: " << d1 << '\n'
    << "to string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to string: " << d_str4 << "\n\n"
    << "Number: " << d5 << '\n'
    << "to string: " << d_str5 << '\n';
    return 0;
}
