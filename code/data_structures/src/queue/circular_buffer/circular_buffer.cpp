#include <iostream>
#include <vector>

template <typename T, long SZ>
class circular_buffer
{
private:
    T* m_buffer;
    long m_index;

public:
    circular_buffer()
        : m_buffer {new T[SZ]()}
        , m_index {0}
    {
    }

    ~circular_buffer()
    {
        delete m_buffer;
    }

    std::vector<T> get_ordered() noexcept
    {
        std::vector<T> vec;
        for (long i = 0; i < SZ; ++i)
            vec.push_back(m_buffer[(i + m_index) % SZ]);
        return vec;
    }

    void push(T x) noexcept
    {
        m_buffer[m_index] = x;
        m_index = (m_index + 1) % SZ;
    }
};

int main()
{
    circular_buffer<int, 4> buf;

    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.push(4);
    buf.push(5);
    buf.push(6);

    for (auto x : buf.get_ordered())
        std::cout << x << std::endl;
}
