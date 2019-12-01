#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibheap.h"
#include "binheap.h"

// Fibheap functions

struct fib_heap_data *construct(int key)
{
	struct fib_heap_data *foo;
	foo = malloc(sizeof(struct fib_heap_data));
	foo->key = key;
	return foo;
}

int my_compare(struct fib_heap_data *old, struct fib_heap_data *new)
{
	if(new->key < old->key)
		return 1;
	else
		return -1;
}

int rand_number(int lower, int upper)
{
    int num = (rand() % 
           (upper - lower + 1)) + lower; 
    return num;
}

int main()
{
	struct fib_heap_data *fdata[75001];
	int data[75001];

	struct fib_heap_data *ret;
	struct fib_heap *H;
	struct fib_heap_node *node;

    for(int l = 0; l<75000; l++)
    {
        data[l] = rand_number(2, 2000);
	    fdata[l] = construct(data[l]);
    }
	
    clock_t t; 
    t = clock(); 

	H = fibheap_init(100, my_compare);
	node = fibheap_insert(H, fdata[0]);

    for(int j = 0; j < 74999; j++)
    {
        fibheap_insert(H, fdata[j+1]);

        ret = fibheap_extract(H);
        printf("%d\n", ret->key);
        free(ret);
    }

    t = clock() - t; 
    double time_taken1 = ((double)t)/CLOCKS_PER_SEC;

	// fibheap_destroy(H);


    clock_t tt; 
    tt = clock(); 

    struct minHeap HH = initMinHeap(100);

    for(int j = 0; j < 74999; j++)
    {
        insertNode(&HH, data[j+1]);
        deleteNode(&HH);
    }

    tt = clock() - tt; 
    double time_taken2 = ((double)tt)/CLOCKS_PER_SEC;
    printf("Fibonacci Heap Time: %f\n", time_taken1); 
    printf("Binary Heap Time: %f\n", time_taken2); 

	return 0;
}