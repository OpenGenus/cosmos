#include <stdio.h>
#include <stdlib.h>

//gives the parent value.
int parent(int i){
	int p;
	if(i%3==0){p=i/3-1;}
	else{p=i/3;}
	return p;
}

void choices()
{
	printf("\n\nYou have following chices.\n");
	printf("i or I: \tTo insert a new element into the heap.\n");
	printf("d or D: \tTo delete the minimum element from the list.\n");
	printf("q or Q: \tTo quit.\n\n");
}

//minheap function. Building heap ne by one.
void minheapify(int a[],int size){
	for(int i=1;i<size;i++){
		int s=i;
		int p=parent(s);
	
		//if parent value > child value swap the two.
		while(p>=0 && a[s]<a[p]){
			int key=a[s];
			a[s]=a[p];
			a[p]=key;
			s=p;
			p=parent(s);
		}
		
	}
}

//insert function to insert in the heap.
int insert(int a[],int x,int size){
	size++;			//increase the size of the heap by one and insert the element at the last position
	a[size-1]=x;
	minheapify(a,size);		//minheapify the heap as minheap property may not be followed after insertion 
	return size;
}

int deletemin(int a[],int size){
	
	//check if size is zero
	if(size==0){printf("can not delete from empty heap\n");}

	else{
		a[0]=a[size-1];	//the first element is replaced by the last and decrease the size by one.
		size--;
		minheapify(a,size); 	//apply minheapify
		return size;
	}
}


//to print the heap.
void showheap(int a[],int size){
	printf("\n\nThe heap is.\n");
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

//main starts here
int main(){
	int n;
	int x;
	char c;

	printf("\nEnter the no. of elements in the heap.\n");
	scanf("%d",&n);

	int a[1000];
	int size=0;

	printf("\nEnter the elements to be inserted into the heap.\n");
	//insert all he numbers into the heap
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		size=insert(a,x,size);
	}
	
	//showheap after insertion
	showheap(a,size);
	choices();
	printf("Enter your choice.\n");
	scanf("%c",&c);
	scanf("%c",&c);	
	
	//exit condition is that c=q or Q
	while(c!='q' || c!='Q'){

		//if insert command is given
		if(c=='i' || c=='I'){
			printf("Enter the value.\n");
			scanf("%d",&x);
			size=insert(a,x,size);
			printf("%d is inserted\n",x);
			showheap(a,size);
		}

		//if delete command is given.
		if(c=='d' || c=='D'){
			if(size==0)
			{
				printf("\nCan not delete from an empty heap.\n");
			}
			else
			{
				printf("%d is deleted\n",a[0]);
				size=deletemin(a,size);
				showheap(a,size);
			}
		}
		printf("Enter your choice.\n");
		scanf("%c",&c);
		scanf("%c",&c);

		if(c=='q' || c=='Q') break;
	}

	
	return 0;
}
