#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
int main(){
    int gd=DETECT, gm;
    float x1,y1,x2,y2;
    float x,y,i;
    float slope;
    float dx,dy;
    initgraph(&gd,&gm,"C://TURBOC3//BGI");
    scanf("%f %f %f %f", &x1,&y1,&x2,&y2);

    dx=x2-x1;
    dy=y2-y1;
    printf("%f %f", dx,dy);
    if(dx>=dy)    slope=dx;
    else    slope=dy;
    dx=dx/slope;
    dy=dy/slope;
    x=x1;
    y=y1;
    i=1;
    while(i<=slope){
        putpixel((int)(x),(int)y,YELLOW);
        x=x+dx;
        y=y+dy;
        i=i+1;
        delay(10);
    }
    getch();
    closegraph();
}
