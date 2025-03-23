//for directed acyclig graphs!!
// Part of Cosmos by OpenGenus Foundation
#include<stdio.h>
#include<stdlib.h>
#define INF 999999
typedef struct node graph;
struct node{
	int val;
	graph *next;
	int weight;
};
int src;
int wt_ans,val_ans;
int heap_count;
int flag[1000000];
struct node table[1000000];
struct node a[1000000];

void insert_vertex(int n){
	int i;
	for(i=1;i<=n;i++){
		table[i].next=NULL;
		table[i].weight=0;	
	}
}

void insert_edge(int x,int y,int w){
	graph *one;
	one=(graph*)malloc(sizeof(graph));
	one->val=y;
	one->weight=w;
	one->next=NULL;
	graph *tmp;
	if(table[x].next==NULL){
		table[x].next=one;
	}
	else{
		tmp=table[x].next;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=one;
	}
}
void insert_heap(int n){
	int l,i;
	for(i=1;i<=n;i++){
		a[i].weight=INF;
		a[i].val=i;
	}
}

void update_heap(int x,int y){
	graph tmp;
	int l,k;
	int i;
	if(x==src && x!=1){
		tmp=a[1];
		a[1]=a[x];
		a[x]=tmp;
		a[1].weight=y;
	}
	else if(x!=src){
		for(i=1;i<=heap_count;i++){
			if(a[i].val==x){
				k=i;
				a[k].weight=y;
			}
		}
		while((a[k/2].weight>a[k].weight)&&(k/2>=1)){
			tmp=a[k/2];
			a[k/2]=a[k];
			a[k]=tmp;
			k=k/2;
		}
	}
}

void extract_heap(int z){
	graph tmp;
	graph var;
	tmp=a[1];
	val_ans=tmp.val;
	wt_ans=tmp.weight;
	flag[a[1].val]=1;
	a[1]=a[z];
	heap_count--;
	int k=1;
	while((a[k].weight>a[2*k].weight || a[k].weight > a[2*k+1].weight) && (2*k<=z)){
		if((a[k].weight>a[2*k].weight) && (a[k].weight <= a[2*k+1].weight)){
			var=a[2*k];
			a[2*k]=a[k];
			a[k]=var;
			k=2*k;

		}
		else{
			var=a[2*k+1];
			a[2*k+1]=a[k];
			a[k]=var;
			k=2*k+1;
		}
	}
}	

int check_heap(int x){
	int i,y;
	for(i=1;i<=heap_count;i++){
		if(a[i].val==x){
			y=a[i].weight;
		}
	}
	return y;
}
void print_table(int n){
	graph *tmp,*var;
	int i,j;
	for(i=1;i<=n;i++){
		printf("table[%d]",i);
		tmp=table[i].next;
		while(tmp){
			printf("->%d",tmp->val);
			tmp=tmp->next;
		}
		printf("\n");
	}
}

int main(){
	int n,x,y,w,m;
	int t;
	int v1,v2;
	graph *tmp;
	graph *var,*tmp2;

	n=4;
	m=4;
	insert_vertex(n);
	int i,j,k,l;
	heap_count=n;
	for(i=1;i<=n;i++){
		flag[i]=0;
	}
	

	insert_heap(n);
	int src,dest;
	src=1;
	update_heap(src,0);
	while(heap_count>0){
		extract_heap(heap_count);
		v1=val_ans;
		table[v1].weight=wt_ans;
		tmp2=table[v1].next;
		while(tmp2){
			var=tmp2;
			if(flag[var->val]==0){
				v2=check_heap(var->val);
				if(var->weight+table[v1].weight < v2){
					update_heap(var->val,(var->weight+table[v1].weight));

				}
			}
			tmp2=tmp2->next;
		}
	}
	int q;
	for(q=1;q<=n;q++){
		printf("%d to %d = %d\n",src ,q,table[q].weight);
	}
	return 0;
}
