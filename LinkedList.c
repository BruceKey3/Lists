#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static void createNewNode(linked_list_node_t**,void*);

static void createNewNode(linked_list_node_t** node, void* data) {
	(*node) = malloc(sizeof(linked_list_node_t));
	(*node)->data = data;
	(*node)->next = NULL;
}

void initialise(linked_list* list)
{
	list->head = NULL;
	list->size = 0;
}

void addLL(linked_list* list, void* data) {
	assert(list);
	if (!(list->head)) {
		createNewNode(&list->head, data);
	}
	else
	{
		linked_list_node_t* curr = list->head;
		while (curr->next != NULL) curr = curr->next;
		createNewNode(&curr->next, data);
	}
	(list->size)++;
}

void* getLL(linked_list* list, int index) {
	assert(list);
	assert(index >= 0 && index < list->size);

	linked_list_node_t* curr = list->head;
	for(int i = 0; i < index; i++)
	{
		assert(curr);
		curr = curr->next;
	}
	return curr->data;
}
