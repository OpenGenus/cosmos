#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *lcptr;
	int data;
	int height;
	struct node *rcptr;
};

struct node *rptr = NULL;
int c = 0,f = 0;

int
height(struct node *rptr)
{
	if (rptr == NULL)
		return (-1);
	else
		return (rptr->height);
}

void
heightUpdate(struct node *rptr)
{
	int leftHeight = height(rptr->lcptr);
	int rightHeight = height(rptr->rcptr);

	if (leftHeight > rightHeight)
		rptr->height = leftHeight + 1;
	else
		rptr->height = rightHeight + 1;
}

int
getBalance(struct node *rptr)
{
	if (rptr == NULL)
		return (0);
	else
		return (height(rptr->lcptr) - height(rptr->rcptr));
}

struct node *
RightRotate(struct node *rptr)
{
	struct node *jptr = rptr;
	struct node *kptr = rptr->lcptr;
	jptr->lcptr = kptr->rcptr;
	kptr->rcptr = jptr;

	heightUpdate(jptr);
	heightUpdate(kptr);

	return (kptr);
}

struct node *
LeftRotate(struct node *rptr)
{
	struct node *jptr = srptr;
	struct node *kptr = rptr->rcptr;
	jptr->rcptr = kptr->lcptr;
	kptr->lcptr = jptr;

	heightUpdate(jptr);
	heightUpdate(kptr);

	return (kptr);
}

struct node *
LeftRightRotate(struct node *rptr)
{
	struct node *jptr = rptr;
	struct node *kptr = rptr->lcptr;
	jptr->lcptr = LeftRotate(kptr);

	return RightRotate(jptr);
}

struct node *
RightLeftRotate(struct node *rptr)
{
	struct node *jptr = rptr;
	struct node *kptr = rptr->rcptr;
	jptr->rcptr = RightRotate(kptr);

	return LeftRotate(jptr);
}

struct node *
insert(struct node *rptr, int x)
{
	if (rptr == NULL) {
		rptr = (struct node *)malloc(sizeof(struct node));
		rptr->data = x;
		rptr->lcptr = rptr->rcptr = NULL;
		rptr->height = 0;
	}
	else {
		if (x < rptr->data) {
			rptr->lcptr = insert(rptr->lcptr,x);

			if (getBalance(rptr) == 2 && x < (rptr->lcptr)->data)
				rptr = RightRotate(rptr);
			else if (getBalance(rptr) == 2 && x >= (rptr->lcptr)->data)
				rptr = LeftRightRotate(rptr);
		}
		else {
			rptr->rcptr = insert(rptr->rcptr,x);

			if (getBalance(rptr) == -2 && x < (rptr->rcptr)->data)
				rptr = RightLeftRotate(rptr);
			else if (getBalance(rptr) == -2 && x >= (rptr->rcptr)->data)
				rptr = LeftRotate(rptr);
		}
		heightUpdate(rptr);
	}

	return (rptr);
}

struct node *
inorder_successor(struct node *rptr)
{
	struct node *t = rptr->rcptr;

	while (t->lcptr != NULL)
		t = t->lcptr;

	return (t);
}

struct node *
delete(struct node *rptr, int x)
{
	if (rptr == NULL) 
    	return rptr;

    if (x < rptr->data)
        rptr->lcptr = delete(rptr->lcptr, x);
 
    else if (x > rptr->data)
        rptr->rcptr = delete(rptr->rcptr, x);

    else {
        if (rptr->lcptr == NULL) {
            struct node *temp = rptr->rcptr;
            free(rptr);
            f = 1;
            return (temp);
        }
        else if (rptr->rcptr == NULL) {
            struct node *temp = rptr->lcptr;
            free(rptr);
            f = 1;
            return (temp);
        }
 
        struct node *temp = inorder_successor(rptr); 
        rptr->data = temp->data; 
        rptr->rcptr = delete(rptr->rcptr, temp->data); 
    }

    if (rptr == NULL) 
      return (rptr);
    
    heightUpdate(rptr); 
 
    if (getBalance(rptr) > 1 && getBalance(rptr->lcptr) >= 0)
        return (RightRotate(rptr));
 
    if (getBalance(rptr) > 1 && getBalance(rptr->lcptr) < 0)
        return (LeftRightRotate(rptr));
 
    if (getBalance(rptr) < -1 && getBalance(rptr->rcptr) <= 0)
        return (LeftRotate(rptr));
 
    if (getBalance(rptr) < -1 && getBalance(rptr->rcptr) > 0)
        return (RightLeftRotate(rptr));
 
    return (rptr);

}

