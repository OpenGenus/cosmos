/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <chrono>
#include <vector> 
#include <thread>

int main(int argc, char** argv)
{
    std::vector<std::thread> threads;
    
    for(auto i = 1; i < argc; ++i)
    {
        thread.emplace_back([i, &argv]()
        {
        int arg = std::stoi(argv[i]);
        std::this_thread::sleep_for(std::chrono::seconds(arg));
        std::cout << argv[i] << std::endl;
        });
    }
    
    for(auto &thread: threads)
    {
        thread.join();
    }
    
    return(0);
}
