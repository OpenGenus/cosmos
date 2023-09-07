#include <iostream>

using namespace std;

//class with  ascii encoder and decoder method
class Ascii
{

  public:
    //empty constructor
    Ascii();

    //takes a string and returns an array of encoded letters in ascii
    int* encode(string s);

    //takes a array of int and returns the deoced in ascii string
    string decode(int* arr, int length);

};


Ascii::Ascii()
{
  //empty
}

int* Ascii::encode(string s)
{
  int* arr = new int[s.length()];

  for(int i = 0; i < s.length(); i++)
  {
    arr[i] = (int) s[i];
  }
  return arr;
}

string Ascii::decode(int* arr, int length)
{
  string s = "";
  for(int i = 0; i < length; i++)
    s += char(arr[i]);

  return s;
}


//here it is provided a default test for ascii class
int main(){
  Ascii coder;
  //in string s put your message to be encrypted
  string s = "Hello World!";
  cout << "Decoded Message: " << s << endl;
  int* encodedMessage = coder.encode(s);
  cout << "Encoded Message: ";
  for(int i = 0 ; i < s.length(); i++)
    cout << encodedMessage[i] <<  " ";
  cout << endl << endl;

  //in encodedArray put your encoded array to be decrypted
  int encodedArray[] = {73, 32, 76, 111, 118, 101, 32, 80, 114, 111, 103, 114, 97, 109, 109, 105, 110, 103, 33};
  string decodedMessage = coder.decode(encodedArray, sizeof(encodedArray) / 4);
  cout << "Encoded Message: ";
  for(int i = 0; i < sizeof(encodedArray) / 4; i++)
    cout << encodedArray[i] << " ";
  cout << endl;
  cout << "Decoded message: " << decodedMessage << endl;

  return 0;
}
