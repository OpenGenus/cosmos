// Header files included
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    /* 
     * x1, x2, y1 & y2 are line coordinates
     * xmax, xmin, ymax & ymin are window's lower and upper corner coordinates
     * xx1, yy1, xx2 & yy2 are the new coordinates of clipped line
     */
    int x1, y1, x2, y2;
    int xmax, xmin, ymax, ymin;
    int xx1, yy1, xx2, yy2;
    int dx, dy, i;
    int p[4], q[4];
    float t1, t2, t[4];

    initgraph (& gd, & gm, "C:\\TC\\BGI");
    // Enter the coordinates for window
    cout << "Enter the lower co-ordinates of window";
    cin >> xmin >> ymin;
    cout << "Enter the upper co-ordinates of window";
    cin >> xmax >> ymax;

    // Graphics function to draw rectangle/clipping window
    setcolor (RED);
    rectangle (xmin, ymin, xmax, ymax);

    // Enter the coordinates of line
    cout << "Enter x1:";
    cin >> x1;
    cout << "Enter y1:";
    cin >> y1;
    cout << "Enter x2:";
    cin >> x2;
    cout << "Enter y2:";
    cin >> y2;

    // Graphics Function to draw line
    line (x1, y1, x2, y2);

    dx = x2 - x1;
    dy = y2 - y1;
    p[0] = - dx;
    p[1] = dx;
    p[2] = - dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (i=0; i < 4; i++)
    {

        if (p[i] != 0)
        {
            t[i] = (float) q[i] / p[i];
        }

        else
        {
            if (p[i] == 0 && q[i] < 0)
                cout << "line completely outside the window";

            else
                if (p[i] == 0 && q[i] >= 0)
                    cout << "line completely inside the window";
        }
    }
    if (t[0] > t[2])
        t1 = t[0];

    else
        t1 = t[2];

    if (t[1] < t[3])
        t2 = t[1];

    else
        t2 = t[3];

    if (t1 < t2)
    {
        xx1 = x1 + t1 * dx;
        xx2 = x1 + t2 * dx;
        yy1 = y1 + t1 * dy;
        yy2 = y1 + t2 * dy;
        cout << "line after clipping:";

        setcolor (WHITE);
        line (xx1, yy1, xx2, yy2);
    }
    else
        cout << "line lies out of the window";

    getch();
    return (0);
}
