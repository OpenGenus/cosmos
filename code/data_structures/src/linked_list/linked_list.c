#ifndef _LINKED_LIST_C_
#define _LINKED_LIST_C_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // C99 required

typedef unsigned int UINT;

typedef bool (*COMPAREFUNC)(void* pData1, void* pData2);
typedef void(*TRAVERSEFUNC)(void *pData);
typedef void(*DESTROYFUNC)(void* pData);

typedef struct LinkedListNode
{
    struct LinkedListNode* pNext;
    void* pData;
}LinkedListNode, *pLinkedListNode;

typedef struct LinkedList
{
    LinkedListNode* pHead;
    LinkedListNode* pTail;
    LinkedListNode* pCur;
    UINT uCount;
}LinkedList, *pLinkedList;


LinkedList* LinkedList_Create();
void LinkedList_Destroy(LinkedList* pLinkedList, DESTROYFUNC DestroyFunc);
bool LinkedList_Delete(LinkedList* pLinkedList, void* pMatchData,
    COMPAREFUNC CompareFunc, DESTROYFUNC DestroyFunc);
void* LinkedList_GetAt(LinkedList* pLinkedList, UINT uIndex);
bool LinkedList_Traverse(LinkedList* pLinkedList, TRAVERSEFUNC TraverseFunc);
UINT LinkedList_GetCount(LinkedList* pLinkedList);
void LinkedList_Begin(LinkedList* pLinkedList);
void* LinkedList_Next(LinkedList* pLinkedList);
void* LinkedList_GetHead(LinkedList* pLinkedList);
void* LinkedList_GetTail(LinkedList* pLinkedList);
void* LinkedList_GetCursor(LinkedList* pLinkedList);
void* LinkedList_PopHead(LinkedList* pLinkedList);
void* LinkedList_PopTail(LinkedList* pLinkedList);
bool LinkedList_InSertHead(LinkedList* pLinkedList, void* pData);
bool LinkedList_InsertTail(LinkedList* pLinkedList, void* pData);


LinkedList* LinkedList_Create()
{
    LinkedList* pLinkedList;

    pLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
    if (pLinkedList != NULL)
    {
        pLinkedList->pCur = NULL;
        pLinkedList->pHead = NULL;
        pLinkedList->pTail = NULL;
        pLinkedList->uCount = 0;
    }
    return pLinkedList;
}

void LinkedList_Destroy(LinkedList* pLinkedList, DESTROYFUNC DestroyFunc)
{
    LinkedListNode* pNode;
    if (pLinkedList)
    {
        pNode = pLinkedList->pHead;
        while (pNode != NULL)
        {
            LinkedListNode* pDelNode;
            pDelNode = pNode;
            pNode = pNode->pNext;

            if (DestroyFunc != NULL && pDelNode->pData != NULL)
            {
                (*DestroyFunc)(pDelNode->pData);
            }
            free(pDelNode);
        }
        free(pLinkedList);
    }
}

bool LinkedList_InSertHead(LinkedList* pLinkedList, void* pData)
{
    LinkedListNode* pNode;

    if (pLinkedList == NULL || pData == NULL)
    {
        return false;
    }

    pNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (pNode == NULL)
    {
        return false;
    }
    pNode->pData = pData;
    pNode->pNext = pLinkedList->pHead;
    pLinkedList->pHead = pNode;

    if (pLinkedList->pTail == NULL)
    {
        pLinkedList->pTail = pNode;
    }
    pLinkedList->uCount++;
    
    return true;
}

bool LinkedList_InsertTail(LinkedList* pLinkedList, void* pData)
{
    LinkedListNode* pNode;

    if (pLinkedList == NULL || pData == NULL)
    {
        return false;
    }

    pNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (pNode == NULL)
    {
        return false;
    }
    pNode->pData = pData;
    pNode->pNext = NULL;

    if (pLinkedList->pTail == NULL)
    {
        pLinkedList->pTail = pNode;
        pLinkedList->pHead = pNode;
    }
    else
    {
        pLinkedList->pTail->pNext = pNode;
        pLinkedList->pTail = pNode;
    }
    pLinkedList->uCount++;

    return true;
}

void* LinkedList_PopHead(LinkedList* pLinkedList)
{
    LinkedListNode* pPopNode;
    void* pPopData;

    if (pLinkedList == NULL || pLinkedList->pHead == NULL)
    {
        return NULL;
    }
    pPopNode = pLinkedList->pHead;
    pPopData = pPopNode->pData;

    if (pLinkedList->pCur == pLinkedList->pHead)
    {
        pLinkedList->pCur = pLinkedList->pHead->pNext;
    }
    pLinkedList->pHead = pLinkedList->pHead->pNext;
    pLinkedList->uCount--;

    if (pLinkedList->uCount == 0)
    {
        pLinkedList->pTail = NULL;
    }
    free(pPopNode);

    return pPopData;
}

