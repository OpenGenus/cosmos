#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct node
{
    int degree;
    node *child;
    int mark;//no use of mark in this program
    int key;
    node *left;
    node *right;
    node *parent;
    int flagg;//flagg denotes whether we have traversed the node in root list in consolidate function
};
struct heap
{
    int n;//n is the total number of nodes in the heap
    node *minn;//minn points to the node in the rootlist which has the minimum key
};
node * union1(node *head1,node *head2 );
void print(node *list , int depth );
heap *FibHeapUnion(heap *H1,heap *H2);
void insertInHeap(heap *H,node *x);
void insertInHeapp(heap *H,node *tmp);
heap *makeHeap();void HeapLink(heap *h,node *x,node *y);
node *getNode(int x);
void consolidate(heap *h);
node *extractMin(heap *h);
int main()
{
    heap *H;
    char ch;int flag,cnt=0;node *t;string dump;
    //Printing the menu
    cout<<"\nOption c for MAKE-FIB-HEAP\nOption u for FIB-HEAP-UNION\nOption i for FIB-HEAP-INSERT\n";
    cout<<"Option e for FIB-HEAP-EXTRACT-MIN\nOption - for Turn off Print after extract min\nOption + for Turn on print after extract min";
    cout<<"\nOption s for show heap\nOption q for exit\n";node *tmpp;
    do
    {
        cin>>ch;
        switch(ch)
        {
        case 'c'://Create Empty Heap Operation
                 H=makeHeap();
                 break;//break statement to avoid fall through

        case 'i'://Insert Operation
                 int x;
                 cin>>x;
                 insertInHeap(H,getNode(x));
                 break;

        case 'u':
                 FibHeapUnion(H,NULL);
                 break;

        case 'e'://Extract Min Operation
                 t=extractMin(H);
                 if(t==NULL)
                    cout<<"Cannot extract min from empty heap!"<<endl;
                 else if(flag==1)
                    cout<<"Minimum extracted : "<<t->key<<endl;
                 break;
        case '#':getline(cin,dump);//if '#' then ignore the whole line
                 break;
        case '-':flag=0;//turn off print after extract min
                 break;
        case '+':flag=1;//turn on print after extract min
                 break;
        case 'q':break;//Quitting
        case 'S':
        case 's':cout<<"\nHEAP STRUCTURE:"<<endl;
                 print(H->minn,0);
                 break;
         default://If user did not type any of the options
                 cout<<"Wrong choice Try again\n";
        }
    }while(ch!='q');
}
void print(node *x,int depth)
{
	if (x!=NULL)
	{
		node *tmp=x;
		for(int i=0;i<4*depth;i++)
			cout<<" ";
		cout<<tmp->key<<endl;
		if (tmp->child != NULL)
		{
			print(tmp->child,depth+1);
		}
		tmp=tmp->right;
		while(tmp!=x && tmp!=NULL)
		{
			for(int i=0;i<4*depth;i++)
				cout<<" ";
			cout<<tmp->key<<endl;
			if (tmp->child != NULL)
			{
				print(tmp->child,depth+1);
			}
			tmp=tmp->right;
		}
	}
	else
	{
		cout<<"Empty List"<<endl;
	}
	return;
}
heap *makeHeap()
{
    heap *h=(heap *)(malloc(sizeof(heap)));//dynamically allocating memory for new heap
    h->n=0;
    h->minn=NULL;
    return h;
}
void insertInHeap(heap *H,node *tmp)
{
    if(H->minn==NULL)//if H->minn is NULL.which means that first node is being inserted in heap
    {
        tmp->right=tmp;
        tmp->left=tmp;//since only node in circular doubly linked list, left and right pointers point to itself
        H->minn=tmp;
    }
    else
    {
        //Concatenating the node tmp in the already present circular doubly linked list
        tmp->left=H->minn->left;
        tmp->right=H->minn;
        H->minn->left=tmp;
        if(H->minn->right==H->minn)
            H->minn->right=tmp;
        if(tmp->key<H->minn->key)
            H->minn=tmp;
        tmp->left->right=tmp;
    }
    H->n=H->n+1;//after insert in heap, we increase H->n,(total number of nodes)
}

