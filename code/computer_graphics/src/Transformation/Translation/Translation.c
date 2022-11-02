#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(){
	int x0,y0,x1,y1,tx,ty;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	printf("Enter coordinates of first point:\t");
	scanf("%d%d",&x0,&y0);
	printf("Enter coordinates of second point:\t");
	scanf("%d%d",&x1,&y1);
	printf("Enter coordinates of translation:\t");
	scanf("%d%d",&tx,&ty);
	setcolor(RED);
	line(x0,y0,x1,y1);
	setcolor(GREEN);
	line(x0+tx,y0+ty,x1+tx,y1+ty);
  printf("RED:- Initial\nGreen:- Translated")
	getch();
	closegraph();
}
