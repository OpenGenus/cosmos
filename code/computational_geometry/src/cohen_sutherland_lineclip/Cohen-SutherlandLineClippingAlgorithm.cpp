#include <iostream>
// Part of Cosmos by OpenGenus Foundation
class CohenSutherLandAlgo
{
private:
    double x1,y1,x2,y2;
    double x_max,y_max,x_min,y_min;
    const int INSIDE = 0;	// 0000
    const int LEFT   = 1;	// 0001
    const int RIGHT  = 2;	// 0010
    const int BOTTOM = 4;	// 0100
    const int TOP    = 8;	// 1000
public:
    CohenSutherLandAlgo():x1(0.0),x2(0.0),y1(0.0),y2(0.0)
    {

    }
    void setCoordinates(double x1, double y1,double x2, double y2);
    void setClippingRectangle(double x_max, double y_max,double x_min, double y_min);
    int generateCode(double x, double y);
    void cohenSutherland();
};
void CohenSutherLandAlgo::setCoordinates(double x1, double y1,double x2, double y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;

}
void CohenSutherLandAlgo::setClippingRectangle(double x_max, double y_max,double x_min, double y_min)
{
    this->x_max = x_max;
    this->y_max = y_max;
    this->x_min = x_min;
    this->y_min = y_min;
}
int CohenSutherLandAlgo::generateCode(double x, double y)
{
    int code = INSIDE;  // intially initializing as being inside
    if (x < x_min)  // lies to the left of rectangle
        code |= LEFT;
    else if (x > x_max) // lies to the right of rectangle
        code |= RIGHT;
    if (y < y_min)  // lies below the rectangle
        code |= BOTTOM;
    else if (y > y_max) // lies above the rectangle
        code |= TOP;
    return code;
}
void CohenSutherLandAlgo::cohenSutherland()
{
    int code1 = generateCode(x1, y1);       // Compute region codes for P1.
    int code2 = generateCode(x2, y2);   // Compute region codes for P2.
    bool accept = false;  // Initialize line as outside the rectangular window.
    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle.
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,in same region.
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle.
            int code_out;
            double x, y;
            // At least one endpoint lies outside the rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            /*
             * Find intersection point by using formulae :
             y = y1 + slope * (x - x1)
             x = x1 + (1 / slope) * (y - y1)
             */
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            // Intersection point x,y is found.
            // Replace point outside rectangle by intersection point.
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = generateCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = generateCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        std::cout <<"Line accepted from " <<"("<< x1 << ", "
                  << y1 << ")" <<  " to "<< "(" << x2 << ", " << y2 << ")" << std::endl;
    }
    else
        std::cout << "Line rejected" << std::endl;
}
int main()
{
    CohenSutherLandAlgo c;
    double x1,y1,x2,y2,x_max,y_max,x_min,y_min;

    std::cout << "\nEnter Co-ordinates of P1(X1,Y1) of Line Segment : ";
    std::cout << "\Enter X1 Co-ordinate : ";
    std::cin >> x1;
    std::cout << "\Enter Y1 Co-ordinate : ";
    std::cin >> y1;
    std::cout << "\nEnter Co-ordinates of P2(X2,Y2) of Line Segment : ";
    std::cout << "\Enter X2 Co-ordinate : ";
    std::cin >> x2;
    std::cout << "\Enter Y2 Co-ordinate : ";
    std::cin >> y2;
    c.setCoordinates(x1, y1, x2, y2);

    std::cout << "\nEnter the Co-ordinates of Interested Rectangle.";
    std::cout << "\nEnter the X_MAX : ";
    std::cin >> x_max;
    std::cout << "\nEnter the Y_MAX : ";
    std::cin >> y_max;
    std::cout << "\nEnter the X_MIN : ";
    std::cin >> x_min;
    std::cout << "\nEnter the Y_MIN : ";
    std::cin >> y_min;
    c.setClippingRectangle(x_max, y_max, x_min, y_min);

    c.cohenSutherland();
   
}