void
inorder(struct node *rptr)
{
	if (rptr != NULL) {
		inorder(rptr->lcptr);
		printf("%d ",rptr->data);
		inorder(rptr->rcptr);
	}
}

void 
preorder(struct node *rptr)
{
	if (rptr != NULL) {
		printf("%d ",rptr->data);
		preorder(rptr->lcptr);
		preorder(rptr->rcptr);
	}
}

void 
postorder(struct node *rptr)
{
	if (rptr != NULL) {
		postorder(rptr->lcptr);
		postorder(rptr->rcptr);
		printf("%d ",rptr->data);
	}
}

void 
search(int x)
{
	struct node *t = rptr;
	int f = 0;
	while (t != NULL) {
		if (x < t->data)
			t = t->lcptr;
		else if (x > t->data)
			t = t->rcptr;
		else {
			f = 1;
			break;
		}
	}
	if (f == 1)
		printf("%d is found in AVL\n",x);
	else
		printf("%d is not found in AVL\n",x);
}

void 
count(struct node *rptr)
{
	if (rptr != NULL) {
		count(rptr->lcptr);
		count(rptr->rcptr);
		c++;
	}
}

void
avlcheck(struct node *rptr)
{
	if (rptr != NULL) {
		avlcheck(rptr->lcptr);
		avlcheck(rptr->rcptr);
		printf("Data:  %d Balance Factor:  %d\n",rptr->data,getBalance(rptr));
	}
}

int main()
{
	int t;
	while (1) {
		printf("1.Insert\n2.Delete\n3.Search\n4.Height\n5.Count\n6.Inorder\n7.Preorder\n8.Postorder\n9.AVL Check\n10.Exit\n");
		scanf("%d",&t);
		switch(t) {
			
			case 1 :
				int x;
				printf("Enter integer to be inserted\n");
				scanf("%d",&x);
				rptr = insert(rptr,x);
				printf("%d is successfully inserted in AVL\n",x);
				break;

			case 2 :
				int x;
				printf("Enter integer to be deleted\n");
				scanf("%d",&x);
				f = 0;
				rptr = delete(rptr,x);
				if (f == 1)
					printf("%d is successfully deleted from AVL\n",x);
				else
					printf("%d is not found in AVL.Hence,cannot be deleted\n",x);
				break;
			
			case 3 :
				int x;
				printf("Enter integer to be searched\n");
				scanf("%d",&x);
				search(x);
				break;
			
			case 4 :
				printf("Height of AVL: %d\n",height(rptr));
				break;
			
			case 5 :
				c = 0;
				count(rptr);
				printf("Number of nodes present AVL:%d\n",c);
				break;
			
			case 6 :
				printf("Inorder sequence:-\n");
				inorder(rptr);
				printf("\n");
				break;
			
			case 7 :
				printf("Preorder sequence:-\n");
				preorder(rptr);
				printf("\n");
				break;
			
			case 8 :
				printf("Postorder sequence:-\n");
				postorder(rptr);
				printf("\n");
				break;

			case 9 :
				printf("Balance Factor for each node:-\n");
				avlcheck(rptr);
				break;

			case 10 :
				return (0);

		}
	}
}