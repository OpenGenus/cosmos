#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int colordfs;
	int colorbfs;
	struct node *next;
	struct node *parentdfs;
	struct node *parentbfs;
	int d;
	int f;
};

struct node *make()
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->colordfs=-1;
	p->next=NULL;
	p->parentdfs=NULL;
	p->d=-1;
	p->f=-1;
	return p;
}

int dfs_visit(struct node *a[],struct node *p,int time)
{
	time++;
	p->colordfs=0;
	p->d=time;
	//printf("discovery time for %d is %d\n",p->data,time );
	struct node *u=p;
	while(u->next!=NULL)
	{
		u=u->next;
		if(a[u->data]->colordfs==-1)
		{
			a[u->data]->parentdfs=p;
			printf("Edge %d------%d is Tree Edge\n",p->data,a[u->data]->data);
			time=dfs_visit(a,a[u->data],time);
		}

		else if(a[u->data]->colordfs==0)
		{
			printf("Edge %d--------%d is a back edge.\n",p->data,a[u->data]->data);
		}

		else if(a[u->data]->colordfs==1)
		{
			if(a[u->data]->d > p->d)
			{
				printf("Edge %d--------%d is a forward edge\n",p->data,a[u->data]->data);
			}
			else
			{
				printf("Edge %d--------%d is a cross edge\n",p->data,a[u->data]->data);
			}
		}
	}

	p->colordfs=1;
	time++;
	p->f=time;
	// printf("Finishing time for %d is %d\n",p->data,time);
	return time;
}

void dfs(struct node *a[],int v)
{
	for(int i=1;i<v+1;i++)
	{
		a[i]->colordfs=-1;
		a[i]->parentdfs=NULL;
	}

	int time=0;
	for(int i=1;i<v+1;i++)
	{
		if(a[i]->colordfs==-1)
		{
			time=dfs_visit(a,a[i],time);
		}
	}
}

void path(struct node *a[],int i,int j)
{
	struct node *p= a[i];
	struct node *q=a[j];
	int que[100];
	int r=-1;
	int f=0;
	if(a[i]->parentdfs==NULL && a[j]->parentdfs==NULL)
	{
		printf("No path.\n");
	}

	else if(a[i]->parentdfs!=NULL)
		{
			struct node *t=a[i];
			while(t!=NULL)
			{
				que[++r]=t->data;
				//printf("Enqueued %d\n",que[r]);
				if(t->data=a[j]->data) 
				{
					//printf("break used equality at %d\n",t->data);
					break;
				}
				else t=t->parentdfs;
			}

			if(que[r]==a[j]->data)
			{
				printf("There exists a path. As dfs is used, not the shortest but a path is:\t");
				while(r>=f)
				{
					printf("%d ",que[f++]);
				}
			}
			printf("\n");
		}

		else
		{
			struct node *t=a[j];
			while(t!=NULL)
			{
				que[++r]=t->data;	
				//printf("Enqueued %d\n",que[r]);
				if(t->data==a[i]->data) 
				{	
					//printf("break equality for %d\n",t->data);
					break;
				}
				else t=t->parentdfs;
			}

			if(que[r]==a[i]->data)
			{
				printf("There exists a path. As dfs is used, not the shortest but a path is:\t");
				while(r>=f)
				{
					printf("%d ",que[f++]);
				}
			}
			printf("\n");
		}
	
}


int main()
{

	printf("Program to find Tree edges, Back edges, Forward edges, Cross edges.\n");
	printf("Also to find whether there exists a path between two nodes.\n");
	printf("\n\n\n\n");
	int e,v;
	printf("Enter the no.of the vertices and edges in the graph.\n");
	scanf("%d%d",&v,&e);
	printf("Note that this is a directed graph.\n");
	struct node *a[v+1];
	for(int i=0;i<v+1;i++)
	{
		a[i]=make();
		a[i]->data=i;
	}

	printf("Enter the connected edges.\n");
	for(int i=0;i<e;i++)
	{
		int x,y;

		scanf("%d%d",&x,&y);
		struct node *p=make();
		p->data=x;
		struct node *q=make();
		q->data=y;
		if(a[x]->next==NULL)
		{
			a[x]->next=q;
		}
		else
		{
			q->next=a[x]->next;
			a[x]->next=q;
		}

		/*if(a[y]==NULL)
		{
			a[y]->next=p;
		}
		else
		{
			p->next=a[y]->next;
			a[y]->next=p;
		}*/

	}

	for(int i=0;i<v+1;i++)
	{
		struct node *t=a[i];
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
	}

	dfs(a,v);
	int vi,vj;
	printf("\n\nEnter the integers between which path is to be found out.\n\n");
	scanf("%d%d",&vi,&vj);
	printf("\n\n\n");
	path(a,vi,vj);
	return 0;
}
