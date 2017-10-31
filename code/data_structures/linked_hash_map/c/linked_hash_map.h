#ifndef _LINKED_HASH_MAP_H_
#define _LINKED_HASH_MAP_H_

/////////////////////////////
//     	Structures         //
/////////////////////////////

typedef struct _data
{
  int key;
  float value;

} Data;

typedef struct _node
{
  int key;
  Data* data;
  struct _node* next_synonym;
  struct _node* next_cache;
  struct _node* prev_cache;

} Node;

typedef struct _linkedList
{
  Node* head;
  Node* tail;
  int length;

} LinkedList;

typedef struct _linkedHashMap
{
  float load_factor;
  int buckets_length;
  int capacity;
  int current_size;

  LinkedList* buckets;	
  Node* oldest;
  Node* newest;

} LinkedHashMap;


///////////////////////////////////////
//	         Public API		         //
///////////////////////////////////////

LinkedHashMap* LHM_init(int capacity, float loadFactor);

Data* LHM_get(LinkedHashMap* map, int key);

void LHM_put(LinkedHashMap* map, Data* data);

int LHM_length(LinkedHashMap* map);

int LHM_remove(LinkedHashMap* map, int key);

void LHM_destroy(LinkedHashMap* map);

void LHM_print(LinkedHashMap* map);

///////////////////////////////////////
//     	 Internal Functions          //
///////////////////////////////////////

int hash(int key, int size);

void addToCache(LinkedHashMap* map, Node* node);

void updateCache(LinkedHashMap* map, Node* node);

void LinkedListStatus(LinkedList* list, int showList);

void freeLinkedList(LinkedList* list);

void printLinkedList(LinkedList* list);

void printCache(LinkedHashMap* map);

void printData(Data* data);


#endif