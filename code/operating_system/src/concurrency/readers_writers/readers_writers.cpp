#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

#define N     5 // # of processes (readers & writes)

std::mutex mu; // controlling access to the number of processes
std::mutex db; // controlling acess to the database
std::mutex print_mu; // guards the cout << I/O
int rc = 0; // # of processes reading or waiting to

void read_db(int i)
{
    std::lock_guard<std::mutex> guard {print_mu};
    std::cout << "Reader #" << i << " is reading to the database" << std::endl;
}

void write_db(int i)
{
    std::lock_guard<std::mutex> guard {print_mu};
    std::cout << "Writer #" << i << " is writing to the database" << std::endl;
}

void reader(int i)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock_mu {mu};
        std::unique_lock<std::mutex> lock_db {db, std::defer_lock};
        rc = rc + 1;
        if (rc == 1)
            lock_db.lock();
        lock_mu.unlock();
        read_db(i);
        lock_mu.lock();
        rc = rc - 1;
        if (rc == 0)
            lock_db.unlock();
        lock_mu.unlock();
    }
}

void writer(int i)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock_db {db};
        write_db(i);
        lock_db.unlock();
    }
}

int main()
{

    std::thread writers[N];
    std::thread readers[N];

    for (size_t i = 0; i < N; i++)
    {
        writers[i] = std::thread(writer, i);
        readers[i] = std::thread(reader, i);
    }

    for (size_t i = 0; i < N; i++)
    {
        writers[i].join();
        readers[i].join();
    }

    return 0;
}
