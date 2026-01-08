/*
 * linked_list.h
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_

#ifndef BOOL

#define TRUE 1
#define FALSE 0
#define BOOL char

#endif


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
linked_list_node_t* add_at_index(linked_list_t *list, void *data, int index);

//void* remove_at_index(linked_list_t *list, int index);








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






///***********************************************************************
// * NAME:		insert_node_before(linked_list_t*, linked_list_node_t*, void*)
// *
// * DESCRIPTION:	Inserts a new node before the specified node.
// *
// * PARAMETERS:	list The linked list to insert the node into.
// * 				node The node to insert before.
// * 				data The data to set on the node.
// *
// * RETURNS:		Returns the created node or NULL if the passed in node
// * 				is not found in the list.
// */
//linked_list_node_t* insert_node_before(
//		linked_list_t *list,
//		linked_list_node_t *node,
//		void *data);


/***********************************************************************
 * NAME:		add_node(dbl_ll_node*)
 *
 * DESCRIPTION:	Adds a new node to the end of the linked list.
 *
 * PARAMETERS:	ll The lined list to add the node to.
 *
 * RETURNS:		Returns the created node.
 */
//linked_list_node_t* add_node(linked_list_node_t *ll);
//
///***********************************************************************
// * NAME:		remove_node(dbl_ll_node*)
// *
// * DESCRIPTION:	Removes the specified node, adjusting the previous and next.
// *
// * PARAMETERS:	node The node to remove.
// *
// */
//void remove_node(linked_list_node_t *node);
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
//linked_list_node_t* insert_before(linked_list_node_t *node);
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
//linked_list_node_t* insert_after(linked_list_node_t *node);


#endif /* INCLUDE_LINKED_LIST_H_ */
