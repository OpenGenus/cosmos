#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,S=0;
	cin>>T;
	while(T--)
	{
	    int arr[4][4];
	    for(int i=0;i<4;i++)
	    {
	        for(int j=0;j<4;j++)
	        {
	            arr[i][j]=0;
	        }
	    }
	    int n,t;
	    cin>>n;
	    char m;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>m>>t;
	        arr[int(m)-65][(t/3)-1]++;
	    }
	    if(n==0)
	    {
	        cout<<-400<<endl;
	        S-=400;
	        continue;
	    }
	    int sum[24];
	    int sum_count=0;
	    for(int i=0;i<4;i++)
	    {
	        int temp[4]={0,0,0,0};
                temp[0]=arr[0][i];
	        for(int j=0;j<4;j++)
	        {
	            if(j==i)
	            {
	                continue;
	            }
	            temp[1]=arr[1][j];
	            for(int k=0;k<4;k++)
	            {
	                if(k==i||k==j)
	                {
	                    continue;
	                }
	                temp[2]=arr[2][k];
	                for(int l=0;l<4;l++)
	                {
	                    if(l==i||l==j||l==k)
	                    {
	                        continue;
	                    }
	                    temp[3]=arr[3][l];
	                    int temp2[4];
	                    temp2[0]=temp[0];
	                    temp2[1]=temp[1];
	                    temp2[2]=temp[2];
	                    temp2[3]=temp[3];
	                    sort(temp2,temp2+4);
	                    int s=0;
	                    for(int o=0;o<4;o++)
	                    {
	                        if(temp2[o]==0)
	                        {
	                            s-=100;
	                        }
	                        else
	                        {
	                            s+=temp2[o]*(25*(o+1));
	                        }
	                    }
                            sum[sum_count++]=s;
	                }
	            }
	        }
	    }
	    sort(sum,sum+24);
	    cout<<sum[23]<<endl;
	    S+=sum[23];
	}
	cout<<S;
	return 0;
}
                
	    
