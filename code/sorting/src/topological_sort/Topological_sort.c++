#include<iostream>

using namespace std;

int main(){
	int i,j,k,n,arr[10][10],indg[10],flag[10],count=0;
 
	cout<<"Enter the no of vertices:\n";
	cin>>n;
 
	cout<<"Enter the adjacency matrix:\n";
	for(i=0;i<n;i++){
		cout<<"Enter row "<<i+1<<"\n";
		for(j=0;j<n;j++)
			cin>>arr[i][j];
	}
 
	for(i=0;i<n;i++){
        indg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indg[i]=indg[i]+arr[j][i];
 
    cout<<"\nThe topological order is:";
 
    while(count<n){
        for(k=0;k<n;k++){
            if((indg[k]==0) && (flag[k]==0)){
                cout<<k+1<<" ";
                flag[k]=1;
            }
 
            for(i=0;i<n;i++){
                if(arr[i][k]==1)
                    indg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}
