#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(){
    int gd=DETECT,gm;
    int xc,yc,x=0,y=0,r,p;
    initgraph(&gd,&gm,"C://TURBOC3//BGI");
    printf("Enter center and radious:\t");
    scanf("%d%d%d",&xc,&yc,&r);
    p=1-r;
    y=r;
    cleardevice();
    while(x<=y){
         if(p<0){
        x=x+1;
        y=y;
        p=p+2*x+1;
         }
         else{
        x=x+1;
        y=y-1;
        p=p+2*x+1-2*y;
         }
         putpixel(x+xc,y+yc,WHITE);
         putpixel(x+xc,-y+yc,WHITE);
         putpixel(-x+xc,y+yc,WHITE);
         putpixel(-x+xc,-y+yc,WHITE);
         putpixel(y+xc,x+yc,WHITE);
         putpixel(y+xc,-x+yc,WHITE);
         putpixel(-y+xc,x+yc,WHITE);
         putpixel(-y+xc,-x+yc,WHITE);

    }
    getch();
    closegraph();
}
