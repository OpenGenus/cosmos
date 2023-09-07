// Part of Cosmos by OpenGenus Foundation
#include <cassert>
#include <stack>
#include <iostream>

template < typename T > // T must have operator< defined
class MinQueue
{
private:
    using MinStack = std::stack< std::pair < T , T > >; // second coordinate: smallest element from current to bottom
    MinStack in, out;

public:
    MinQueue() { }

    void push(T x);
    T pop();
    T getMin();

};

template< typename T >
void MinQueue<T>::push(T x)
{
    if (in.empty())
        in.emplace(x, x);

    else
    {
        T m = in.top().second; // previous minimum
        in.emplace(x, std::min(x, m));
    }
}

template< typename T >
T MinQueue<T>::pop(){
    if (out.empty())
    {
        while (!in.empty())
        { // transfers everything to out stack (inverting their order)
            std::pair<T, T> p = in.top();
            in.pop();

            if (out.empty())
                out.emplace(p.first, p.first);
            else
            {
                T m = out.top().second;
                out.emplace(p.first, std::min(p.first, m));
            }
        }

    }

    if (out.empty())
    {
        std::cout << "Error! Queue is empty.\n";
        assert(false);
    }

    T ret = out.top().first;
    out.pop();

    return ret;
}

template< typename T >
T MinQueue<T>::getMin()
{

    if (in.empty() and out.empty())
    {
        std::cout << "Can't get minimum: Queue is empty.\n";
        assert(false);
    }

    if (in.empty())
        return out.top().second;
    if (out.empty())
        return in.top().second;

    return std::min(in.top().second, out.top().second);
}

int main(){
    MinQueue< char > MQ;

    MQ.push('a');
    MQ.push('x');
    MQ.push('h');

    std::cout << MQ.getMin() << '\n';
    std::cout << MQ.pop() << '\n';
    std::cout << MQ.getMin() << '\n';

    return 0;
}
