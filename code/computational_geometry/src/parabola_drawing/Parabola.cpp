#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void putPixel(int x, int y, int cx, int cy)
{
    putpixel((x + cx), (cy - y), 15);
    putpixel((x + cx), (cy + y), 15);
}

void para(int cx, int cy, double a)
{

    setcolor(BLUE);
    line(cx, 0, cx, 479);
    setcolor(RED);
    line(0, cy, 639, cy);

    // x = 0 and y = 0 are the starting coordinates of the parabola.
    double x = 0, y = 0;

    //d1 is the decision parameter that determines how the next point to be drawn is chosen.
    double d1;
    d1 = 2 * a - 1;


    putPixel(x, y, cx, cy);

    while (y <= (2 * a * 1.0))
    {
        if (d1 < 0)
	{
            d1 += (4 * a) - 3 - (2 * y);
            x++;
            y++;
        }

    	else
    	{
            d1 -= 3 + (2 * y);
            y++;
    	}

        putPixel(x, y, cx, cy);

    }

    d1 = ((4.0 * a * (x + 1)) - (y + 0.5) * (y + 0.5));

    while(y < 220)
    {
        if(d1 < 0)
	{
            d1 += (4 * a);
            x++;
        }

        else
        {
            d1 += (4 * a) - 2 - (2 * y);
            x++;
            y++;
        }

        putPixel(x, y, cx, cy);
    }
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double a;
    // a is the distance from focus to the vertex of the parabola
    cout << "Enter the distance from focus to the vertex of the parabola:" << endl;
    cin >> a;

    int cx, cy;
    cout << "Enter the x coordinate of the vertex of the parabola" << endl;
    cin >> cx;

    cout << "Enter the y coordinate of the vertex of the parabola" << endl;
    cin >> cy;

    para(cx, cy, a);

    getch();
    closegraph();

    return 0;
}
