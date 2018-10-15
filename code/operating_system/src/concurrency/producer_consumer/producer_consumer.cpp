#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

const int N = 100;
std::vector<int> shared_buffer(N);
std::mutex lock_buffer;
std::condition_variable cond;

void producer()
{

    while (true)
    {
        std::unique_lock<std::mutex> guard_producer(lock_buffer);
        if (shared_buffer.size() == N)
            cond.wait(guard_producer);

        int item_produced = rand() % 100 + 1; // ranges 1 to 100
        shared_buffer.push_back(item_produced);

        if (shared_buffer.size() == 1)
            cond.notify_one();
        std::cout << "Item " << item_produced
                  << " was inserted into the buffer" << std::endl;
    }
}

void consumer()
{

    while (true)
    {
        std::unique_lock<std::mutex> guard_consumer(lock_buffer);
        if (shared_buffer.empty())
            cond.wait(guard_consumer);

        int item_consumed = shared_buffer.back(); // gets item
        shared_buffer.pop_back(); // removes item

        if (shared_buffer.size() == N - 1)
            cond.notify_one();
        std::cout << "Item " << item_consumed
                  << " was removed from the buffer" << std::endl;
    }
}

int main()
{
    srand (time(0));
    std::thread t_consumer(producer);
    std::thread t_producer(consumer);
    t_consumer.join();
    t_producer.join();
    return 0;
}
