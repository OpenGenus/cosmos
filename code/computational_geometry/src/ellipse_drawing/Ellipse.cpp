#include <iostream>
#include <graphics.h>

using namespace std;

void ellipseSymm(int x, int y, int c1, int c2)
{
    putpixel(x + c1, y + c2, 15);
    putpixel(-x + c1, y + c2, 15);
    putpixel(x + c1, -y + c2, 15);
    putpixel(-x + c1, -y + c2, 15);
}

void myEllipse(int a, int b, int c1, int c2)
{
    setcolor(BLUE);
    line(c1, 0, c1, 479);
    setcolor(RED);
    line(0, c2, 639, c2);

    // x = a and y = 0 are the first coordinates of the ellipse that are drawn on the screen
    int x = a;
    int y = 0;
    // d is the decision parameter that determines the next point to be chosen for drawing
    int d = (a * a) - ((1/4) * (b * b)) - (a * b * b);
    ellipseSymm(x, y, c1, c2);

    while ((b * b * x) >= (a * a * y))
    {
        if (d < 0)
            d += a * a * (3 + (2 * y));
        else
	{
            d += a * a * (2 * y + 3) + (2 * b * b * (1 - x));
            x--;
        }

        y++;
        ellipseSymm(x, y, c1, c2);
    }

    d = (b * b * (x - 1) * (x - 1)) + (a * a * (y + 0.5) * (y + 0.5)) - (a * a * b * b);

    while (x >= 0)
    {
        if (d < 0)
        {
            d += (b * b * (3 - (2 * x))) + (2 * a * a * (1 + y));
            y++;
        }

        else
            d += (b * b * (3 - (2 * x)) );

	x--;
        ellipseSymm(x, y, c1, c2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int a,b,c1,c2;
    cout << "Enter value of major axis" << endl;
    cin >> a;
    cout << "Enter value of minor axis" << endl;
    cin >> b;

    cout << "Enter the x coordinate of the centre of the ellipse" << endl;
    cin >> c1;

    cout << "Enter the y coordinate of the centre of the ellipse" << endl;
    cin >> c2;

    myEllipse(a, b, c1, c2);

    getch();
    closegraph();
    return 0;
}

