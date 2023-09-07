# include <stdio.h>
# include <dos.h>
# include <iostream.h>
# include <conio.h>
# include <stdlib.h>
# include <graphics.h>

void FloodFill(int,int,int,int);
void MidPoint(int);
void main()
{
    int xCenter=320;
    int yCenter=240;
    int gDriver = DETECT, gMode, errorcode;
    initgraph(&gDriver, &gMode, "c:\\tc\\bgi");
    cleardevice();
    MidPoint(49);

    FloodFill(xCenter+1,yCenter+1,0,8);
    getch();
    return;
}

void MidPoint(int Radius)
{
    int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=320;
    int yCenter=240;

    p0=(5/4)-Radius;

    putpixel(xCenter+x,yCenter+y,15);
    putpixel(xCenter-x,yCenter+y,15);
    putpixel(xCenter+x,yCenter-y,10);
    putpixel(xCenter-x,yCenter-y,10);
    putpixel(xCenter+y,yCenter+x,12);
    putpixel(xCenter-y,yCenter+x,12);
    putpixel(xCenter+y,yCenter-x,9);
    putpixel(xCenter-y,yCenter-x,9);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }

        putpixel(xCenter+x,yCenter+y,15);
        putpixel(xCenter-x,yCenter+y,15);
        putpixel(xCenter+x,yCenter-y,10);
        putpixel(xCenter-x,yCenter-y,10);
        putpixel(xCenter+y,yCenter+x,12);
        putpixel(xCenter-y,yCenter+x,12);
        putpixel(xCenter+y,yCenter-x,9);
        putpixel(xCenter-y,yCenter-x,9);

    }

}
void FloodFill(int pointx,int pointy,int OldColor,int NewColor)
{
    int Intensity=getpixel(pointx,pointy);
    if(Intensity==OldColor)
    {
        putpixel(pointx,pointy,NewColor);
        FloodFill(pointx+1,pointy,OldColor,NewColor);
        FloodFill(pointx-1,pointy,OldColor,NewColor);
        FloodFill(pointx,pointy+1,OldColor,NewColor);
        FloodFill(pointx,pointy-1,OldColor,NewColor);
    }
}
