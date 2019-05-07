#include <iostream>
#include <cmath>

class AreaOfTriangle
{
public:
    AreaOfTriangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    double calculateArea();

private:
    double a_, b_, c_;

};

double AreaOfTriangle::calculateArea()
{
    /*
     * As magnitude of length of sides must be positive.
     * Given length of sides of triangle must follow the following result :
     * "Sum of any two sides of triangle must be smaller than the third side of triangle".
     */
    if (a_ < 0 || b_ < 0 || c_ < 0 || a_+ b_ <= c_ || a_+ c_ <= b_ || b_+ c_ <= a_)
        return 0.0;
    double s = (a_ + b_ + c_) / 2;  //semi-perimeter of triangle
    return sqrt(s * (s - a_) * (s - b_) * (s - c_));    //Heron's Formula
}

int main()
{
    double ta, tb, tc;
    std::cout << "\nEnter the length of side-1 : ";
    std::cin >> ta;
    std::cout << "\nEnter the length of side-2 : ";
    std::cin >> tb;
    std::cout << "\nEnter the length of side-3 : ";
    std::cin >> tc;
    AreaOfTriangle a(ta, tb, tc);
    if (a.calculateArea() == 0.0)
        std::cout << "\nInvalid Triangle";
    else
        std::cout << "\nArea of Triangle : " << a.calculateArea() << " square units.";

}
