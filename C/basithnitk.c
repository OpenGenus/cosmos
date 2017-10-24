[3#include<stdio.h>
#include<string.h>
int main()
{       int d,m,y,flag=1;char day[10];

        printf("enter date and day in the following format\ndd/mm/yyyy, day\neg:17/02/2012, tuesday\n");
        scanf("%d/%d/%d, ",&d,&m,&y);
        scanf("%s",day);


        if(m==1||m==3||m==5||m==7||m==8||m==10)
                if(d>0&&d<32)
                        if(d==31)
                        {
                                d=1;m++;
                        }
                        else d++;
                else flag=0;
        else if(m==4||m==6||m==9||m==11)
                if(d>0&&d<31)
                        if(d==30)
                        {
                                d=1;m++;
                        }
                        else d++;
                else flag=0;
        else if(m==12)
                if(d>0&&d<32)
                        if(d==31)
                        {
                                d=1;m=1;y++;
                        }
                        else d++;
                else flag=0;
        else if(m==2)
                if(y%4==0)
                        if(d>0&&d<30)
                                if(d==29)
			
