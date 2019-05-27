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
    line(300, 0, 300, 479);
    setcolor(RED);
    line(0, 240, 639, 240);

    int x = a;
    int y = 0;
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
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;

    c1 = 300;
    c2 = 240;

    myEllipse(a, b, c1, c2);

    getch();
    closegraph();
    return 0;
}

