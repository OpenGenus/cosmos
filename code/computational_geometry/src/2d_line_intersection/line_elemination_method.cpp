#include <iostream>
#include <vector>
class EliminationMethd2DLineIntersection
{
public:
    void acceptTheCoordinates(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void intersection1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

private:
    std::vector<double> a, b, c, d;    //four coordinates constituting 2 Dimensional Lines.
};
void EliminationMethd2DLineIntersection::acceptTheCoordinates(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    a.push_back(x1);
    a.push_back(y1);
    b.push_back(x1);
    b.push_back(y1);
    c.push_back(x1);
    c.push_back(y1);
    d.push_back(x1);
    d.push_back(y1);
    intersection1(a[0], a[1], b[0], b[1], c[0], c[1], d[0], d[1]);
}
void EliminationMethd2DLineIntersection::intersection1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double x12 = x1 - x2;
    double x34 = x3 - x4;
    double y12 = y1 - y2;
    double y34 = y3 - y4;
    double c = x12 * y34 - y12 * x34;
    double a = x1 * y2 - y1 * x2;
    double b = x3 * y4 - y3 * x4;
    if(c != 0)
    {
        double x = (a * x34 - b * x12) / c;
        double y = (a * y34 - b * y12) / c;
        std::cout << "Intersection point coordinates : \n";
        std::cout << "Xin : " << x << std::endl;
        std::cout << "Yin : " << y << std::endl;
    } 
    else
    {
        std::cout << "Lines are parallel";
    }
}
int main()
{
    EliminationMethd2DLineIntersection obj;
    int value;
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
    std::cout << "\nEnter the Coordinates for Line-1";
    std::cout << "\nEnter the X-coordinate for Point-1: ";
    std::cin >> x1;
    std::cout << "\nEnter the Y-coordinate for Point-1: ";
    std::cin >> y1;
    std::cout << "\nEnter the X-coordinate for Point-2: ";
    std::cin >> x2;
    std::cout << "\nEnter the Y-coordinate for Point-2: ";
    std::cin >> y2;
    std::cout << "\nEnter the Coordinates for Line-2";
    std::cout << "\nEnter the X-coordinate for Point-1: ";
    std::cin >> x3;
    std::cout << "\nEnter the Y-coordinate for Point-1: ";
    std::cin >> y3;
    std::cout << "\nEnter the X-coordinate for Point-2: ";
    std::cin >> x4;
    std::cout << "\nEnter the Y-coordinate for Point-2: ";
    std::cin >> y4;
    obj.acceptTheCoordinates(x1,y1, x2, y2, x3, y3, x4, y4);
    return 0;
}
