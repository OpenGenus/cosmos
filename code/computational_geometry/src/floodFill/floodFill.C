#include<stdio.h>
#include<graphics.h>

void floodFill(int x, int y, int old, int newcol)
{
    int current;

    // To get color pixel
    current = getpixel(x, y);

    // check current pixel is old_color or not
    if(current == old)
    {
        delay(5);

	    // put new pixel with new color
	    putpixel(x, y, newcol);

	    // recursive call for bottom pixel fill
	    floodFill(x + 1, y, old, newcol);

	    // recursive call for top pixel fill
	    floodFill(x - 1, y, old, newcol);

	    // recursive call for right pixel fill
	    floodFill(x, y + 1, old, newcol);

	    // recursive call for left pixel fill
	    floodFill(x, y - 1, old, newcol);

	    // recursive call for bottom-right corner pixel fill
        floodFill(x + 1, y + 1, old, newcol);

	    // recursive call for top-right corner pixel fill
        floodFill(x - 1, y + 1, old, newcol);

	    // recursive call for bottom-left corner pixel fill
        floodFill(x + 1, y - 1, old, newcol);

	    // recursive call for top-left corner pixel fill
        floodFill(x - 1, y - 1, old, newcol);
    }
}

void main()
{
    int gd = DETECT, gm;
    int left, top, right, bottom;

    printf("Enter the left point: ");
    scanf("%d", & left);

    printf("Enter the top point: ");
    scanf("%d", & top);

    printf("Enter the right point: ");
    scanf("%d", & right);

    printf("Enter the bottom point: ");
    scanf("%d", & bottom);

    initgraph(& gd, & gm, "C:\\TURBOC3\\BGI");

    rectangle(left, top, right, bottom);

    floodFill(left + 1, top + 1, 0, 15);

    getch();
    closegraph();
}

// Sample input - https://imgur.com/css9qIj
// Sample output - https://imgur.com/0N0Kjr8
