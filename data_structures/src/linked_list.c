/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

// Forward declarations.
//static linked_list_node_t* malloc_node(void *data);
//static void* free_node(linked_list_node_t *node);

/***********************************************************************
 * NAME:		create_linked_list()
 *
 * DESCRIPTION:	Creates a new linked list.
 *
 * RETURNS:		Returns the linked list or NULL if memory could not be allocated.
 *
 */
linked_list_t* create_linked_list() {

	linked_list_t *list = malloc(sizeof(linked_list_t));
	if (list == NULL) {
		fprintf(stderr, "Unable to allocate linked list!\n");
		return NULL;
	}

	(*list).head = NULL;
	(*list).end = NULL;
	(*list).size = 0;

	return list;
}

/***********************************************************************
 * NAME:		free_linked_list(linked_list_t*)
 *
 * DESCRIPTION:	Frees all memory for the linked list.  This will
 * 				traverse all nodes freeing all nodes.  This will NOT
 * 				free the data in each node.
 *
 * PARAMETERS:	The linked list to free.
 *
 */
void free_linked_list(linked_list_t *list) {

	linked_list_node_t *node = (*list).head;
	while (node != NULL) {
		linked_list_node_t *next = (*node).next;

		(*node).previous = NULL;
		(*node).next = NULL;
		(*node).data = NULL;

		free(node);

		node = next;
	}

	(*list).head = NULL;
	(*list).end = NULL;

	free(list);
}

/***********************************************************************
 * NAME:		is_list_empty(linked_list_t*)
 *
 * DESCRIPTION:	Checks if the linked list is empty.
 *
 * PARAMETERS:	list The linked list to check if it's empty.
 *
 * RETURNS:		Returns TRUE if the linked list is empty, FALSE if not.
 */
BOOL is_list_empty(linked_list_t* list) {
	return (*list).size == 0;
}

/***********************************************************************
 * NAME:		push_head(linked_list_t*, void*)
 *
 * DESCRIPTION:	Adds a new node to the head of the linked list.
 *
 * PARAMETERS:	list The linked list to add the node to.
 * 				data The data to set on the node.
 *
 * RETURNS:		Returns the created node or NULL if memory could
 * 				not be allocated for the node.
 */
linked_list_node_t* push_head(linked_list_t *list, void *data) {

	linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
	if (node == NULL) {
		fprintf(stderr, "Unable to allocate memory for linked list node!\n");
		return NULL;
	}

	(*node).data = data;
	(*node).next = NULL;
	(*node).previous = NULL;

	// Get the current head and set the new node's next to it.
	linked_list_node_t *curr_head = (*list).head;
	if (curr_head == NULL) {
		(*list).head = (*list).end = node;
	}
	else {
		(*node).next = curr_head;

		(*list).head->previous = node;
		(*list).head = node;
	}

	(*list).size++;

	return node;
}

/***********************************************************************
 * NAME:		remove_head(linked_list_t*)
 *
 * DESCRIPTION:	Removes the head of the list and returns the data of the
 * 				head node.
 *
 * PARAMETERS:	list The linked list to add the node to.
 *
 * RETURNS:		Returns the head node's data or NULL if the list is empty.
 */
void* remove_head(linked_list_t *list) {

	if ((*list).head == NULL) {
		fprintf(stderr, "Can not remove HEAD of linked list from empty list.\n");
		return NULL;
	}

	linked_list_node_t *head = (*list).head;

	void *data = (*head).data;

	if ((*head).next) {
		(*list).head = (*head).next;
		(*list).head->previous = NULL;
	}
	// No next node, list is now empty to set head and end to NULL.
	else {
		(*list).head = NULL;
		(*list).end = NULL;
	}

	(*head).data = NULL;
	(*head).previous = NULL;
	(*head).next = NULL;

	free(head);

	if ((*list).size > 0) {
		(*list).size--;
	}

	return data;
}

/***********************************************************************
 * NAME:		push_end(linked_list_t*, void*)
 *
 * DESCRIPTION:	Adds a new node to the end of the linked list.
 *
 * PARAMETERS:	list The linked list to add the node to.
 * 				data The data to set on the node.
 *
 * RETURNS:		Returns the created node or NULL if memory could
 * 				not be allocated for the node.
 */
linked_list_node_t* push_end(linked_list_t *list, void *data) {

	linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
	if (node == NULL) {
		fprintf(stderr, "Unable to allocate memory for linked list node!\n");
		return NULL;
	}

	(*node).data = data;
	(*node).next = NULL;
	(*node).previous = NULL;

	linked_list_node_t *curr_end = (*list).end;
	if (curr_end == NULL) {
		(*list).head = (*list).end = node;
	}
	else {
		(*curr_end).next = node;

		(*list).end = node;
		(*list).end->previous = curr_end;
	}

	(*list).size++;

	return node;
}

/***********************************************************************
 * NAME:		remove_end(linked_list_t*)
 *
 * DESCRIPTION:	Removes the end of the list and returns the data of the
 * 				node.
 *
 * PARAMETERS:	list The linked list to remove the node from.
 *
 * RETURNS:		Returns the end node's data or NULL if the list is empty.
 */
