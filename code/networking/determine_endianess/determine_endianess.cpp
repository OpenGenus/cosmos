#include <iostream>

using namespace std;

int is_big_endian()
{
    union {
        uint32_t i;
        char c[4];
    } bigint= {0x01020304};

    return bigint.c[0] == 1;
}

int main(int argc, char const *argv[])
{
	if(is_big_endian()){
		cout<<"Big Endian"<<endl;
	}
	else{
		cout<<"Little Endian"<<endl;
	}
	return 0;
}

