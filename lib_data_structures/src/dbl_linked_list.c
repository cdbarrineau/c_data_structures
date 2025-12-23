/*
 * dbl_linked_list.c
 *
 *  Created on: Dec 23, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/dbl_linked_list.h"


/***********************************************************************
 * NAME:		find_head()
 *
 * DESCRIPTION:	Finds and returns the head of the list.
 *
 * RETURNS:		Returns the head of the list.
 */
dbl_ll_node* find_head(dbl_ll_node *node) {
	dbl_ll_node *head = node;

	while ((*node).previous) {
		if ((*node).previous) {
			head = find_head((*node).previous);
		}

		return head;
	}

	return head;
}

/***********************************************************************
 * NAME:		create()
 *
 * DESCRIPTION:	Creates a new linked list.
 *
 * RETURNS:		Returns the lined list node that is the head of the list
 * 				or NULL if memory could not be allocated.
 */
dbl_ll_node* create_list() {

	dbl_ll_node *head = (dbl_ll_node*)malloc(sizeof(dbl_ll_node));
	if (head == NULL) {
		fprintf(stderr, "Unable to allocate linked list!");
		return NULL;
	}

	(*head).next = NULL;
	(*head).previous = NULL;

	return head;
}

/***********************************************************************
 * NAME:		add_node(dbl_ll_node*)
 *
 * DESCRIPTION:	Adds a new node to the end of the linked list.
 *
 * PARAMETERS:	ll The lined list to add the node to.
 *
 * RETURNS:		Returns the created node.
 */
dbl_ll_node* add_node(dbl_ll_node *node) {
	dbl_ll_node *new_node = (dbl_ll_node*)malloc(sizeof(dbl_ll_node));
	if (new_node == NULL) {
		fprintf(stderr, "Unable to allocation linked list node!");
		return NULL;
	}

	// Find the end of the list.
	dbl_ll_node *end = node;
	while ((*end).next != NULL) {
		end = (*end).next;
	}

	(*new_node).previous = end;
	(*new_node).next = NULL;

	(*end).next = new_node;

	return new_node;
}

/***********************************************************************
 * NAME:		remove_node(dbl_ll_node*)
 *
 * DESCRIPTION:	Removes the specified node, adjusting the previous and next.
 *
 * PARAMETERS:	node The node to remove.
 */
void remove_node(dbl_ll_node *node) {

	// Get the node before and after this node.
	dbl_ll_node *previous = NULL;
	if ((*node).previous) {
		previous = (*node).previous;
	}

	dbl_ll_node *next = NULL;
	if ((*node).next) {
		next = (*node).next;
	}

	if (previous) {
		(*previous).next = next;
	}

	if (next) {
		(*next).previous = previous;
	}

	free(node);
}

/***********************************************************************
 * NAME:		insert_before(dbl_ll_node*)
 *
 * DESCRIPTION:	Inserts a node before the specified node.
 *
 * PARAMETERS:	node The node to insert before.
 *
 * RETURNS:		Returns the inserted node.
 */
dbl_ll_node* insert_before(dbl_ll_node* node) {

	// Create a new node.
	dbl_ll_node *new_node = (dbl_ll_node*)malloc(sizeof(dbl_ll_node));
	if (new_node == NULL) {
		fprintf(stderr, "Unable to allocate node!");
		return NULL;
	}

	// Get any node before and after this one.
	dbl_ll_node *previous = (*node).previous;
	dbl_ll_node *next = (*node).next;

	// Set the links on the nodes.
	// Takes care if node is the head.
	if (previous) {
		(*previous).next = new_node;
	}
	// Takes care if node is last.
	if (next) {
		(*next).previous = new_node;
	}

	(*new_node).previous = previous;
	(*new_node).next = node;

	return new_node;
}

/***********************************************************************
 * NAME:		insert_after(dbl_ll_node*)
 *
 * DESCRIPTION:	Inserts a node after the specified node.
 *
 * PARAMETERS:	node The node to insert after.
 *
 * RETURNS:		Returns the inserted node.
 */
dbl_ll_node* insert_after(dbl_ll_node *node) {

	dbl_ll_node *new_node = (dbl_ll_node*)malloc(sizeof(dbl_ll_node));
	if (new_node == NULL) {
		fprintf(stderr, "Unable to allocate node!");
		return NULL;
	}

	dbl_ll_node *next = (*node).next;

	(*node).next = new_node;

	(*new_node).previous = node;
	(*new_node).next = next;

	if (next) {
		(*next).previous = new_node;
	}

	return new_node;
}

/***********************************************************************
 * NAME:		free_linkedlist(dbl_ll_node)
 *
 * DESCRIPTION:	Frees all memory for the linked list node.  This will
 * 				traverse both directions freeing any memory in the
 * 				previous and next nodes.
 *
 * PARAMETERS:	The linked list to free.
 *
 */
void free_list(dbl_ll_node *list) {

	// Find the head and traverse till all is freed.
	dbl_ll_node *node = find_head(list);
	while (node) {
		// Get a handle to the next node.
		dbl_ll_node *next = (*node).next;

		(*node).next = NULL;
		(*node).previous = NULL;

		free(node);

		node = next;
	}
}

