/*
 * policy_design.cpp
 *
 * Created: 3/15/2018 1:14:41 AM
 *  Author: n-is
 *   email: 073bex422.nischal@pcampus.edu.np
 */

#include <iostream>

class Classical
{
public:
    Classical(int a)
    {
    }

    void solve()
    {
        std::cout << "The differential equation was solved by the classical" <<
            " method." << std::endl;
    }
};

class Laplace
{
public:
    void solve()
    {
        std::cout << "The differential equation was solved by the Laplace" <<
            " Transform method." << std::endl;
    }
};

template <class Method>
class DifferentialEquaton
{
private:
    Method m_;
public:
    DifferentialEquaton(const Method & m = Method()) :
        m_(m)
    {
    }

    void solve()
    {
        m_.solve();
    }
};

int main()
{
    DifferentialEquaton<Laplace> eqn1;
    DifferentialEquaton<Classical> eqn2(Classical(1));

    eqn1.solve();
    eqn2.solve();

    return 0;
}
