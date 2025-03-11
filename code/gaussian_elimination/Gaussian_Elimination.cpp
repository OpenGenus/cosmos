#include<math.h>
#include<iostream>
using namespace std;
int main(){
    float a[10][10],*temp,app,sum,mult;
    int i,j,k,n,p;

    cout<<"Enter n : "<<endl;
    cin>>n;
    temp = (float*)malloc(n*sizeof(float));
    cout<<"Enter the elements of augmended matrix:\n";
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    // generation of scalar matrix
    for(i=0;i<n;i++){
        app = a[i][i];
        p = i;
    // find largest no of the columns and row no. of largest no.
    for(k = i+1; k < n; k++)
    if(fabs(app) < fabs(a[k][i])){
       app = a[k][i] ;
       p = k;
    }
    // swaping the elements of diagonal row and row containing largest no
    for(j = 0; j <= n; j++){
        temp[j] = a[p][j];
        a[p][j] = a[i][j];
        a[i][j] = temp[j];
    }
    // calculating triangular matrix
    for(j=i+1;j<n;j++){
        mult = a[j][i]/a[i][i];
        for(k=0;k<=n;k++)
            a[j][k] -= mult*a[i][k];
            }
    }
       
    //for calculating value of z,y,x via backward substitution method
    for(i=n-1;i>=0;i--){
        sum = 0;
        for(j=i+1;j<n;j++)
            sum += a[i][j]*temp[j];
            temp[i] = (a[i][n]-sum)/a[i][i];
    }
    cout<<"The matrix is :\n";
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++)
            cout<<a[i][j];
            cout<<endl;
    }

    cout<<"Solution is:\n";
    for(i=0;i<n;i++)
    printf("x[%d] = %.2f\n",i+1,temp[i]);
    return 0;
}

    
