// Part of Cosmos by OpenGenus
//Sample Input and Output:
//
//------------------------
//Number of data points: 5
//
//Enter the dataset values:
//w       x       y       z       op
//1       2       4       3       1
//1       3       2       1       1
//8       7       6       9       2
//7       8       6       9       2
//6       9       7       5       2
//w       x       y       z       op
//1.00    2.00    4.00    3.00    1
//1.00    3.00    2.00    1.00    1
//8.00    7.00    6.00    9.00    2
//7.00    8.00    6.00    9.00    2
//6.00    9.00    7.00    5.00    2
//
//Enter the feature values of the unkown point:
//w       x       y       z
//8       7       5       9
//w       x       y       z       op      distance
//8.00    7.00    6.00    9.00    2       1.00
//7.00    8.00    6.00    9.00    2       1.73
//6.00    9.00    7.00    5.00    2       5.29
//1.00    2.00    4.00    3.00    1       10.54
//1.00    3.00    2.00    1.00    1       11.75
//
//Number of nearest neighbors(k): 2
//
//The class of unknown point is: 2
//
//---------Code---------------

#include <stdio.h>
#include <math.h>
#include <string.h>

struct point {
	float w,x,y,z;
	float distance;
	int op;	
};

int main(){
	int i,j,n,k;
	point p;
	point temp;
	printf("Number of data points: ");
	scanf("%d",&n);
	point arr[n];
	printf("\nEnter the dataset values: \n");
	printf("w\tx\ty\tz\top\n");
	
	// Taking input data
	for (i=0;i<n;i++){
		scanf("%f%f%f%f%d",&arr[i].w,&arr[i].x,&arr[i].y,&arr[i].z,&arr[i].op);	
	}
	printf("w\tx\ty\tz\top\n");
	for (i=0;i<n;i++){
		printf("%.2f\t%.2f\t%.2f\t%.2f\t%d\n",arr[i].w,arr[i].x,arr[i].y,arr[i].z,arr[i].op);
	}
	printf("\nEnter the feature values of the unkown point: \nw\tx\ty\tz\n");
	scanf("%f%f%f%f",&p.w,&p.x,&p.y,&p.z);
	
	//Measuring the Euclidean distance
	for (i=0;i<n;i++){
		arr[i].distance=sqrt((arr[i].w - p.w) * (arr[i].w - p.w) + (arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y) + (arr[i].z - p.z) * (arr[i].z - p.z));	
	}
	
	//Sorintg the training data w.r.t distance	
	for (i = 1; i < n; i++){
	  for (j = 0; j < n - i; j++) {
	     if (arr[j].distance > arr[j + 1].distance) {
	        temp = arr[j];
	        arr[j] = arr[j + 1];
	        arr[j + 1] = temp;
	     }
	  }
	}
	printf("w\tx\ty\tz\top\tdistance\n");
	for (i=0;i<n;i++){
		printf("%.2f\t%.2f\t%.2f\t%.2f\t%d\t%.2f\n",arr[i].w,arr[i].x,arr[i].y,arr[i].z,arr[i].op,arr[i].distance);
	}
	
	// Taking the K -nearest neighbors
	printf("\nNumber of nearest neighbors(k): ");
	scanf("%d",&k);
	int freq1 = 0;	// for class 1
	int freq2 = 0;  // for class 2  
	int freq3 = 0;  // for class 3
	int none = 0;			
	for (int i = 0; i < k; i++){ 
	    if (arr[i].op == 1) 
	        freq1++; 
	    else if (arr[i].op == 2) 
	        freq2++; 
	    else if(arr[i].op==3)
	    	freq3++;
	    else
	    	none++;
	} 
	if(freq1>= freq2 && freq1 >= freq3){
		printf("\nThe class of unknown point is: 1");
	}
	else if(freq2>= freq1 && freq2 >= freq3){
		printf("\nThe class of unknown point is: 2");
	}
	else{
		printf("\nThe class of unknown point is: 3");	
	}
}

