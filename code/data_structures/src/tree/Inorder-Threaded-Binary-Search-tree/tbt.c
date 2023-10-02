#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Menu Driven Program with implementation of BST and all the fuctions
    // Insert
    // Traversal(both without using stack)
        // preorder
        // inorder
	// postorder
    // Delete
    // Exit Program

struct node{
    int val;
    bool lbit;
    bool rbit;

    struct node* left;
    struct node* right;

};

struct node* getNode(int val);
struct node* insert(struct  node* head , int key);

struct node* inorderPredecessor(struct node* p);
struct node* inorderSuccessor(struct node*p);

void Traversal(struct node* head);
void inorder(struct node* head);
void preorder(struct node* head);

struct node* findParent(struct node* p);
struct node* postSuccessor(struct node* p);
void postorder(struct node* head);

// ********************************* DELETE ********************************
struct node* delThreadedBST(struct node* head, int key);
struct node* delTwoChild(struct node* head, struct node* par, struct node* ptr);
struct node* delOneChild(struct node* head, struct node* par, struct node* ptr);
struct node* delNoChild (struct node* head, struct node* par, struct node* ptr);




int main(){
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->lbit= 0; 
    head->rbit= 1;     //convention for all cases
    head->right=head; //convention for all cases
    head->left=head;  //head->left should point to root 

    
    // uncomment the following to create a sample tree like

    // insert(head,10);
    // insert(head,5);
    // insert(head,15);
    // insert(head,20);
    // insert(head,13);
    // insert(head,14);
    // insert(head,12);
    // insert(head,8);
    // insert(head,3);
    // insert(head, 21);
    // insert(head, 22);
    // insert(head, 30);

    //will create a tree like this
    //             10
    //    5                    15
    //  3   8            13           20
    //               12     14           21
    //                                     22
    //                                       30
    //or use menu driven approach

	
    while(1){
        printf("\n\n\n\n****************************************************************");
        printf("\nSelect operation");

        printf("\n\t1.Insert\n\t2.Traverse(pre in)\n\t3.Delete\n\n\t0.Exit\n\nEnter your choice: ");
        int n;
        scanf("%d",&n);
        int temp;
        // system("cls");

        switch(n){
            case 1:
                {
                    printf("\nEnter number to Insert: ");
                    scanf("%d",&temp);
                    head = insert(head,temp);
                }
            break;

            
            case 2:
                Traversal(head);
            break;

            case 3:
                {
                    printf("\nEnter number to Delete: ");
                    scanf("%d",&temp);
                    delThreadedBST(head, temp);

                }
            break;

            case 0:
                exit(0);
            break;

            default:
                printf("invalid Choixe.");
            break;
        }
    }

    return 0;
}

    //             10
    //    5                    15
    //  3   8            13           20
    //               12     14           21
    //                                      22
    //                                        30




struct node* getNode(int val){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->val  = val;
    temp->lbit = 0;
    temp->rbit = 0;
    temp->left = NULL;
    temp->right= NULL;
    return temp;
}


struct node* insert(struct  node* head , int key){
    struct node* temp = getNode(key);
    struct node* p;

    if(head->left == head) {
        head->left = temp;
        temp->left = head;
        temp->right = head;
        return head;
    }

    p= head->left;   

    while(1){
        if(key < p->val && p->lbit==1)
            p=p->left;
        
        else if(key > p->val && p->rbit==1)
            p=p->right;
        else 
            break;
    }

    if(key < p->val )
    {
        p->lbit = 1;
        temp->left = p->left;            
        temp->right = p;      
        p->left = temp;       

    }

    else if( key > p->val )
    {
        p->rbit = 1;
        // rearrange the thread after linking new node
        temp->right = p->right;     //inorder successor (next)
        temp->left = p;             
        p->right = temp;
        
    }

    return head;
}

struct node* inorderPredecessor(struct node* p){
    if(p->lbit==0)return p->left;
    else if(p->lbit==1){
        p=p->left;
        while(p->rbit==1)p=p->right;
    }
    return p;
}

struct node* inorderSuccessor(struct node*p){
    if(p->rbit==0)return p->right;
    else if (p->rbit==1)
    {
        p=p->right;
        while(p->lbit==1)p=p->left; 
    }
    return p;
}


void inorder(struct node* head){
    struct node* p;
    p=head->left;
    while(p->lbit==1)p=p->left;

    while(p!=head){
        printf(" %d", p->val);
        p=inorderSuccessor(p);

    }
}

