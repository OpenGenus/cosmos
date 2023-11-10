#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
	int a[2],b[2],c[2],scale[2],i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");

	printf("Enter value of a:\t");
	scanf("%d%d",&a[0],&a[1]);

	printf("Enter value of b:\t");
	scanf("%d%d",&b[0],&b[1]);

	printf("Enter value of c:\t");
	scanf("%d%d",&c[0],&c[1]);

	printf("Enter value of scale:\t");
	scanf("%d%d",&scale[0],&scale[1]);
	setcolor(RED);
	line(b[0],b[1],c[0],c[1]);
	line(a[0],a[1],b[0],b[1]);
	line(a[0],a[1],c[0],c[1]);
	setcolor(GREEN);
	a[0]=scale[0]*a[0];
	a[1]=scale[1]*a[1];
	b[0]=scale[0]*b[0];
	b[1]=scale[1]*b[1];
	c[0]=scale[0]*c[0];
	c[1]=scale[1]*c[1];
	line(b[0],b[1],c[0],c[1]);
	line(a[0],a[1],b[0],b[1]);
	line(a[0],a[1],c[0],c[1]);
	getch();
}