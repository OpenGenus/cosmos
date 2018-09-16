#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int freq;
	char alpha[26];
	struct node *next;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;

node* getnode(){

	node* newnode = (node*)malloc(sizeof(node));
	newnode->freq = -1;
	int i;
	for(i=0;i<26;i++)newnode->alpha[i] = '$';
	newnode->next = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	return newnode;
}

node* adds(node* headl,node* temp){

	if(headl == NULL){

		headl = temp;
		return headl;
	}
	else{
		temp->next = headl;
		headl = temp;
		return headl;
	}
}

node* addl(node* taill,node* temp){

	if(taill == NULL){

		taill = temp;
		return taill;
	}
	else{
		taill->next = temp;
		taill = temp;
		return taill;
	}
}


node* addbw(node* smaller,node* temp,node* greater){

	temp->next = greater;
	smaller->next = temp;
	return temp;
}

node* addafterp(node* p, node* temp){

	node *te = p->next;
	temp = addbw(p,temp,te);
	return temp;
}

void printl(node* headl){

	while(headl != NULL){
		printf("%c%d ",headl->alpha[0],headl->freq);
		headl = headl->next;
	}
}

node* search(node* headl,node *temp){

	node* t1 = headl;
	node* t2 = headl;
	if(t2->next != NULL){
		t2 = t2->next;
	}
	if(t2 == headl){
		if(t2->freq > temp->freq){
			headl = adds(t2,temp);
			return headl;
		}
		else if(t2->freq < temp->freq){
			temp = addl(t2,temp);
			return headl;
		}
		else if(t2->freq == temp->freq){
			if(t2->alpha[0] > temp->alpha[0]){
				temp = addl(t2,temp);
				return headl;
			}
			else if(t2->alpha[0] < temp->alpha[0]){
				temp = adds(t2,temp);
				return headl;
			}
		}
	}
	while(t1 != t2){
		
		if(temp->freq < t1->freq){
				temp->next = t1;
				headl = temp;
				return headl;
		}
		else if(temp->freq >t2->freq){
			if(t2->next == NULL){
				temp = addl(t2,temp);
				return headl;
			}
			else if(temp->freq > t2->freq && temp->freq < (t2->next)->freq){
				temp = addafterp(t2,temp);
				return headl;
			}
		}
		else if(t1->freq < temp->freq && t2->freq > temp->freq){

			temp = addbw(t1,temp,t2);
			
			return headl;
		}
		else if(t1->freq < temp->freq && t2->freq == temp->freq){

			if(temp->alpha[0] < t2->alpha[0]){
				temp = addbw(t1,temp,t2);
				return headl;
			}
			if(t2->next == NULL){
				temp = addl(t2,temp);
				return headl;
			}
		}
		else if(t1->freq == temp->freq && t2->freq == temp->freq){

			if(temp->alpha[0] < t2->alpha[0] && temp->alpha[0] > t1->alpha[0]){
				temp = addbw(t1,temp,t2);
				return headl;
			}
			if(t2->next == NULL){
				temp = addl(t2,temp);
				return headl;
			}
		}
		else if(t1->freq >temp->freq && t2->next == NULL){
			headl = adds(t1,temp);
			return headl;
		}
		else if(t1->freq == temp->freq && t2->freq > temp->freq){
			if(temp->alpha[0] > t1->alpha[0]){
				temp = addbw(t1,temp,t2);
				return headl;
			}
			else{
				headl = adds(t1,temp);
				return headl;
			}
		}
		if(t1->next != NULL){
			t1 = t1->next;
		}
		if(t2->next != NULL){
			t2 = t2->next;
		}
	}

}


node* pop(node *headl){

	node* temp = headl;
	headl = headl->next;
	temp->next = NULL;
	return temp;
}

node* buildtree(node* headl){

		while(headl->next != NULL){
		
		node* t2 = headl;
		headl = headl->next;
		t2->next = NULL;
		node* t1 = headl;
		headl = headl->next;
		t1->next = NULL;
		node* par = getnode();
		par->left = t2;
		par->right = t1;
		par->alpha[0] = (par->left)->alpha[0];
		par->freq = t1->freq + t2->freq;
		t1->parent = par;
		t2->parent = par;
		if(headl == NULL){
			headl = par;
		}
		else{
			headl = search(headl,par);
		}	
	}
	
	return headl;

}

void printleaf(node *headl){

	if(headl == NULL)return;
	else
	{
		if(headl->left == NULL && headl->right == NULL)printf("%c ",headl->alpha[0]);
		else{
			printleaf(headl->left);
			printleaf(headl->right);
		}
	}

}

void printarr(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)printf("%d", arr[i]);
    printf("\n");
}

void printcodes(node* headl, int *arr, int top)
{
    if (headl->left)
    {
        arr[top] = 0;
        printcodes(headl->left, arr, top + 1);
    }
    if (headl->right)
    {
        arr[top] = 1;
        printcodes(headl->right, arr, top + 1);
    }
    if (headl->left == NULL && headl->right == NULL)
    {
        printf("%c: ", headl->alpha[0]);
        printarr(arr, top);
    }
}

int main(){

	node *head = getnode();
	char input[100];
	int top =0,result[20];
	printf("Enter the string to be coded: ");
	scanf("%s",input);
	int frequency[26] = {0};
	int d,i;
	for(i=0;input[i] != '\0';i++){

		d = input[i];
		d -= 97;
		frequency[d]++;
	}
	int f=0;
	for(i=0;i<26;i++){

		if(frequency[i] != 0){
			if(f==0){
				head->alpha[0] = i+97;
				head->freq = frequency[i];
				f=1;
			}
			else
			{
				node *t1 = getnode();
				t1->alpha[0] = i+97;
				t1->freq = frequency[i];
				head = search(head,t1);
			}
		}
	}
	head = buildtree(head);
	printf("List of codes: \n");
	printcodes(head,result,top);
	return 0;
}
