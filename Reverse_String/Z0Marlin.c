#include<stdio.h>
#include<string.h>
int main(){
char a[50],t;
int i,n;
printf("Input String : ");
n=(scanf("%[^\n]%*c",a),strlen(a));
for(i=0;i<n/2;i++){
	t=a[i];
	a[i]=a[n-1-i];
	a[n-1-i]=t;
}
printf("%s\n",a);
}
