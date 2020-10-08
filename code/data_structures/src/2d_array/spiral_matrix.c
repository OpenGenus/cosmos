/*Part of Cosmos by OpenGenus Foundation*/


#include<stdio.h>
#define Row 4
#define Col 3

void
spiral_matrix(int r, int c, int arr[Row][Col])
{
	int i;
	int k = 0, l = 0;
	while (k < r && l < c)
	{
		for (i = l; i < c ; ++i) {
			printf("%d\t", arr[k][i]);
		}
		k++;
		
		for (i = k; i < r; ++i) {
			printf("%d\t", arr[i][c - 1]);
		}
		c--;
		if (k < r) {
			for (i = c - 1; i >= l; --i) {
				printf("%d\t", arr[r - 1][i]);
			}
		r--;
	    }
	    if (l < c) {
	    	for (i = r - 1 ; i >= k; --i) {
	    		printf("%d\t", arr[i][l]);
			}
			l++;
		}
	}
}

int 
main()
{
    int a[Row][Col] = {{1, 2, 3}, {10, 20, 30}, {110, 220, 330}, {1100, 2200, 3300}};
     
    spiral_matrix (Row, Col, a);
    return (0);
}
	
