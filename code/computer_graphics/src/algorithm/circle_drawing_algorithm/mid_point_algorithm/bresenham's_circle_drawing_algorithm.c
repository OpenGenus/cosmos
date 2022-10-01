#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(){
    int gd=DETECT,gm;
    int xc,yc,x,y,r;
    int x,y,p;
    initgraph(&gd,&gm,"C://TURBOC3//BGI");
    scanf("%d%d%d",&xc,&yc,&r);
    x=0;
    y=r;
    p=3-2*r;
    while(x<=y){
        putpixel(x+xc,y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(y+xc,x+yc,WHITE);
        putpixel(y+xc,-x+yc,WHITE);
        putpixel(-y+xc,x+yc,WHITE);
        putpixel(-y+xc,-x+yc,WHITE);

        if(p<0){
            x=x+1;
            p=p+4*x+6;
        }
        else{
            x=x+1;
            y=y-1;
            p=p+4*(x-y)+10;
        }

    }
    getch();
    closegraph();
}
