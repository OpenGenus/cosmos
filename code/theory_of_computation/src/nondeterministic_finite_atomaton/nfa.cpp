#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <math.h> 

int row = 0; 

struct node 
{ 
	int data; 
	struct node* next; 
	char edgetype; 

}typedef node; 

node* push(node* first , char edgetype , int data) 
{ 
	node* new_node = (node*)malloc(sizeof(node)); 
	new_node->edgetype = edgetype; 
	new_node->data = data; 
	new_node->next = NULL; 
	if (first==NULL) 
	{ 
		first = new_node; 
		return new_node; 
	} 
	first->next = push(first->next,edgetype,data); 
	return first; 
} 

int nfa(node** graph, int current, char* input, 
		int* accept, int start) 
{ 
	if (start==(int)strlen(input)) 
		return accept[current]; 

	node* temp = graph[current]; 
	while (temp != NULL) 
	{ 
        if (input[start]==temp->edgetype) 
        if (nfa(graph,temp->data,input,accept,start+1==1)) return 1; 
	    temp=temp->next; 
	} 
	return 0; 
} 

void generate(char** arr, int size, char *a) 
{ 
	if (size==0) 
	{ 
		strcpy(arr[row], a); 
		row++; 
		return; 
	} 
	char b0[20] = {'\0'}; 
	char b1[20] = {'\0'}; 
	b0[0] = '0'; 
	b1[0] = '1'; 

	generate((char**)arr, size-1, strcat(b0,a));
	generate((char**)arr, size-1, strcat(b1,a));
	return; 
} 

int main() 
{ 
	int n; 
	int i, j; 
	scanf("%d", &n);
	node* graph[n+1];  

	for (i=0;i<n+1;i++) 
		graph[i]=NULL; 


	int accept[n+1];

	for (i=0; i<n; i++) 
	{ 
		int index,acc,number_nodes; 
		scanf("%d%d%d",&index,&acc,&number_nodes); 
		accept[index]=acc;
		for (j=0;j<number_nodes;j++)
		{ 
			int node_add; 
			int edge; 
			scanf("%d%d",&edge,&node_add); 
			graph[index] = push(graph[index],'0'+edge,node_add); 
		} 
	} 

	int size = 1, count = 0; 

	if (accept[1]==1) 
	{ 
		printf("e\n"); 
		count++; 
	} 

	while (count < 11) 
	{ 
		char** arr; 
		int power = pow(2,size); 
		arr = (char**)malloc(power*sizeof(char*)); 

		for (i=0;i<power;i++) 
			arr[i] = (char*)malloc(size*sizeof(char)); 

		char a[20] = {'\0'}; 

		generate((char**)arr,size,a);

		for (i=0; i<power; i++) 
		{ 
			char input[20] = {'\0'}; 

			for (j=0; j<size; j++) 
			{ 
				char foo[2]; 
				foo[0] = arr[i][size-1-j]; 
				foo[1] = '\0'; 
				strcat(input,foo); 
			} 

			int result = nfa(graph,1,input,accept,0); 

			if (result==1) 
			{ 
				printf("%s\n",input); 
				count++; 
			} 
			if (count==10) 
				return 0; 
		} 
		size++;
		row=0; 
	} 
	return 0; 
} 
