#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(){
	int x1,y1,x2,y2,dx,dy,x,y,endx,endy,p;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	printf("Enter coordinates of first point: ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter cooridnates of second point: ");
	scanf("%d%d",&x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy)){
		if(x1>x2){
			x=x2;
			y=y2;
			endx=x1;
		}else{
			x=x1;
			y=y1;
			endx=x2;
		}
		p=2*dy-dx;
		while(x<endx){
			putpixel(x,y,WHITE);
			if(p<0){
				p=p+2*dy;
			}else{
				y++;
				p=p+2*dy-2*dx;
			}
			x++;
		}
	}
	else{
		if(y1>y2){
			y=y2;
			x=x2;
			endy=y1;
		}else{
			x=x1;
			y=y1;
			endy=y2;
		}
		dx=abs(dx);
		dy=abs(dy);
		p=2*dx-dy;
		while(y<endy){
			putpixel(x,y,RED);
			if(p<0){
				p=p+2*dx;
			}else{
				x++;
				p=p+2*dx-2*dy;
			}
			y++;
		}

	}
	getch();

}
