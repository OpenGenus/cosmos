#include <stdio.h>

#define asize 100
#define min(a, b) (((a) < (b)) ? (a) : (b))

struct heap
{
	int a[asize];
	int hsize ;
} H;

void 
swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void 
heapInsert(int key)
{
	++H.hsize;
	H.a[H.hsize] = key;
	int i = H.hsize;
	while (i > 1 && H.a[i] < H.a[i / 2]) {
		swap(&H.a[i], &H.a[i / 2]);
		i = i / 2;
	}
	printf("%d is inserted in Min Heap \n", key);
}

void 
displayHeap()
{
	int i;
	printf("Elements in the heap:- \n");
	for (i = 1; i <= H.hsize; i++)
		printf("%d ", H.a[i]);
	printf("\n");
}

void delMin()
{
	if (H.hsize == 0) {
		printf("Heap is empty,No element can be popped out \n");
		return;
	}

	int x = H.a[1];
	H.a[1] = H.a[H.hsize];
	--H.hsize;
	int i = 1;
	
	while ((2 * i) <= H.hsize) {
		if ((2 * i) + 1 <= H.hsize && H.a[i] > min(H.a[2 * i], H.a[(2 * i) + 1])) {
			if (H.a[(2 * i) + 1] < H.a[2 * i]) {
				swap(&H.a[i], &H.a[(2 * i) + 1]);
				i=(2 * i) + 1;
			}
			else {
				swap(&H.a[i], &H.a[(2 * i)]);
				i=2 * i;	
			}

		}
		else if ((2 * i) + 1 > H.hsize && H.a[i] > H.a[2 * i]) {
			swap(&H.a[i], &H.a[(2 * i)]);
			break;
		}
		else
			break;
	}
	printf("%d is popped out \n", x);

}

int 
main()
{
	int key, ch;
	H.hsize = 0;
	while (1) {
		printf("1.Insert\n2.Display Min Heap\n3.Pop out Minimum element\n4.Exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1 :
				printf("Enter integer to be inserted \n");
				scanf("%d", &key);
				heapInsert(key);
				break;

			case 2 :
				displayHeap();
				break;	

			case 3 :
				delMin();
				break;

			case 4 :
				return (0);
		}
	}
}