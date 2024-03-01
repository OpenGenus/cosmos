#include "iostream"
#include "fstream"

inline unsigned int myatoi(const char digit)
{
	switch(digit)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
}

unsigned int mult(const char*& digits)
{
	return (myatoi(digits[0]) * myatoi(digits[1])  * myatoi(digits[2]) *
			myatoi(digits[3]) * myatoi(digits[4]));
}

int main(int argc, char** argv)
{
	unsigned int max_mult = 0;
	unsigned int i = 0;
	char* digits = new char[6];

	std::fstream file;
	file.open("./number.txt");
	if(file.is_open())
	{
		while(i < 1000)
		{
			file.seekp(i);
			file.get(digits, 6, '\n');
			max_mult = std::max(max_mult, multi(digits));
			++i;
		}
	}

	file.close();
	delete[] digits;

	std::cout << max_mult;
	return 0;
}