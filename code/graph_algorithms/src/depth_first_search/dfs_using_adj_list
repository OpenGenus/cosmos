/*Time Complexity of this method using adjacency list is O(V+E)*/

#include<stdio.h>
#include<stdlib.h>
struct node{
	int v;
	int w;
	struct node *next;
};
struct vertex{
	int v;
	int colour;
	int p;
	struct vertex *next;
};
struct vertex *stack=NULL;
void print_graph(struct node *vertices[], int n, int e){
	int i;
	struct node *sptr;
	for(i=0;i<n;i++){
		sptr=vertices[i];
		while(sptr!=NULL&&sptr->next!=NULL){
			printf("%d %d\n",sptr->v,sptr->w);
		}
		printf("%d %d\n",sptr->v,sptr->w);
	}
}
void make_graph(struct node *vertices[], int n, int e){
	int a,i;
	struct node *sptr;
	printf("Enter edge in form 'a b w' where w is weight of edge from a to b\n");
	for(i=0;i<e;i++){
		struct node *t=malloc(sizeof(struct node));
		t->next=NULL;
		scanf("%d %d %d", &a, &(t->v), &(t->w));
		sptr=vertices[a];
		while(sptr!=NULL&&sptr->next!=NULL){
			sptr=sptr->next;
		}
		if(sptr==NULL)
			vertices[a]=t;
		else
			sptr->next=t;
	}
}
void push(struct vertex * a){
	a->colour=1;
	struct vertex * sptr;
	if(stack==NULL){
		stack=a;
	}
	else{
		a->next=stack;
		stack=a;
	}
}
struct vertex * pop(){
	struct vertex *a=stack;
	if(stack->next==NULL)
		stack=NULL;
	else
		stack=stack->next;
	return a;
}
void dfs(struct node *vertices[],struct vertex *visited[], int n, int e){
	printf("Enter source\n");
	int k;
	scanf("%d",&k);
	push(visited[k]);
	visited[k]->p=k;
	while(stack!=NULL){
			struct vertex *u=pop();
			if(visited[u->v]->colour==1){
			visited[u->v]->colour=2;
			struct node *sptr=vertices[u->v];
			while(sptr!=NULL){
				if(visited[sptr->v]->colour==0){
					push(visited[sptr->v]);
					visited[sptr->v]->p=u->v;
				}
				else if(visited[sptr->v]->colour==1)
					visited[sptr->v]->p=u->v;
				sptr=sptr->next;
			}
			}
	}
}
void main(){
	int n,e,i;
	struct node *sptr;
	printf("Enter no. of vertices in the graph\n");
	scanf("%d",&n);
	struct node * vertices[n];
	struct vertex * visited[n];
	for(i=0;i<n;i++){
		vertices[i]=NULL;
	}
	for(i=0;i<n;i++){
		struct vertex *t=malloc(sizeof(struct vertex));
		t->v=i;
		t->colour=0;
		t->p=0;
		t->next=NULL;
		visited[i]=t;
	}
	printf("Enter no. of edges in graph");
	scanf("%d",&e);
	make_graph(vertices, n, e);
	dfs(vertices,visited,n,e);
	for(i=0;i<n;i++){
		printf("\n%d	%d",visited[i]->v, visited[i]->p);
	}
}
