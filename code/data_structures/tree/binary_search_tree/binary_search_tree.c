#include <iostream>
using namespace std;

struct tnode
{
	int data;
	tnode *left;
	tnode *right;
};

void insert(tnode **ref, int data)
{
	tnode *newn = new tnode;
	newn->data = data;

	tnode *curr = *ref;

	if(curr == NULL)
	{
		*ref = newn;
		return;
	}

	if(data < curr->data)
	{
		insert(&curr->left, data);
	}
	else if(data > curr->data)
	{
		insert(&curr->right, data);
	}
	else
	{
		cout<<"same value?"<<endl;
		return;
	}

	return;
}

void disp(tnode *ref, int key)
{
	tnode *curr = ref;
	if(curr == NULL)
		return;

	switch(key)
	{
		case 1://preorder
			cout<<curr->data<<endl;
			disp(curr->left, key);
			disp(curr->right, key);
			break;

		case 2://inorder
			disp(curr->left, key);
			cout<<curr->data<<endl;
			disp(curr->right, key);
			break;
		case 3://postorder
			disp(curr->left, key);
			disp(curr->right, key);
			cout<<curr->data<<endl;
			break;
	}
}

void search(tnode *ref, int key)
{
	tnode *curr = ref;
	if(curr == NULL)
	{
		cout<<"not found!"<<endl;
		return ;
	}

	if(curr->data == key)
	{
		cout<<"found!"<<endl;
		return;
	}
	else
	{
		if(key < curr->data)
			search(curr->left, key);
		else
			search(curr->right, key);
	}
}

int minc = 0;

void min(tnode *ref)
{
	tnode *curr = ref;
	if(curr == NULL)
	{
		return;
	}
	if(curr != NULL)
	{
		min(curr->left);
		if(minc == 0)
			cout<<curr->data<<endl;;
		minc += 1;
		return;
	}
}

/*void remove(tnode **ref, int key)
{
	tnode *curr = *ref;
	if(curr == NULL)
		return;
	if(curr->data == key)
	{
		node *tracker = curr;
		while(tracker != NULL)
		{
		}
	}
	else
	{
		if(key < curr->data)
			search(curr->left, key);
		else
			search(curr->right, key);
	}
}*/

void treeops()
{
	tnode *head = NULL;
	int ch;
	do
	{
	    cout<<"----\n0.Exit\n1.insert\n2.disp\n3.search\n4.min\n5.delete\n----"<<endl;
	    cin>>ch;
	    switch(ch)
	    {
	      case 0:
	        break;
	      case 1:
	        int nodeval;
	        cin>>nodeval;
	        insert(&head, nodeval);
	        break;
	      case 2:
	      	int dispch;
	      	cout<<"\n1.preorder\n2.inorder\n3.postorder\n";
	      	cin>>dispch;
	        disp(head,dispch);
	        break;
	      case 3:
	        cin>>nodeval;
	        search(head, nodeval);
	        break;
	      case 4:
	        min(head);
	        break;
	      case 5:
	        //delete here
	        break;
	    }
	}
  while(ch != 0);
  return;
}
