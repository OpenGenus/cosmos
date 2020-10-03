#include <iostream>
#include "graphics.h"

class BresenhamCircle
{

public:
    BresenhamCircle(int radius_) : radius_(radius_) { }

    void getRadiusCenter();

    void drawBresenhamCircle();

    void displayBresenhmCircle(int xc_, int yc_, int x, int y);

private:
    int radius_;
    int xc_;
    int yc_;

};

void BresenhamCircle::drawBresenhamCircle()
{
    int x = 0, y = radius_;
    int decesionParameter = 3 - 2 * radius_;
    displayBresenhmCircle(xc_, yc_, x, y);
    while (y >= x)
    {
        x++;
        if (decesionParameter > 0)
        {
            y--;
            decesionParameter = decesionParameter + 4 * (x - y) + 10;
        }
        else
            decesionParameter = decesionParameter + 4 * x + 6;
        displayBresenhmCircle(xc_, yc_, x, y); //displaying all the Eight Pixels of (x,y)
        delay(30);
    }
}

void BresenhamCircle::getRadiusCenter()
{
    std::cout << "\nEnter Radius of the Circle : ";
    std::cin >> radius_;
    std::cout << "\nEnter X-Coordinate of Center of Circle : ";
    std::cin >> xc_;
    std::cout << "\nEnter Y-Coordinate of Center of Circle : ";
    std::cin >> yc_;
}

void BresenhamCircle::displayBresenhmCircle(int xc_,int yc_, int x, int y)
{
    //displaying all 8 coordinates of(x,y) residing in 8-octants
    putpixel(xc_+x, yc_+y, WHITE);
    putpixel(xc_-x, yc_+y, WHITE);
    putpixel(xc_+x, yc_-y, WHITE);
    putpixel(xc_-x, yc_-y, WHITE);
    putpixel(xc_+y, yc_+x, WHITE);
    putpixel(xc_-y, yc_+x, WHITE);
    putpixel(xc_+y, yc_-x, WHITE);
    putpixel(xc_-y, yc_-x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    BresenhamCircle b(0);
    //accepting the radius and the centre coordinates of the circle
    b.getRadiusCenter();
    /*
     * selecting the nearest pixel and displaying all the corresponding
     * points of the nearest pixel point lying in 8-octants.
     *
     */
    b.drawBresenhamCircle();
    delay(200);
    closegraph();

}