void preorder(struct node* head){
    struct node* p;
    p=head->left;

    while(p!=head){
        printf("%d ", p->val);

        if(p->lbit==1){
            p=p->left;
        }
        else if(p->rbit==1){
            p=p->right;
        }
        else if(p->rbit==0){
            while(p->rbit==0)p=p->right;
            p=p->right;
        }
    }    
}




struct node* findParent(struct node* p){
    struct node* child= p;
    //ancestor of child 
    while(p->rbit==1)p=p->right;
    p=p->right;

    if(p->left==child)return p;

    p=p->left;
    while(p->right != child){
        p=p->right;
    }
    return p;
}

struct node* postSuccessor(struct node* p){
    struct node* cur= p;
    struct node* parent = findParent(cur);
    // printf("suc %d\n", parent->val);

    if(parent->right==cur)return parent;

    else {
        while(p->rbit==1)p=p->right;
        p=p->right;

        if(p->rbit==1){
            p=p->right;    
            while(!(p->rbit==0 && p->lbit==0)){
                if(p->lbit==1)p=p->left;
                else if(p->rbit==1)p=p->right;  
            }
        }
        // printf("suc %d\n", p->val);

    }
        return p;

}


void postorder(struct node* head)
{
    struct node* p = head->left;
    struct node* temp=p;
    while(!(p->rbit==0 && p->lbit==0)){
        if(p->lbit==1){
            p=p->left;
        }
        else if(p->rbit==1)p=p->right;  
    }
    printf(" %d", p->val);

    while(p!=head->left){
        // printf(" hello\n");
        p=postSuccessor(p);
        printf(" %d", p->val);
    }
}






void Traversal(struct node* head){
    printf("\nTraversal Type : \n1.preorder\n2.Inorder\n3.PostOrder\n\n\nEnter your choice: ");
    int n;
    scanf("%d",&n);
    // system("cls");
    switch (n)
    {
        case 1:
            printf("\nPreorder:\n\t");
            preorder(head);
            break;
            
        
        case 2:
            printf("\nInorder:\n\t");
            inorder(head);
            break;
        
        case 3:
            printf("\nPostorder:\n\t");
            postorder(head);
            break;
        
        default:
            break;
    }
}


// ********************************* DELETE ********************************

struct node* delThreadedBST(struct node* head, int key)
{

    struct node *par = head, *ptr = head->left;

    bool found = 0;

    while (ptr != head) {
        if (key == ptr->val) {
            found = 1;
            break;
        }
        par = ptr;
        if (key < ptr->val) {
            if (ptr->lbit == 1)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->rbit == 1)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found == 0)
        printf("key not present in tree\n");

    else if (ptr->lbit == 1 && ptr->rbit == 1)
        head = delTwoChild(head, par, ptr);

    else if(ptr->lbit == 0 && ptr->rbit == 0)
        head = delNoChild(head, par, ptr);

    else 
        head = delOneChild(head, par, ptr);
    
    return head;
}



struct node* delTwoChild(struct node* head, struct node* par, struct node* ptr){

    struct node* parSuc = ptr; 
    struct node* suc = ptr->right;

    while(suc->lbit==1){
        parSuc=suc;
        suc = suc->left;
    }

    ptr->val = suc->val;

    if(suc->lbit==0 && suc->rbit==0)
        head = delNoChild(head , parSuc , suc);

    else        
        head = delOneChild(head, parSuc , suc);
    
    return head;
}


struct node* delOneChild(struct node* head, struct node* par, struct node* ptr){

    struct node* child;
    if(ptr->lbit==1)child = ptr->left;
    else child = ptr->right;

    struct node* p= inorderPredecessor(ptr);
    struct node* s= inorderSuccessor(ptr);

    if(ptr == par->left){
        par->left = child;
    }
    else {
        par->right = child;
    }

    if(ptr->lbit ==1)
        p->right = s;

    else if(ptr->rbit ==1)
        s->left =p;

    free(ptr);
    return head;
}
struct node* delNoChild (struct node* head, struct node* par, struct node* ptr){
    if(ptr == head->left){          
        ptr = NULL;
    }
    else if(ptr == par->left){
        par->lbit=0;
        par->left = ptr->left;  
    }
    else if(ptr == par->right){
        par->rbit = 0;
        par->right = ptr->right;
    }
    free(ptr);
    return head;
}