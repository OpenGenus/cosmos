#include <stdio.h>

long long int a[101][101];

void pascal_triangle()
{
	for(int i=0;i<101;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i){
				a[i][j]=1;
			}
			else{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}

		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	pascal_triangle();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			printf("%lli ",a[i][j]);
		}
		printf("\n");
	}
		
	return (0);
}
