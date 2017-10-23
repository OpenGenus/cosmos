#include <iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton& getInstance()
        {
            static Singleton instance;
            return instance;
        };
    private:
        Singleton() {};

        // C++ 03
        // Methods are declared, although not implemented, in order to prevent copies of the singleton
        Singleton(const Singleton&);
        void operator=(const Singleton&);


    public:
        // C++ 11
        // Same principle than above but for C++11
        // Singleton(const Singleton&) = delete;
        // void operator=(const Singleton&) = delete;
};

//For tests purposes
int main()
{
	Singleton& aInstance = Singleton::getInstance();
	Singleton& aInstance2 = Singleton::getInstance();
	cout << "&aInstance  : " << &aInstance << endl;
	cout << "&aInstance2 : " << &aInstance2 << endl;
	return 0;
}

