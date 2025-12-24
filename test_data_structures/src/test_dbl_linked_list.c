/*
 * test_dbl_linked_list.c
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "dbl_linked_list.h"

#include "../include/test_dbl_linked_list.h"


#define MAX_CHAR 25

// Data for the linked list.
typedef struct ll_data_type {
	int id;
	char* name;
} ll_data;


// Forward declination.
void print_list(dbl_ll_node *node);
void cleanup(dbl_ll_node *node);
void add_data(dbl_ll_node *node, int id, char* name);
void free_data(ll_data *data);

/***********************************************************************
 * NAME:		test_dbl_linked_list()
 *
 * DESCRIPTION:	Tests a doubly linked list.
 *
 */
void test_dbl_linked_list() {

	printf("*****  test_dbl_linked_list  *****\n");

	dbl_ll_node *head = create_list();
	if (head == NULL) {
		return;
	}

	char* head_name = (char*)malloc(sizeof(char) * (MAX_CHAR + 1));
	snprintf(head_name, MAX_CHAR, "Head");

	add_data(head, 0, head_name);

	print_list(head);

	dbl_ll_node *last_node = NULL;

	int len = 3;
	for (int i = 0; i < len; i++) {
		dbl_ll_node *next = add_node(head);
		if (next == NULL) {
			return;
		}

		add_data(next, i + 1, NULL);

		last_node = next;
	}

	print_list(head);

	// We're going to remove this later.
	dbl_ll_node *old_head = head;

	// Insert a node before the head.
	dbl_ll_node *new_head = insert_before(head);
	add_data(new_head, 100, NULL);

	head = new_head;

	print_list(head);

	dbl_ll_node *node_after_head = insert_after(head);
	add_data(node_after_head, 101, NULL);

	print_list(head);

	// Add a node to the end of the list.
	dbl_ll_node *new_last_node = insert_after(last_node);
	add_data(new_last_node, 102, NULL);

	print_list(head);

//	dbl_ll_node *tmp = find_head(new_last_node);
//	ll_data *tmp_data = (ll_data*)tmp->data;
//	printf("tmp: %d %s %p\n", tmp_data->id, tmp_data->name, tmp_data);

	// Remove the old head.  This will be the one after the new head.
	free_data((*old_head).data);
	remove_node(old_head);

	print_list(head);

	cleanup(head);

	free_list(head);
	head = NULL;

	print_list(head);

	printf("Freed Linked List Head: %p\n", head);
}


void print_list(dbl_ll_node *node) {

	if (node == NULL) {
		printf("No node to print!\n");
		return;
	}

	printf("** printing list **\n");

	while (node) {
		ll_data *data = (ll_data*)(*node).data;

		printf("id = %d, name = %s, address = %p\n", (*data).id, (*data).name, data);

		node = (*node).next;
	}
}

void free_data(ll_data *data) {
	free((*data).name);

	free(data);
}

void cleanup(dbl_ll_node *node) {

	while (node) {
		ll_data *data = (*node).data;

		free_data(data);

		node = (*node).next;
	}
}

void add_data(dbl_ll_node *node, int id, char* name) {
	ll_data *data = (ll_data*)malloc(sizeof(ll_data));
	(*data).id = id;

	if (name) {
		(*data).name = name;
	}
	else {
		(*data).name = (char*)malloc(sizeof(char) * (MAX_CHAR + 1));
		snprintf(data->name, MAX_CHAR, "Node #%d", id);
	}

	(*node).data = data;
}



