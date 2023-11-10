#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <iomanip>

#define MAX_DIMENSION 21705

using namespace std;

class TreeNode {
private:
    double location[MAX_DIMENSION];                                         //location or the center
    double sum[MAX_DIMENSION];                                                      //for cummulative adding
    int dataNum;                                                                                    //denominator
    TreeNode *left;                                                                         //left treenode pointer
    TreeNode *right;                                                                        //right treenode pointer
    TreeNode *next;                                                                         //next for a list
    bool isLegit;                                                                           //spam or legit corpus
    int serialNum;                                                                          //ID in the "string of leaves"

public:
    TreeNode()
    {
        left = NULL;
        right = NULL;
        next = NULL;
        dataNum = 1;
        isLegit = false;
        for (int i = 0; i < MAX_DIMENSION; i++)
        {
            location[i] = 0;
            sum[i] = 0;
        }
    }                                                                               // end of constructor

    void setLocation(int i, double j)
    {
        location[i] = j;
        sum[i] = j;
    }                                                                               //for entering the data of the treenode

    TreeNode* getNext()
    {
        return next;
    }

    double getLocation(int i)
    {
        return location[i];
    }

    void setNext( TreeNode *input)
    {
        next = input;
    }

    void setLegit()
    {
        isLegit = true;
    }

    bool Legitimacy()
    {
        return isLegit;
    }

    friend class HierachicalTree;
};                                                                                      //end of TreeNode

struct Subtree
{
    TreeNode *begin;
    int length;
    Subtree *next;
};
class HierachicalTree {
private:
    TreeNode *root;
    TreeNode *listHead;                                     //for a sequence of temp subtrees
    TreeNode *listRear;                                     //for a sequence of temp subtrees
    TreeNode *tmp;
    Subtree *subtreeHead, *subtreeHandle;

protected:
    void createTree ();                                                                     //create tree from the sequence of treenodes
    void dfs (TreeNode *treePtr);                                           //traverse the tree
    Subtree *atLevel(int lvl, TreeNode *parent);

public:
    HierachicalTree()
    {
        root = NULL;
        listHead = NULL;
        listRear = NULL;
    }                                                                               // end of constructor

    void addToList(TreeNode *Item)
    {
        if (listHead == NULL && listRear == NULL)
        {
            listHead = Item;
            listRear = Item;
        }
        else
        {
            listRear->next = Item;
            listRear = Item;
        }
    }                                                                               // put the data into the list

    void organise()
    {
        tmp = 0;
        int tok = 0;
        cout << "root: " << root << endl;
        system("pause");
        dfs(root);
        tmp = listHead;

        while (tmp != NULL)
        {
            tmp->serialNum = tok++;
            tmp = tmp->next;
        }

    }                                                                               //access the protected function

    void buildTree()
    {
        createTree();
    }                                                                               //access the protected function

    Subtree *subtreeAt(int level)
    {
        subtreeHead = subtreeHandle = NULL;
        return atLevel(level, root);
    }

    int rightEnd(TreeNode *p)
    {
        if (p->right == NULL)
            return p->serialNum;
        else
            return rightEnd(p->right);
    }

    int leftEnd(TreeNode *p)
    {
        if (p->left == NULL)
            return p->serialNum;
        else
            return leftEnd(p->left);
    }

};

