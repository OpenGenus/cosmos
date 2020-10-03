#include <iostream>
class TwoDimensionalLineIntersection
{
public:
    bool determinantMethod();

    void setCoordinatesOfLines(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_, double x4_, double y4_);

    void printIntersectionPoints();
private:
    double x1_, y1_, x2_, y2_, x3_, y3_, x4_, y4_, xin_, yin_;
};
void TwoDimensionalLineIntersection :: setCoordinatesOfLines(double x1_, double y1_, double x2_, double y2_, double x3_,
                                                             double y3_, double x4_, double y4_)
{
    this->x1_ = x1_;
    this->x2_ = x2_;
    this->x3_ = x3_;
    this->x4_ = x4_;
    this->y1_ = y1_;
    this->y2_ = y2_;
    this->y3_ = y3_;
    this->y4_ = y4_;
}
bool TwoDimensionalLineIntersection :: determinantMethod()
{
    double slopeOfLine1;
    double slopeOfLine2;
    if(x2_ - x1_ != 0)
        slopeOfLine1 = (y2_ - y1_)/(x2_ - x1_);
    else
        slopeOfLine1 = 0;
    if(x4_ - x3_ != 0)
        slopeOfLine2 = (y4_ - y3_)/(x4_ - x3_);
    else
        slopeOfLine1 = 0;

    if(slopeOfLine1 != slopeOfLine2)
    {
        xin_ = ((x1_*y2_ - y1_*x2_)*(x3_ - x4_) - (x3_*y4_ - y3_*x4_)*(x1_ - x2_) )/( ((x1_ - x2_)*(y3_ - y4_))- ((y1_ - y2_)*(x3_ - x4_)));
        yin_ = ((x1_*y2_ - y1_*x2_)*(y3_ - y4_) - (x3_*y4_ - y3_*x4_)*(y1_ - y2_) )/( ((x1_ - x2_)*(y3_ - y4_))- ((y1_ - y2_)*(x3_ - x4_)));
        return true;
    } else
        return false;

}
void TwoDimensionalLineIntersection ::printIntersectionPoints()
{
    if(determinantMethod())
    {
        std::cout << "\nIntersection Coordinate : ";
        std::cout << "\nX-coordinate : " << xin_;
        std::cout << "\nY-coordinate : " << yin_;
    } else
        std::cout << "\nLines are Parallel.";
}
int main()
{
    TwoDimensionalLineIntersection t;
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "\nEnter the Coordinates for Line-1 : ";
    std::cout << "\nLine-1 | x1-coordinate : ";
    std::cin >> x1;
    std::cout << "\nLine-1 | y1-coordinate : ";
    std::cin >> y1;
    std::cout << "\nLine-1 | x2-coordinate : ";
    std::cin >> x2;
    std::cout << "\nLine-1 | y2-coordinate : ";
    std::cin >> y2;
    std::cout << "\nEnter the Coordinates for Line-2 : ";
    std::cout << "\nLine-2 | x3-coordinate : ";
    std::cin >> x3;
    std::cout << "\nLine-2 | y3-coordinate : ";
    std::cin >> y3;
    std::cout << "\nLine-2 | x4-coordinate : ";
    std::cin >> x4;
    std::cout << "\nLine-2 | y4-coordinate : ";
    std::cin >> y4;

    t.setCoordinatesOfLines(x1, y1, x2, y2, x3, y3, x4, y4);
    t.printIntersectionPoints();
}
