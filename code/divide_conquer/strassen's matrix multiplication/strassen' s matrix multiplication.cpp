/*
 Given a matrix of size nxn. Write a program to calculate square of the input matrix using Strassen’s matrix multiplication algorithm.(2< n < 128 and n will be only powers of 2.)
 */


#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

//BASE CASE
void two(long long int a[131][131],long long int b[131][131],long long int c[131][131]){
    long long int a1=a[1][1],b1=a[1][2],c1=a[2][1],d1=a[2][2],e1=b[1][1],f1=b[1][2],g1=b[2][1],h1=b[2][2];
    long long int p1=a1*(f1-h1),p2=(a1+b1)*h1,p3=(c1+d1)*e1,p4=d1*(g1-e1),p5=(a1+d1)*(e1+h1),p6=(b1-d1)*(g1+h1),p7=(a1-c1)*(e1+f1);
    c[1][1]=a1*e1+b1*g1;
    c[1][2]=a1*f1+b1*h1;
    c[2][1]=c1*e1+d1*g1;
    c[2][2]=c1*f1+d1*h1;
}

void add(long long int a[131][131],long long int b[131][131],long long int n,long long int c[131][131]){
    long long int i=1,j=1;
    while(i<=n){
        for(j=1;j<=n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
        i++;
    }
    return;
}

void subt(long long int a[131][131],long long int b[131][131],long long int n,long long int c[131][131]){
    long long int i=1,j=1;
    for(i=1;i<=n;i++){
        while(j<=n){
            c[i][j]=a[i][j]-b[i][j];
            j++;
        }
        j=1;
    }
    return;
}

void answer(long long int a[131][131],long long int b[131][131],long long int n,long long int c[131][131]){
    long long int i,j;
    if(n==2) { two(a,b,c);return;}
    
    else{
        long long int a11[131][131];
        long long int a12[131][131];
        long long int a21[131][131];
        long long int a22[131][131];
        long long int b11[131][131];
        long long int b12[131][131];
        long long int b21[131][131];
        long long int b22[131][131];
        
        i=1;j=1;
        while(i<=n/2){
            while(j<=n/2){
                
                a11[i][j]=a[i][j];
                b11[i][j]=b[i][j];
                
                a21[i][j]=a[i+(n/2)][j];
                b21[i][j]=b[i+(n/2)][j];
                
                a12[i][j]=a[i][j+(n/2)];
                b12[i][j]=b[i][j+(n/2)];
                
                a22[i][j]=a[i+(n/2)][j+(n/2)];
                b22[i][j]=b[i+(n/2)][j+(n/2)];
                
                j++;
            }
            i++;j=1;
        }
        
        long long int m1[131][131];
        long long int m2[131][131];
        long long int m3[131][131];
        long long int m4[131][131];
        long long int m5[131][131];
        long long int m6[131][131];
        long long int m7[131][131];
        
        long long int temp1[131][131];
        long long int temp2[131][131];
        
        subt(b12,b22,n/2,temp1);
        answer(a11,temp1,n/2,m1);
        
        add(a11,a12,n/2,temp1);
        answer(temp1,b22,n/2,m2);
        
        add(a21,a22,n/2,temp1);
        answer(temp1,b11,n/2,m3);
        
        subt(b21,b11,n/2,temp1);
        answer(a22,temp1,n/2,m4);
        
        add(a11,a22,n/2,temp1);
        add(b11,b22,n/2,temp2);
        answer(temp1,temp2,n/2,m5);
        
        subt(a12,a22,n/2,temp1);
        add(b21,b22,n/2,temp2);
        answer(temp1,temp2,n/2,m6);
        
        subt(a11,a21,n/2,temp1);
        add(b11,b12,n/2,temp2);
        answer(temp1,temp2,n/2,m7);
        
        for(i=1;i<=n/2;i++){
            for(j=1;j<=n/2;j++){
                
                c[i][j]=m5[i][j]+m4[i][j]-m2[i][j]+m6[i][j];
                c[i+(n/2)][j]=m3[i][j]+m4[i][j];
                c[i][j+(n/2)]=m1[i][j]+m2[i][j];
                c[i+(n/2)][j+(n/2)]=m1[i][j]+m5[i][j]-m3[i][j]-m7[i][j];
                
            }
        }
        
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long int t,n,i,j,ma[131][131],ans[131][131];
    cin>>n;//INPUT SIZE
    for(i=1;i<=130;i++){
        for(j=1;j<=130;j++){
            ma[i][j]=0;
            ans[i][j]=0;
        }
    }
    
    //INPUT ARRAY
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>ma[i][j];
        }
    }
    
    answer(ma,ma,n,ans);
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}

