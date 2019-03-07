#include <iostream>

class CohenSutherLandAlgo
{
    
public:
    CohenSutherLandAlgo() : x1_(0.0), x2_(0.0), y1_(0.0), y2_(0.0) { }

    void setCoordinates(double x1, double y1, double x2, double y2);

    void setClippingRectangle(double x_max, double y_max, double x_min, double y_min);

    int generateCode(double x, double y);

    void cohenSutherland();

private:
    double x1_, y1_, x2_, y2_;
    double xMax_, yMax_, xMin_, yMin_;
    const int Inside = 0;	// 0000
    const int Left   = 1;	// 0001
    const int Right  = 2;	// 0010
    const int Bottom = 4;	// 0100
    const int Top    = 8;	// 1000

};

void CohenSutherLandAlgo::setCoordinates(double x1, double y1, double x2, double y2)
{
    this->x1_ = x1;
    this->y1_ = y1;
    this->x2_ = x2;
    this->y2_ = y2;
}

void CohenSutherLandAlgo::setClippingRectangle(double x_max, double y_max, double x_min, double y_min)
{
    this->xMax_ = x_max;
    this->yMax_ = y_max;
    this->xMin_ = x_min;
    this->yMin_ = y_min;
}

int CohenSutherLandAlgo::generateCode(double x, double y)
{
    int code = Inside;  // intially initializing as being inside
    if (x < xMin_)  // lies to the left of rectangle
        code |= Left;
    else if (x > xMax_) // lies to the right of rectangle
        code |= Right;
    if (y < yMin_)  // lies below the rectangle
        code |= Bottom;
    else if (y > yMax_) // lies above the rectangle
        code |= Top;
    return code;
}

void CohenSutherLandAlgo::cohenSutherland()
{
    int code1 = generateCode(x1_, y1_);   // Compute region codes for P1.
    int code2 = generateCode(x2_, y2_);   // Compute region codes for P2.
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
            break;  // If both endpoints are outside rectangle,in same region.
        }
        else
        {
            // Some segment of line lies within the rectangle.
            int codeOut;
            double x, y;
            // At least one endpoint lies outside the rectangle, pick it.
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;
            /*
             * Find intersection point by using formulae :
             y = y1 + slope * (x - x1)
             x = x1 + (1 / slope) * (y - y1)
             */
            if (codeOut & Top)
            {
                // point is above the clip rectangle
                x = x1_ + (x2_ - x1_) * (yMax_ - y1_) / (y2_ - y1_);
                y = yMax_;
            }
            else if (codeOut & Bottom)
            {
                // point is below the rectangle
                x = x1_ + (x2_ - x1_) * (yMin_ - y1_) / (y2_ - y1_);
                y = yMin_;
            }
            else if (codeOut & Right)
            {
                // point is to the right of rectangle
                y = y1_ + (y2_ - y1_) * (xMax_ - x1_) / (x2_ - x1_);
                x = xMax_;
            }
            else if (codeOut & Left)
            {
                // point is to the left of rectangle
                y = y1_ + (y2_ - y1_) * (xMin_ - x1_) / (x2_ - x1_);
                x = xMin_;
            }
            /*
             * Intersection point x,y is found.
               Replace point outside rectangle by intersection point.
            */
            if (codeOut == code1)
            {
                x1_ = x;
                y1_ = y;
                code1 = generateCode(x1_, y1_);
            }
            else
            {
                x2_ = x;
                y2_ = y;
                code2 = generateCode(x2_, y2_);
            }
        }
    }
    if (accept)
    {
        std::cout <<"Line accepted from " <<"("<< x1_ << ", "
                  << y1_ << ")" <<  " to "<< "(" << x2_ << ", " << y2_ << ")" << std::endl;
    }
    else
        std::cout << "Line rejected" << std::endl;
}

int main() {

    CohenSutherLandAlgo c;
    double x1, y1, x2, y2, x_max, y_max, x_min, y_min;

    std::cout << "\nEnter Co-ordinates of P1(X1,Y1) of Line Segment : ";
    std::cout << "\nEnter X1 Co-ordinate : ";
    std::cin >> x1;
    std::cout << "\nEnter Y1 Co-ordinate : ";
    std::cin >> y1;
    std::cout << "\nEnter Co-ordinates of P2(X2,Y2) of Line Segment : ";
    std::cout << "\nEnter X2 Co-ordinate : ";
    std::cin >> x2;
    std::cout << "\nEnter Y2 Co-ordinate : ";
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
