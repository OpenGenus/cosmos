//For Hacktoberfest 2021
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
int poly[30], a[9][3], b[3][3], c[9][3], poly2[30];
int x,y,p,i,j,k,xc,yc;
int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
xc=getmaxx()/2;
yc=getmaxy()/2;
printf("\n Enter number of points : ");
scanf("%d",&p);
j=0;
for(i=0;i<p*2;i+=2)
{
printf("\n Enter cordinate point x%d and y%d : ",j+1,j+1);

scanf("%d",&poly[i]);
scanf("%d",&poly[i+1]);
j++;
}
poly[p*2]=poly[0];
poly[p*2+1]=poly[1];



for(i=0;i<p*2;i+=2)
{
poly2[i]=xc+poly[i];
poly2[i+1]=yc-poly[i+1];

}
poly2[p*2]=poly2[0];
poly2[p*2+1]=poly2[1];

fillpoly(p+1,poly2);


line(0,yc,xc*2,yc);
line(xc,0,xc,yc*2);
j=0;
for(i=0;i<p;i++)
{
 a[i][0]=poly[j];
 a[i][1]=poly[++j];
 a[i][2]=1;
 ++j;
}
for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
     {
       b[i][j]=0;
       if(i==j)
       {
       b[i][j]=1;
       }
     }
    }
    b[1][1]=-1;
for(i=0;i<p;i++)
{

   for(j=0;j<3;j++)
   {
   c[i][j]=0;
     for(k=0;k<3;k++)
     {
 c[i][j]=c[i][j]+a[i][k]*b[k][j];
     }
   }

 }
printf("\n\n\t Reflection : ");


for(i=0,j=0;i<p;i++,j+=2)
{
poly[j]  =xc+c[i][0];
poly[j+1]=yc-c[i][1];
}
poly[j]  =poly[0];
poly[j+1]=poly[1];

setfillstyle(9,2);
fillpoly(p+1,poly);

getch();
closegraph();
}