void* remove_end(linked_list_t *list) {

	if ((*list).end == NULL) {
		fprintf(stderr, "Can not remove END of linked list from empty list.\n");
		return NULL;
	}

	linked_list_node_t *end = (*list).end;

	void *data = (*end).data;

	(*list).end = (*end).previous;

	linked_list_node_t *new_end = (*list).end;
	if (new_end != NULL) {
		(*new_end).next = NULL;
	}
	// No more items.
	else {
		(*list).head = NULL;
	}

	(*end).previous = NULL;
	(*end).next = NULL;
	(*end).data = NULL;

	free(end);

	if ((*list).size > 0) {
		(*list).size--;
	}

	return data;
}

/***********************************************************************
 * NAME:		insert_at_index(linked_list_t*, void*, int)
 *
 * DESCRIPTION:	Inserts a new node at the specified index the linked list.
 *
 * PARAMETERS:	list The linked list to insert the node to.
 * 				data The data to set on the node.
 * 				index The zero-based index to insert the node into.  Only
 * 				caveat is that if the index is equal to the current size,
 * 				the node will be inserted at the end.
 *
 * RETURNS:		Returns the created node or NULL if the index is out
 * 				of bounds or memory could not be allocated for the node.
 */
linked_list_node_t* insert_at_index(linked_list_t *list, void *data, int index) {

	if (index == 0) {
		return push_head(list, data);
	}
	else if ((*list).size == index) {
		return push_end(list, data);
	}
	else if (index < 0) {
		fprintf(stderr, "Invalid index to insert in linked list %d\n", index);
		return NULL;
	}
	else if (((*list).size - 1) < index) {
		fprintf(stderr, "Invalid index to insert in linked list %d\n", index);
		return NULL;
	}

	// Insert somewhere in the middle.
	linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
	if (node == NULL) {
		fprintf(stderr, "Unable to allocate memory for linked list node!\n");
		return NULL;
	}

	(*node).data = data;
	(*node).next = NULL;
	(*node).previous = NULL;

	// Look for the insertion point.
	int i = 0;

	linked_list_node_t *previous = NULL;
	linked_list_node_t *curr = (*list).head;
	while (curr != NULL) {
		if (i == index) {
			(*previous).next = node;
			(*node).next = curr;
			(*curr).previous = node;

			(*list).size++;

			return node;
		}

		previous = curr;

		i++;
		curr = (*curr).next;
	}

	return NULL;
}

/***********************************************************************
 * NAME:		remove_at_index(linked_list_t*, int)
 *
 * DESCRIPTION:	Removes the node at the specified 0-based index.
 *
 * PARAMETERS:	list The linked list to remove the node from.
 * 				index The index to remove the node.
 *
 * RETURNS:		Returns the end node's data or NULL if the list is empty
 * 				or the index is out of bounds.
 */
void* remove_at_index(linked_list_t *list, int index) {

	if (index == 0) {
		return remove_head(list);
	}
	else if (index == (*list).size - 1) {
		return remove_end(list);
	}
	else if (index < 0) {
		fprintf(stderr, "Invalid index to remove in linked list %d\n", index);
		return NULL;
	}
	else if (index >= ((*list).size)) {
		fprintf(stderr, "Invalid index to remove in linked list %d\n", index);
		return NULL;
	}

	int i = 0;
	linked_list_node_t *previous = NULL;
	linked_list_node_t *node = (*list).head;
	while (node != NULL) {
		if (i == index) {
			void *data = (*node).data;

			// Previous should never be null as we took care of
			// the head at the start of this function.
			(*previous).next = (*node).next;
			(*node).next->previous = previous;

			free(node);

			(*list).size--;

			return data;
		}

		previous = node;
		i++;
		node = (*node).next;
	}

	return NULL;
}

/***********************************************************************
 * NAME:		clear_linked_list(linked_list_t*)
 *
 * DESCRIPTION:	Removes all nodes in the linked list.
 *
 * PARAMETERS:	list The linked list to clear all nodes.
 *
 */
void clear_linked_list(linked_list_t *list) {

	linked_list_node_t *node = (*list).head;
	while (node != NULL) {
		remove_end(list);

		node = (*list).head;
	}
}

/***********************************************************************
 * NAME:		find_node_by_data(linked_list_t*, void*)
 *
 * DESCRIPTION:	Finds a node by the data.
 *
 * PARAMETERS:	list The linked list to find the data in.
 * 				data The data to find the node of.
 *
 * RETURNS:		Returns the node with the data or NULL if not found.
 */
linked_list_node_t* find_node_by_data(linked_list_t *list, void *data) {

	linked_list_node_t *node = (*list).head;
	while (node != NULL) {
		if ((*node).data == data) {
			return node;
		}

		node = (*node).next;
	}

	return NULL;
}


//static linked_list_node_t* malloc_node(void *data) {
//	linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
//	if (node == NULL) {
//		fprintf(stderr, "Unable to allocate memory for linked list node!\n");
//		return NULL;
//	}
//
//	(*node).data = data;
//	(*node).next = NULL;
//	(*node).previous = NULL;
//
//	return node;
//}

//static void* free_node(linked_list_node_t *node) {
//	void *data = (*node).data;
//
//	(*node).data = NULL;
//	(*node).previous = NULL;
//	(*node).next = NULL;
//
//	free(node);
//
//	if ((*list).size > 0) {
//			(*list).size--;
//		}
//
//	return data;
//}

