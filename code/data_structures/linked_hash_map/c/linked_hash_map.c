#include <stdio.h>
#include <stdlib.h>
#include "linked_hash_map.h"

int hash(int key, int size)
{
  return key % size;
}

LinkedHashMap* LHM_init(int capacity, float loadFactor)
{
  int num_buckets = capacity / loadFactor;

  LinkedHashMap* map = (LinkedHashMap*) malloc(sizeof(LinkedHashMap));
  
  map->buckets = (LinkedList*) malloc(num_buckets * sizeof(LinkedList));
  map->buckets_length = num_buckets;
  map->load_factor = loadFactor;
  map->capacity = capacity;
  map->current_size = 0;
  map->oldest = NULL;
  map->newest = NULL;

  int i = 0;
  for(i = 0; i < num_buckets; i++)
  {
    map->buckets[i].head = NULL;
    map->buckets[i].tail = NULL;
    map->buckets[i].length = 0;
  }

  return map;
}

int LHM_remove(LinkedHashMap* map, int key)
{
  int bucket_idx = hash(key, map->buckets_length);
  LinkedList* list = &map->buckets[bucket_idx];

  Node* ptr = list->head;
  Node* prev = NULL;

  while(ptr != NULL)
  {
    if(ptr->key == key)
    {
      // Last node on the list
      if(list->length == 1)
      {
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        map->current_size--;

        free(ptr);
        return 0;
      }

      else
      {
        if(ptr == list->head)
        {
          list->head = ptr->next_synonym;
        }
        else  if(ptr == list->tail)
        {
          prev->next_synonym = NULL;
          list->tail = prev;
        }

        if(prev != NULL && ptr->next_synonym != NULL)
        {
          prev->next_synonym = ptr->next_synonym;
        }

        list->length--;
        map->current_size--;

        free(ptr);
        return 0;
      }
    }

    prev = ptr;
    ptr = ptr->next_synonym;
  }

  return -1;
}

void addToCache(LinkedHashMap* map, Node* node)
{
  // The cache is empty
  if(map->newest == NULL)
  {
    map->newest = node;
    map->oldest = node;
  }
  else
  {
    if(map->current_size < map->capacity)
    {
      (map->newest)->next_cache = node;
      node->prev_cache = map->newest;
      map->newest = node;			
    }
    else
    {
      // Remove the oldest node in cache and update it
      Node* newOldest = (map->oldest)->next_cache;
      newOldest->prev_cache = NULL;
      LHM_remove( map, (map->oldest)->key );
      map->oldest = newOldest;

      (map->newest)->next_cache = node;
      node->prev_cache = map->newest;
      map->newest = node;
    }
  }
}

void updateCache(LinkedHashMap* map, Node* node)
{
  Node* next = node->next_cache;
  Node* prev = node->prev_cache;

  if(node == map->newest)
  {
    return;
  }
  else if(node == map->oldest)
  {
    next->prev_cache = NULL;
    map->oldest = next;
    node->next_cache = NULL;

    (map->newest)->next_cache = node;
    prev = map->newest;
    map->newest = node;
    return;
  }

  Node* ptr = map->oldest;
  while(ptr != NULL)
  {
    // This node is the most recently visited (newest)
    if(ptr->key == node->key)
    {
      prev->next_cache = next;
      next->prev_cache = prev;

      (map->newest)->next_cache = ptr;
      ptr->prev_cache = map->newest;
      ptr->next_cache = NULL;
      map->newest = ptr;

    }

    ptr = ptr->next_cache;
  }
}

void LHM_put(LinkedHashMap* map, Data* data)
{
  // Find the proper bucket to put the data
  int bucket_idx = hash(data->key, map->buckets_length);
  LinkedList* list = &map->buckets[bucket_idx];

  // List is empty
  if(list->length == 0)
  {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = data->key;
    newNode->data = data;
    newNode->next_synonym = NULL;
    newNode->next_cache = NULL;
    newNode->prev_cache = NULL;
    addToCache(map, newNode);

    list->head = newNode;
    list->tail = newNode;
    list->length = list->length + 1;
    map->current_size++;
  }

  // Check if there's already data with this key on the list
  else
  {
    Node* ptr = list->head;

    while(ptr != NULL)
    {
      if(ptr->key == data->key)
      {
        // Update entry's data
        ptr->data = data;
        break;
      }

      ptr = ptr->next_synonym;
    }

    // Add a new entry
    if(ptr == NULL)
    {
      Node* newNode = (Node*) malloc(sizeof(Node));
      newNode->key = data->key;
      newNode->data = data;
      newNode->next_synonym = NULL;
      newNode->next_cache = NULL;
      newNode->prev_cache = NULL;
      addToCache(map, newNode);

      list->tail->next_synonym = newNode;
      list->tail = newNode;
      list->length++;
      map->current_size++;
    }
  }
}

