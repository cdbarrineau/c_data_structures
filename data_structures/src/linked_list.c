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
 * NAME:		add_at_index(linked_list_t*, void*, int)
 *
 * DESCRIPTION:	Adds a new node at the specified index the linked list.
 *
 * PARAMETERS:	list The linked list to add the node to.
 * 				data The data to set on the node.
 * 				index The zero-based index to insert the node into.
 *
 * RETURNS:		Returns the created node or NULL if the index is out
 * 				of bounds or memory could not be allocated for the node.
 */
linked_list_node_t* add_at_index(linked_list_t *list, void *data, int index) {

	if (index == 0) {
		return push_head(list, data);
	}
	else if ((*list).size == index) {
		return push_end(list, data);
	}
	else if (((*list).size - 1) < index) {
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

	linked_list_node_t *curr = (*list).head;
	while (curr != NULL) {
		if (i == index) {
			(*node).previous = curr;

			if ((*curr).previous != NULL) {
//				(*curr).next = node;
			}


			(*curr).next = node;


			return node;
		}

		i++;
		curr = (*curr).next;
	}

	return NULL;
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




//
///***********************************************************************
// * NAME:		find_head()
// *
// * DESCRIPTION:	Finds and returns the head of the list.
// *
// * RETURNS:		Returns the head of the list.
// */
//linked_list_node_t* find_head(linked_list_node_t *node) {
//	linked_list_node_t *head = node;
//
//	while ((*node).previous) {
//		if ((*node).previous) {
//			head = find_head((*node).previous);
//		}
//
//		return head;
//	}
//
//	return head;
//}

//
///***********************************************************************
// * NAME:		add_node(dbl_ll_node*)
// *
// * DESCRIPTION:	Adds a new node to the end of the linked list.
// *
// * PARAMETERS:	ll The lined list to add the node to.
// *
// * RETURNS:		Returns the created node.
// */
//linked_list_node_t* add_node(linked_list_node_t *node) {
//	linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
//	if (new_node == NULL) {
//		fprintf(stderr, "Unable to allocation linked list node!\n");
//		return NULL;
//	}
//
//	// Find the end of the list.
//	linked_list_node_t *end = node;
//	while ((*end).next != NULL) {
//		end = (*end).next;
//	}
//
//	(*new_node).previous = end;
//	(*new_node).next = NULL;
//
//	(*end).next = new_node;
//
//	return new_node;
//}
//
///***********************************************************************
// * NAME:		remove_node(dbl_ll_node*)
// *
// * DESCRIPTION:	Removes the specified node, adjusting the previous and next.
// *
// * PARAMETERS:	node The node to remove.
// */
//void remove_node(linked_list_node_t *node) {
//
//	// Get the node before and after this node.
//	linked_list_node_t *previous = NULL;
//	if ((*node).previous) {
//		previous = (*node).previous;
//	}
//
//	linked_list_node_t *next = NULL;
//	if ((*node).next) {
//		next = (*node).next;
//	}
//
//	if (previous) {
//		(*previous).next = next;
//	}
//
//	if (next) {
//		(*next).previous = previous;
//	}
//
//	free(node);
//}
//
///***********************************************************************
// * NAME:		insert_before(dbl_ll_node*)
// *
// * DESCRIPTION:	Inserts a node before the specified node.
// *
// * PARAMETERS:	node The node to insert before.
// *
// * RETURNS:		Returns the inserted node.
// */
//linked_list_node_t* insert_before(linked_list_node_t* node) {
//
//	// Create a new node.
//	linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
//	if (new_node == NULL) {
//		fprintf(stderr, "Unable to allocate node!\n");
//		return NULL;
//	}
//
//	// Get any node before and after this one.
//	linked_list_node_t *previous = (*node).previous;
//	linked_list_node_t *next = (*node).next;
//
//	// Set the links on the nodes.
//	// Takes care if node is the head.
//	if (previous) {
//		(*previous).next = new_node;
//	}
//	// Takes care if node is last.
//	if (next) {
//		(*next).previous = new_node;
//	}
//
//	(*new_node).previous = previous;
//	(*new_node).next = node;
//
//	return new_node;
//}
//
///***********************************************************************
// * NAME:		insert_after(dbl_ll_node*)
// *
// * DESCRIPTION:	Inserts a node after the specified node.
// *
// * PARAMETERS:	node The node to insert after.
// *
// * RETURNS:		Returns the inserted node.
// */
//linked_list_node_t* insert_after(linked_list_node_t *node) {
//
//	linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
//	if (new_node == NULL) {
//		fprintf(stderr, "Unable to allocate node!\n");
//		return NULL;
//	}
//
//	linked_list_node_t *next = (*node).next;
//
//	(*node).next = new_node;
//
//	(*new_node).previous = node;
//	(*new_node).next = next;
//
//	if (next) {
//		(*next).previous = new_node;
//	}
//
//	return new_node;
//}



