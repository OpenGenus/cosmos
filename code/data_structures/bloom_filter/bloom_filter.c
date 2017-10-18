#include <stdio.h>
#include <stdlib.h>


typedef struct st_BloomFilter
{
	int size;
	char *bits;
} BloomFilter;

// Declare interface
BloomFilter* bl_init(int size);
void bl_add(BloomFilter *bl, int value);
int bl_contains(BloomFilter *bl, int value);
void bl_destroy(BloomFilter *bl);

// Implementation
BloomFilter* bl_init(int size)
{
	BloomFilter *bl = (BloomFilter*)malloc(sizeof(BloomFilter));
	bl->size = size;
	bl->bits = (char*)malloc(size/8 + 1);
	return bl;
}

void bl_add(BloomFilter *bl, int value)
{
	int hash = value % bl->size;
	bl->bits[hash / 8] |= 1 << (hash % 8);
}

int bl_contains(BloomFilter *bl, int value)
{
	int hash = value % bl->size;
	return (bl->bits[hash / 8] & (1 << (hash % 8))) != 0;
}

void bl_destroy(BloomFilter *bl)
{
	free(bl->bits);
	free(bl);
}

int main()
{
	BloomFilter *bl = bl_init(1000);
	bl_add(bl, 1);
	bl_add(bl, 2);
	bl_add(bl, 1001);
	bl_add(bl, 1004);

	if(bl_contains(bl, 1))
		printf("bloomfilter contains 1\n");

	if(bl_contains(bl, 2))
		printf("bloomfilter contains 2\n");

	if(!bl_contains(bl, 3))
		printf("bloomfilter not contains 3\n");

	if(bl_contains(bl, 4))
		printf("bloomfilter not contains 4, but return false positive\n");
}



