#include <graphics.h>
#include <conio.h>
void flood_fill4(int x,int y,int newColor,int oldColor)
{
int c;
c=getpixel(x,y);
if(c==oldColor)
{
setcolor(newColor);
putpixel (x,y,newColor);
delay(10);
flood_fill4(x+1,y,newColor,oldColor);
flood_fill4(x,y+1,newColor,oldColor);
flood_fill4(x-1,y,newColor,oldColor);
flood_fill4(x,y-1,newColor,oldColor);
}
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
rectangle(250,200,300,250);
flood_fill4(251,201,4,0); // 4(red) - newColor  0(black) - oldColor
          // x y point should be one greater than rectangle border
getch();
closegraph();
}