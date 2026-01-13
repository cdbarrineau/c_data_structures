/*
 * linked_list.h
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_

#include "ds_bool.h"


// Need a tag on this struct because we're referring
// to the struct itself inside the struct.
// However, note that nowhere else do we refer to this
// linked_list_node tag.  Only refer to the alias linked_list_node_t.

/*
 * A node in the doubly-linked list.
 *
 */
typedef struct linked_list_node {

	// The data associated with this node.
	void *data;

	// The previous node or NULL if this is the head.
	struct linked_list_node *previous;

	// The next node or NULL if this is the end.
	struct linked_list_node *next;

} linked_list_node_t;

/*
 * A doubly-linked list.
 *
 */
typedef struct {

	// The head of the linked list.
	linked_list_node_t *head;

	// The end of the linked list.
	linked_list_node_t *end;

	// Number of nodes in the linked list.
	size_t size;

} linked_list_t;


/***********************************************************************
 * NAME:		create_linked_list()
 *
 * DESCRIPTION:	Creates a new linked list.
 *
 * RETURNS:		Returns the linked list or NULL if memory could not be allocated.
 *
 */
linked_list_t* create_linked_list();

/***********************************************************************
 * NAME:		free_linkedlist(linked_list_t*)
 *
 * DESCRIPTION:	Frees all memory for the linked list.  This will
 * 				traverse all nodes freeing all nodes.  This will NOT
 * 				free the data in each node.
 *
 * PARAMETERS:	The linked list to free.
 *
 */
void free_linked_list(linked_list_t *list);

/***********************************************************************
 * NAME:		is_list_empty(linked_list_t*)
 *
 * DESCRIPTION:	Checks if the linked list is empty.
 *
 * PARAMETERS:	list The linked list to check if it's empty.
 *
 * RETURNS:		Returns TRUE if the linked list is empty, FALSE if not.
 */
BOOL is_list_empty(linked_list_t* list);

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
linked_list_node_t* push_head(linked_list_t *list, void *data);

/***********************************************************************
 * NAME:		remove_head(linked_list_t*)
 *
 * DESCRIPTION:	Removes the head of the list and returns the data of the
 * 				head node.
 *
 * PARAMETERS:	list The linked list to remove the node from.
 *
 * RETURNS:		Returns the head node's data or NULL if the list is empty.
 */
void* remove_head(linked_list_t *list);

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
linked_list_node_t* push_end(linked_list_t *list, void *data);

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
void* remove_end(linked_list_t *list);

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
linked_list_node_t* insert_at_index(linked_list_t *list, void *data, int index);

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
void* remove_at_index(linked_list_t *list, int index);

/***********************************************************************
 * NAME:		clear_linked_list(linked_list_t*)
 *
 * DESCRIPTION:	Removes all nodes in the linked list.
 *
 * PARAMETERS:	list The linked list to clear all nodes.
 *
 */
void clear_linked_list(linked_list_t *list);

/***********************************************************************
 * NAME:		peek_linked_list(linked_list_t*)
 *
 * DESCRIPTION:	Gets the head of the list without removing it.
 *
 * PARAMETERS: 	list The linked list to peek at the head.
 *
 * RETURNS:		Returns the head's data of the list or NULL if there is none.
 */
void* peek_linked_list(linked_list_t *list);

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
linked_list_node_t* find_node_by_data(linked_list_t *list, void *data);

#endif /* INCLUDE_LINKED_LIST_H_ */
