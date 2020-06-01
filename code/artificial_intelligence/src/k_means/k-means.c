// Part of Cosmos by OpenGenus
#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,t1,t2;
    int a0[10];
    int a1[10];
    int a2[10];
 
    printf("\nEnter 10 numbers:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a0[i]);
    }
 
    //initial means
    int m1;
    int m2;
    printf("\nEnter first mean: ");
    scanf("%d",&m1);
    printf("\nEnter second mean: ");
    scanf("%d",&m2);
     
    int om1,om2;    //previous means
 
    do
    {
     om1=m1;
    om2=m2;
 
    //creating clusters
    i=j=k=0;
    for(i=0;i<10;i++)
    {
        //calculating distance to means
        t1=a0[i]-m1;
        if(t1<0){t1=-t1;}
        t2=a0[i]-m2;
        if(t2<0){t2=-t2;}
        if(t1<t2)
        {
            //near to first mean
            a1[j]=a0[i];
            j++;
        }
        else
        {
            //near to second mean
            a2[k]=a0[i];
            k++;
        }
    }
 
    t2=0;
    //calculating new mean
    for(t1=0;t1<j;t1++)
    {
        t2=t2+a1[t1];
    }
    m1=t2/k;
 
    t2=0;
    for(t1=0;t1<k;t1++)
    {
        t2=t2+a2[t1];
    }
    m2=t2/k;
 
    //printing clusters
    printf("\nCluster 1:\n__________\n");
    for(t1=0;t1<j;t1++)
    {
        printf("%d ",a1[t1]);
    }
    printf("\nm1= %d",m1);
 
    printf("\nCluster 2:\n___________\n");
    for(t1=0;t1<k;t1++)
    {
         printf("%d ",a2[t1]);
    }
    printf("\nm2= %d",m2);
    }while(m1!=om1&&m2!=om2);
    getch();
}
