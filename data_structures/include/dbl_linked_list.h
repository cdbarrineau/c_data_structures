/*
 * dbl_linked_list.h
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_DBL_LINKED_LIST_H_
#define INCLUDE_DBL_LINKED_LIST_H_

// DEPRECATED linked list.

// Need a tag on this struct because we're referring
// to the struct itself inside the struct.
// However, note that nowhere else do we refer to this
// dll_node tag.  Only refer to the alias dbl_ll_node.
typedef struct dll_node {

	void *data;
	struct dll_node *previous;
	struct dll_node *next;

} dbl_ll_node;

/***********************************************************************
 * NAME:		find_head()
 *
 * DESCRIPTION:	Finds and returns the head of the list.
 *
 * RETURNS:		Returns the head of the list.
 */
dbl_ll_node* find_head(dbl_ll_node *node);

/***********************************************************************
 * NAME:		create_list()
 *
 * DESCRIPTION:	Creates a new linked list.
 *
 * RETURNS:		Returns the lined list node that is the head of the list
 * 				or NULL if memory could not be allocated.
 */
dbl_ll_node* create_list();

/***********************************************************************
 * NAME:		add_node(dbl_ll_node*)
 *
 * DESCRIPTION:	Adds a new node to the end of the linked list.
 *
 * PARAMETERS:	ll The lined list to add the node to.
 *
 * RETURNS:		Returns the created node.
 */
dbl_ll_node* add_node(dbl_ll_node *ll);

/***********************************************************************
 * NAME:		remove_node(dbl_ll_node*)
 *
 * DESCRIPTION:	Removes the specified node, adjusting the previous and next.
 *
 * PARAMETERS:	node The node to remove.
 *
 */
void remove_node(dbl_ll_node *node);

/***********************************************************************
 * NAME:		insert_before(dbl_ll_node*)
 *
 * DESCRIPTION:	Inserts a node before the specified node.
 *
 * PARAMETERS:	node The node to insert before.
 *
 * RETURNS:		Returns the inserted node.
 */
dbl_ll_node* insert_before(dbl_ll_node *node);

/***********************************************************************
 * NAME:		insert_after(dbl_ll_node*)
 *
 * DESCRIPTION:	Inserts a node after the specified node.
 *
 * PARAMETERS:	node The node to insert after.
 *
 * RETURNS:		Returns the inserted node.
 */
dbl_ll_node* insert_after(dbl_ll_node *node);

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
void free_list(dbl_ll_node *list);

#endif /* INCLUDE_DBL_LINKED_LIST_H_ */
