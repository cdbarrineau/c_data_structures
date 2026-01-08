/*
 * test_linked_list.c
 *
 *  Created on: Jan 8, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/test_linked_list.h"
#include <linked_list.h>

// Forward declination.
static void print_list(linked_list_t *list);
static void test_push_head(linked_list_t *list);
static void test_push_end(linked_list_t *list);
static void test_find_by_data(linked_list_t *list);


/***********************************************************************
 * NAME:		test_dbl_linked_list()
 *
 * DESCRIPTION:	Tests a doubly linked list.
 *
 */
void test_linked_list() {

	printf("*****  test_linked_list  *****\n");

	linked_list_t *list = create_linked_list();
	if (list == NULL) {
		return;
	}

	test_push_head(list);
	test_push_end(list);
	test_find_by_data(list);

	free_linked_list(list);
}

static void test_push_head(linked_list_t *list) {
	print_list(list);

	push_head(list, "One");

	print_list(list);

	push_head(list, "Two");

	print_list(list);

	push_head(list, "Three");

	print_list(list);

	char *d1 = remove_head(list);
	printf("Removed head with data: %s\n", d1);

	print_list(list);

	d1 = remove_head(list);
	printf("Removed head with data: %s\n", d1);

	print_list(list);

	d1 = remove_head(list);
	printf("Removed head with data: %s\n", d1);

	print_list(list);

	d1 = remove_head(list);
	printf("Removed head with data: %s\n", d1);

	print_list(list);
}

static void test_push_end(linked_list_t *list) {
	print_list(list);

	push_end(list, "One");

	print_list(list);

	push_end(list, "Two");

	print_list(list);

	push_end(list, "Three");

	print_list(list);

	char *d1 = remove_end(list);
	printf("Removed end with data: %s\n", d1);

	print_list(list);

	d1 = remove_end(list);
	printf("Removed end with data: %s\n", d1);

	print_list(list);

	d1 = remove_end(list);
	printf("Removed end with data: %s\n", d1);

	print_list(list);

	d1 = remove_end(list);
	printf("Removed end with data: %s\n", d1);

	print_list(list);
}

static void test_find_by_data(linked_list_t *list) {

	// Push a few onto the list.
	push_head(list, "Ten");
	push_head(list, "Eleven");

	linked_list_node_t *node = find_node_by_data(list, "Ten");
	if (node == NULL) {
		fprintf(stderr, "Did not find node by data: Ten!\n");
	}
	else {
		char *data = (*node).data;
		printf("Find node by data: %s\n", data);
	}

	// Find something that is not in the list.
	linked_list_node_t *not_found_node = find_node_by_data(list, "Twelve");
	if (not_found_node == NULL) {
		printf("Node not found, but that's what we wanted for Twelve\n");
	}
	else {
		fprintf(stderr, "Found node by data: Twelve!\n");
	}
}

static void print_list(linked_list_t *list) {

	printf("\n***  print_list size: %zu ***\n", (*list).size);

	if (is_list_empty(list)) {
		printf("\tList is empty.\n");
		return;
	}

	linked_list_node_t *node = (*list).head;
	while (node != NULL) {
		printf("\tNode data = %s\n", (char*)(*node).data);

		node = (*node).next;
	}
}

//static void verify_list(linked_list_t *list) {
//
//	size_t i = 1;
//	size_t size = (*list).size;
//
//	if (size == 0) {
//		if ((*list).head != NULL) {
//			fprintf(stderr, "List size is zero but there is a head node!\n");
//		}
//		if ((*list).end != NULL) {
//			fprintf(stderr, "List size is zero but there is an end node!\n");
//		}
//
//		return;
//	}
//
//	// Walk the list and verify the previous and next of each.
//	linked_list_node_t *previous = NULL;
//	linked_list_node_t *next = NULL;
//
//	linked_list_node_t *node = (*list).head;
//	while (node != NULL) {
//
//		// At the first node.
//		if (i == 1) {
//			if ((*node).previous != NULL) {
//				fprintf(stderr, "Head node has a previous node!\n");
//			}
//		}
//		// At the last node.
//		else if (i == size) {
//			if ((*node).next != NULL) {
//				fprintf(stderr, "End node has a next node!\n");
//			}
//		}
//		// Somewhere in the middle.  Check previous and next.
//		else {
//
//		}
//
//		previous = (*node).previous;
//		next = (*node).next;
//
//		node = (*node).next;
//		i++;
//	}
//}







