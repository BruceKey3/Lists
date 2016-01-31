#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static void createNewNode(linked_list_node_t** node, void* data) {
	*node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
	(*node)->data = data;
	(*node)->next = NULL;
}

void initialise(linked_list** list)
{
	*list = (linked_list*)malloc(sizeof(linked_list));
	(*list)->head = NULL;
	(*list)->size = 0;
}

void addLL(linked_list* list, void* data) {
	if (list->head == NULL) {
		createNewNode(&(list->head), data);
	}
	else
	{
		linked_list_node_t* curr = list->head;
		while (curr->next != NULL) curr = curr->next;
		createNewNode(&(curr->next), data);
	}
	(list->size)++;
}

void* getLL(linked_list* list, int index) {
	assert(index < list->size);
	linked_list_node_t* curr = list->head;
	for(int i = 0; i < index; i++)
	{
		assert(curr != NULL);
		curr = curr->next;
	}
	return curr->data;
}