void insertInHeapp(heap *H,node *tmp)
{
    //SAME FUNCTION AS insertInHeap except that H->n is not being increased
    //This function is used when in extractMin ,we insert children of H->minn to the root list
    if(H->minn==NULL)
    {
        tmp->right=tmp;
        tmp->left=tmp;
        H->minn=tmp;
    }
    else
    {
        tmp->left=H->minn->left;
        tmp->right=H->minn;
        H->minn->left=tmp;
        if(H->minn->right==H->minn)
            H->minn->right=tmp;
        if(tmp->key<H->minn->key)
            H->minn=tmp;
        tmp->left->right=tmp;
    }
}
heap *FibHeapUnion(heap *H1,heap *H2)
{
    //To concatenate the root lists of two fib heaps
    heap *h=makeHeap();
    if(H1==NULL && H2==NULL)
    {
        //if both are null,the new list pointed by h also null
        h=NULL;
        return h;
    }
    else if(H1==NULL)
    {
        //if h1 is null, then new h is h2
        h=H2;
        h->n=H2->n;
        h->minn=H2->minn;
        return h;
    }
    else if(H2==NULL)
    {
        //if h2 is null,then new h is h1
        h=H1;
        h->n=H1->n;
        h->minn=H1->minn;
        return h;
    }
    else
    {
        //concatenate the heads H1 and H2 of the two root lists and make the new minimum equal to h
        h->minn=H1->minn;
        node *x=h->minn->right;
        //Linking operations ensuring that no link is lost
        h->minn->right=H2->minn;
        H2->minn->left->right=x;
        node *y=H2->minn->left;
        H2->minn->left=h->minn;
        x->left=y;
        h->n=H1->n+H2->n;
        if(H2->minn->key<h->minn->key)
            h->minn=H2->minn;
        return h;
    }
}
node *extractMin(heap *h)
{
    node *y=h->minn;
    if(y==NULL)
        return y;
    node *x=y->child;
    //if there are children of y,then insert them into root list
    if(x!=NULL)
    {
        node *tmp=x;
        do
        {
            node *tt=tmp->right;//important..storing tmp->right in tt so that it is not lost when calling insertInHeapp and we can successfully traverse the list
            insertInHeapp(h,tmp);
            tmp->parent=NULL;
            tmp=tt;
        }while(tmp!=x);
    }
    //Removing y from root list
    y->left->right=y->right;
    y->right->left=y->left;
    if(y==y->right)//if only y present in root list
        h->minn=NULL;
    else
    {
        //otherwise temporarily setting h->minn and calling consolidate function
        h->minn=y->right;
        consolidate(h);
    }
    h->n=h->n-1;//since minimum extracted reduce n
    return y;
}
void HeapLink(heap *h,node *x,node *y)
{
    //Here we want to link y as a child of x
    //Remove y from root list
    y->left->right=y->right;
    y->right->left=y->left;
    if(x->child==NULL)
    {
        x->child=y;
        y->left=y;
        y->right=y;
    }
    else
    {
        //Ensuring proper linking
        y->right=x->child;
        y->left=x->child->left;
        x->child->left->right=y;
        x->child->left=y;
    }
    y->parent=x;
    x->degree=x->degree+1;//increasing degree of x
    y->mark=0;//useless for this question,but will be useful if we add Cut and CascadingCut functions
}
void consolidate(heap *h)
{
    node *tttt=h->minn;//tttt is a temporary pointer to traverse root list and set all flaggs to 0
    do
    {
        tttt->flagg=0;
        tttt=tttt->right;
    }while(tttt!=h->minn);
    if(h->minn==NULL)
        return;
    int n=(int)(log2(h->n))+2;//n size i have made 2 extra just as a safety precaution
    node *arr[n];//arr is an array in which arr[i] points to a node with degree i
    for(int i=0;i<n;i++)
        arr[i]=NULL;
    int br=0;node *tmp=h->minn;int cnt=-1;int counter=0;
    do
    {
        node *tt=tmp->right;//important..storing tmp->right in tt so that it is not lost when calling insertInHeapp and we can successfully traverse the list
        int x=tmp->degree;
        tmp->flagg=1;//tmp flagg made 1
        while(arr[x]!=NULL)
        {
            if(arr[x]==tmp)//just a precaution
                break;
            if(tmp->key<arr[x]->key)//if tmp->key less than arr[x]->key ,make arr[x] child of tmp
                HeapLink(h,tmp,arr[x]);
            else
                {HeapLink(h,arr[x],tmp);tmp=arr[x];tmp->flagg=1;}
            arr[x]=NULL;
            x++;//incrementing degree in which we have to next check array arr
        }
        arr[x]=tmp;
        tmp=tt;
        node *ttt=tmp;
        br=0;
        //here i am checking that if all flaggs are 1 ,then i will break out of the outer while loop!
        do
        {
            if(ttt->flagg==0)
                br=1;
            ttt=ttt->right;
        }while(ttt!=tmp);
    }while(br==1);

    //Now traversing array arr to find the new h->minn
    for(int i=0;i<n;i++)
    {
        if(h->minn==NULL)
            h->minn=arr[i];
        else if(arr[i]!=NULL && h->minn->key>arr[i]->key)
            h->minn=arr[i];
    }
}
node *getNode(int x)
{
    //This function returns a dynamically allocated node by setting all fields to their defaults
    node *tmp=(node *)(malloc(sizeof(struct node)));
    tmp->degree=0;
    tmp->key=x;
    tmp->parent=NULL;
    tmp->child=NULL;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->mark=0;
    tmp->flagg=0;
}
