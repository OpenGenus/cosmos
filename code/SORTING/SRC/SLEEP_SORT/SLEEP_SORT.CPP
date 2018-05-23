/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;

int main(int argc, char** argv)
{
    vector<thread> threads;

    for (auto i = 1; i < argc; ++i)
    {
        threads.emplace_back(
            [i, &argv]()
        {
            int arg = stoi(argv[i]);
            this_thread::sleep_for(chrono::seconds(arg));
            cout << argv[i] << endl;
        }
            );
    }

    for (auto &thread: threads)
        thread.join();

    return 0;
}