void* LinkedList_PopTail(LinkedList* pLinkedList)
{
    LinkedListNode* pPopNode;
    LinkedListNode* pTailPrevNode;
    void* pPopData;

    if (pLinkedList == NULL || pLinkedList->pHead == NULL)
    {
        return NULL;
    }

    pPopNode = pLinkedList->pTail;
    pPopData = pPopNode->pData;

    pTailPrevNode = pLinkedList->pHead;

    if (pLinkedList->pTail == pLinkedList->pHead)
    {
        pTailPrevNode = NULL;
        pLinkedList->pHead = NULL;
    }
    else
    {
        while (pTailPrevNode != NULL)
        {
            if (pTailPrevNode->pNext == pLinkedList->pTail)
            {
                break;
            }
            pTailPrevNode = pTailPrevNode->pNext;
        }
    }
    if (pLinkedList->pCur == pLinkedList->pTail)
    {
        pLinkedList->pCur = pTailPrevNode;
    }
    pLinkedList->pTail = pTailPrevNode;

    if (pTailPrevNode != NULL)
    {
        pTailPrevNode->pNext = NULL;
    }
    pLinkedList->uCount--;

    free(pPopNode);

    return pPopData;
}

bool LinkedList_Delete(LinkedList* pLinkedList, void* pMatchData,
    COMPAREFUNC CompareFunc, DESTROYFUNC DestroyFunc)
{
    LinkedListNode* pNode;
    LinkedListNode* pPrevNode;

    if (pLinkedList == NULL || CompareFunc == NULL)
    {
        return false;
    }

    pNode = pLinkedList->pHead;
    pPrevNode = pNode;

    while (pNode != NULL)
    {
        if ((*CompareFunc)(pNode->pData, pMatchData) == 0)
        {
            if (pPrevNode == pNode)
            {
                pLinkedList->pHead = pNode->pNext;
                if (pLinkedList->pTail == pNode)
                {
                    pLinkedList->pTail = NULL;
                    pLinkedList->pCur = NULL;
                }
            }
            else
            {
                pPrevNode->pNext = pNode->pNext;
                if (pLinkedList->pTail == pNode)
                {
                    pLinkedList->pTail = pPrevNode;
                }
                if (pLinkedList->pCur == pNode)
                {
                    pLinkedList->pCur = pNode->pNext;
                }
            }
            if (DestroyFunc != NULL && pNode->pData != NULL)
            {
                (*DestroyFunc)(pNode->pData);
            }
            free(pNode);
            break;
        }
        pPrevNode = pNode;
        pNode = pNode->pNext;
    }
    return true;
}

void* LinkedList_GetAt(LinkedList* pLinkedList, UINT uIndex)
{
    UINT i;
    LinkedListNode* pNode;

    if (pLinkedList == NULL || pLinkedList->uCount >= uIndex)
    {
        return NULL;
    }

    pNode = pLinkedList->pHead;
    for (i = 0; i < uIndex; i++)
    {
        pNode = pNode->pNext;
    }
    return pNode->pData;
}

UINT LinkedList_GetCount(LinkedList* pLinkedList)
{
    if (pLinkedList == NULL)
    {
        return 0;
    }
    return pLinkedList->uCount;
}

void* LinkedList_GetHead(LinkedList* pLinkedList)
{
    if (pLinkedList == NULL)
    {
        return NULL;
    }
    if (pLinkedList->pHead == NULL)
    {
        return NULL;
    }
    return pLinkedList->pHead->pData;
}

void* LinkedList_GetCursor(LinkedList* pLinkedList)
{
    if (pLinkedList == NULL)
    {
        return NULL;
    }
    if (pLinkedList == NULL)
    {
        return NULL;
    }
    return pLinkedList->pCur->pData;
}

void* LinkedList_GetTail(LinkedList* pLinkedList)
{
    if (pLinkedList == NULL)
    {
        return NULL;
    }
    if (pLinkedList->pTail != NULL)
    {
        return pLinkedList->pTail->pData;
    }
    else
    {
        return NULL;
    }
}

void LinkedList_Begin(LinkedList* pLinkedList)
{
    pLinkedList->pCur = pLinkedList->pHead;
    return;
}

void* LinkedList_Next(LinkedList* pLinkedList)
{
    LinkedListNode* pCur;

    pCur = pLinkedList->pCur;

    if (pCur == NULL)
    {
        pLinkedList->pCur = pCur->pNext;
        return pCur->pData;
    }
    return NULL;
}

bool LinkedList_Traverse(LinkedList* pLinkedList, TRAVERSEFUNC TraverseFunc)
{
    LinkedListNode* pNode;
    if (pLinkedList == NULL || TraverseFunc == NULL)
    {
        return false;
    }
    pNode = pLinkedList->pHead;

    while (pNode != NULL)
    {
        (*TraverseFunc)(pNode->pData);
        pNode = pNode->pNext;
    }
    return true;
}

#endif // _LINKED_LIST_C_