void HierachicalTree::createTree()
{
    TreeNode *goal;
    TreeNode *temp, *temp2;
    double sum = 0;
    double minimum = MAX_DIMENSION;
    cout << "Creating tree" << endl;
    while (listHead != listRear)
    {
        temp = listHead->next;
        while (temp != NULL)
        {
            sum = 0;
            for (int i = 0; i < MAX_DIMENSION; i++)
                sum += abs(listHead->location[i] - temp->location[i]);  //CAUTION: BIT STREAM ONLY
            //FOR NON-INT SCALING, USE EUCLIDEAN DISTANCE
            if (sum < minimum)
            {
                goal = temp;
                minimum = sum;
            }
            temp = temp->next;
        }
        cout << "		Comparison between listHead and others completed"<< endl;
        temp = new TreeNode;
        temp->dataNum = listHead->dataNum + goal->dataNum;

        for (int i = 0; i < MAX_DIMENSION; i++)
        {
            temp->sum[i] = listHead->sum[i] + goal->sum[i];
            temp->location[i] = temp->sum[i] / temp->dataNum;
        }
        cout << "		Subtree built"<< endl;
        temp2 = listHead;
        cout << "		  temp2 = "<< temp2 << endl;
        cout << "		  goal = "<< goal << endl;
        while (temp2->next != goal)
        {
            cout << "				temp2 to be set to: "<< temp2->next << endl;
            temp2 = temp2->next;
            cout << "				done."<< endl;
        }
        cout << "		temp2 allocated"<< endl;

        temp->left = listHead;
        temp->right = goal;

        if (goal == listRear && listHead->next != listRear)
        {
            cout << "		  Subtree: head and rear"<< endl;
            temp2->next = temp;
            listHead = listHead->next;
        }
        else if (listHead->next == listRear)
        {
            cout << "		  Subtree: Now root found"<< endl;
            listHead = temp;
        }
        else
        {
            cout << "		  Subtree: head and someone in the middle"<< endl;
            temp2->next = goal->next;
            listRear->next = temp;
            listHead = listHead->next;
        }
        cout << "		Subtree mounted to list"<< endl;
        minimum = MAX_DIMENSION;
        listRear = temp;
    }

    root = listHead;
    listHead = NULL;
    listRear = NULL;
    temp = NULL;
    temp2 = NULL;
    goal = NULL;

}


void HierachicalTree::dfs(TreeNode *treePtr)
{
    //=============
    // This method sequencially "strings" all leaf nodes
    //=============
    if (treePtr->left == NULL && treePtr->right == NULL)                                //Leaf
    {
        if (listHead)
        {
            treePtr->next = NULL;
            tmp->next = treePtr;
            tmp = treePtr;
        }
        else
        {
            listHead = treePtr;
            tmp = treePtr;
        }
    }
    else                                                                                                                        //2 children
    {
        dfs(treePtr->left);
        dfs(treePtr->right);
    }
    return;
}

Subtree *HierachicalTree::atLevel(int lvl, TreeNode *parent)
{
    if (lvl == 0)
    {
        Subtree *subtreeTmp = new Subtree;
        subtreeTmp->begin = parent;
        subtreeTmp->length = rightEnd(parent) - leftEnd(parent);
        return subtreeTmp;
    }
    else
        return atLevel(lvl - 1, parent->left);
}

int main(void)
{
    int axis, oldAxis;
    int fileSeq = 1;
    char buffer[10];
    string fileName;
    string str;
    ifstream inf;
    HierachicalTree hTree;                                                      //hierachical tree
    TreeNode *tempNode;

    fileName = sprintf(buffer, "%d", fileSeq);
    fileName += ".txt";
    inf.open(fileName.c_str(), ios::in);

    while (inf)
    {
        tempNode = new TreeNode;
        inf >> str;
        oldAxis = -1;                                                           //init to a sub-zero number
        while (inf.eof())
        {
            axis = atof(str.c_str());
            if (axis < oldAxis)                                          //reach the bottom of file
            {
                cout << axis << endl;
                if (axis)
                    tempNode->setLegit();
            }
            else
            {
                tempNode->setLocation(axis, 1);
                oldAxis = axis;
                cout << axis << endl;
            }
            inf >> str;
        }
        system("pause");
        hTree.addToList(tempNode);
        cout << fileName << " read" << endl;
        inf.close();
        fileName = sprintf(buffer, "%d", ++fileSeq);
        fileName += ".txt";
        inf.open(fileName.c_str(), ios::in);
    }
    inf.close();
    system("pause");
    hTree.buildTree();
    cout << "Built" << endl;
    system("pause");
    hTree.organise();
    cout << "Linked list built" << endl;
    system("pause");

    return 0;
}
