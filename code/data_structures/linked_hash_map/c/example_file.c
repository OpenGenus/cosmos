#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_hash_map.h"

#define NUM_DATA 100
#define VALUE_RANGE 300

#define HASH_CAPACITY 10
#define HASH_LOAD_FACTOR 0.5


int main()
{
  srand(time(NULL));
  
  // Creating data to populate hash map
  Data** data_array = (Data**) malloc(NUM_DATA * sizeof(Data*));

  for(int i = 0; i < NUM_DATA; i++)
  {
    Data* data = (Data*) malloc(sizeof(Data));
    data->key = i;
    data->value = (float) (rand() % VALUE_RANGE);
    data_array[i] = data;
  }

  // Init Linked Hash Map
  LinkedHashMap* hashMap = LHM_init(HASH_CAPACITY, HASH_LOAD_FACTOR);

  printf("\n***** ADDING KEYS 0, 7, 27 and 37... *****");
  // Addig some data to the map
  LHM_put(hashMap, data_array[0]);
  LHM_put(hashMap, data_array[7]);
  LHM_put(hashMap, data_array[27]);
  LHM_put(hashMap, data_array[37]);
  LHM_print(hashMap);

  printf("***** REMOVING KEY 7... *****\n");
  // Removing elements [Test]
  printf("Hash map size before removal: %d\n", LHM_length(hashMap));
  LHM_remove(hashMap, 7);
  printf("Hash map size after removal: %d\n\n", LHM_length(hashMap));

  // Getting an element from the hash map
  printf("***** FETCHING 37... *****\n");
  Data* data;
  if( (data = LHM_get(hashMap, 37)) != NULL )
  {
    printf("Element fetched: ");
    printData(data); printf("\n");
  }
  else
  {
    printf("Element is not in the hash map");
  }

  // Second try
  printf("***** FETCHING KEY 9999... *****\n");
  if( (data = LHM_get(hashMap, 9999)) != NULL )
  {
    printf("Element fetched: ");
    printData(data);
  }
  else
  {
    printf("Element with key is not in the hash map\n");
  }

  //Exceeding capacity
  printf("\n\nAdding until capacity is reachead, then adding new data and overwriting the LRU\n");
  while(LHM_length(hashMap) < hashMap->capacity)
  {
    LHM_put(hashMap, data_array[rand() % NUM_DATA]);
  }

  printf("Recently used: %d\n", hashMap->newest->key);
  printf("Least recently used: %d\n", hashMap->oldest->key);
  printf("Adding extra data (key: 50)...\n");
  LHM_put(hashMap, data_array[50]);
  printf("Recently used: %d\n", hashMap->newest->key);
  printf("Least recently used: %d\n", hashMap->oldest->key);



  printf("\n***** DESTROYING... *****\n");
  LHM_destroy(hashMap);


  return 0;
}