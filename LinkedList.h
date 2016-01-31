#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>

/*	USAGE

   	linked_list* list;
	initialise(&list);
	int one = 609;
	int* ptr = &one;
	addLL(list, ptr);
	ptr = (int*)getLL(list,0);
	printf("%d\n", *ptr);

 */

typedef struct linked_list_node_s
{
	void* data;
	struct linked_list_node_s* next;
} linked_list_node_t;


typedef struct linked_list
{
	linked_list_node_t* head;
	int size;
}linked_list;

void initialise(linked_list**);

void addLL(linked_list*, void*);

void* getLL(linked_list*, int);

#endif /* LINKEDLIST_H_ */
