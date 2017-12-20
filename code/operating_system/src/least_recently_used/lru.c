#include<stdio.h>
int frame[3]={0,0,0},pref[3]={0,0,0},page[20];
int hita(int a) // counts hit
{
 int n=1,i=0;
  for(i=0;i<3;i++)
      {
       if(frame[i]==a)
          {
           n=0;
           break;
          }
       else
         continue;
     }printf("%d",n);
 return n;
}
void initi(int a,int i)
 {int z=0,min=0,j=0;
 
  for(j=0;j<3;j++) //setting up preference table
    {
     for(z=i;z>=0;z--)
        {
         if(frame[j]==page[i])
             pref[j]=z;
        }
    }
min=pref[0];
   
  for(j=0;j<3;j++) //finds out lowest prefernce value
    {if(min>pref[j])
        min=pref[j];
     else
        continue;
    }
frame[min]=a;
}
void main()
{
int hit=0,temp=0,miss=0,i=0,n=0;
printf("ENter the no of pages");//takes input
for(i=0;i<8;i++)
 scanf("%d",&page[i]);
 
for(i=0;i<3;i++)//intialize first frames
 {
  frame[i]=page[i];
  miss++;
 }
 
for(i=3;i<8;i++)
 {
 temp=hita(page[i]);
  if(temp==0)
   hit++;
  else
     {miss++;
     initi(frame[i],i);}
 }
printf("hit=%d and miss=%d",hit,miss);
}