int LHM_length(LinkedHashMap* map)
{
  return map->current_size;
}

Data* LHM_get(LinkedHashMap* map, int key)
{
  int bucket_idx = hash(key, map->buckets_length);
  LinkedList* list = &map->buckets[bucket_idx];

  Node* ptr = list->head;

  while(ptr != NULL)
  {
    if(ptr->key == key)
    {
      updateCache(map, ptr);
      return ptr->data;
    }

    ptr = ptr->next_synonym;
  }

  return NULL;
}

void freeLinkedList(LinkedList* list)
{
  Node* head = list->head;
  Node* ptr;

  while(head != NULL)
  {
    ptr = head;
    head = head->next_synonym;
    free(ptr);
  }
}

void LHM_destroy(LinkedHashMap* map)
{
  int i;
  for(i = 0; i < map->buckets_length; i++)
  {
    freeLinkedList(&map->buckets[i]);
  }

  free(map->buckets);
  free(map->oldest);
  free(map->newest);
}

void LHM_print(LinkedHashMap* map)
{
  printf("\n\n=============== Linked Hash Map Status ===============\n");
  printf("Load Factor: %f\n", map->load_factor);
  printf("Capacity: %d\n", map->capacity);
  printf("Buckets length: %d\n", map->buckets_length);
  printf("Current Size: %d\n", map->current_size);
  printf("Oldest accessed data (key): %d\n", map->oldest->key);
  printf("newest accessed data (key): %d\n\n", map->newest->key);

  int i = 0;
  for (i = 0; i < map->buckets_length; i++)
  {
    printf("* Bucket[%d]: ", i);
    if(map->buckets[i].length != 0)
    {			
      printf("\n- Head: (key: %d, value: %f)\n", map->buckets[i].head->key, map->buckets[i].head->data->value);
      printf("- Tail: (key: %d, value: %f)\n", map->buckets[i].tail->key, map->buckets[i].tail->data->value);
      printf("- Length:%d\n", map->buckets[i].length);			
      
      Node* ptr = map->buckets[i].head;

      while(ptr != NULL)
      {
        printf("\t- Data.key = %d\n", ptr->key);
        printf("\t- Data.value = %f\n\n", ptr->data->value);

        ptr = ptr->next_synonym;
      }
    }
    else
    {
      printf("EMPTY\n");
    }
  }
  printf("==================================================\n");
}

void printLinkedList(LinkedList* list)
{
  if(list != NULL)
  {
    Node* ptr = list->head;

    int i = 0;
    while(ptr != NULL)
    {
      printf("Element [%d]\n", i);
      printf("\t- key: %d\n", ptr->key);
      printf("\t- value: %f\n\n", ptr->data->value);

      ptr = ptr->next_synonym;
      i++;
    }		
  }
  else
  {
    printf("Invalid list");
  }
}

void LinkedListStatus(LinkedList* list, int showList)
{
  if(list != NULL)
  {
    printf("Head: (key: %d, value: %f)\n", list->head->key, list->head->data->value);
    printf("Tail: (key: %d, value: %f)\n", list->tail->key, list->tail->data->value);
    printf("Length:%d\n", list->length);

    if(showList)
    {
      printLinkedList(list);
    }
  }
  else
  {
    printf("Invalid Linked List");
  }
}



void printCache(LinkedHashMap* map)
{
  if(map->oldest == NULL && map->newest == NULL)
  {
    printf("Hash map cache is empty\n");
    return;
  }

  if(map->oldest != NULL)
  {
    printf("\n\n=============== Hash Mape Cache ===============\n");
    printf("Oldest node: (key: %d, value: %f)\n", map->oldest->key, map->oldest->data->value);
    printf("Newest node: (key: %d, value: %f)\n", map->newest->key, map->newest->data->value);
    Node* ptr = map->oldest;

    int i = 0;
    while(ptr != NULL)   // while(ptr != NULL || i < map->capacity)
    {
      printf("cache[%d] = key: %d\n", i, ptr->key);
      ptr = ptr->next_cache;
      i++;
    }

    printf("===============================================\n");
  }
}

void printData(Data* data)
{
  printf("(key: %d, value: %f)\n", data->key, data->value);
}