/*
 * test_stack.c
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#include "../include/test_stack.h"

void print_stack(stack *s);

/***********************************************************************
 * NAME:		test_stack()
 *
 * DESCRIPTION:	Tests a stack.
 *
 */
void test_stack() {

	printf("*****  test_stack  *****\n");

	stack *s1 = create_stack();

	stack *s2 = create_stack();

	for (int i = 0; i < 3; i++) {
		char *buf = (char*)malloc(sizeof(char) * (10));
		snprintf(buf, 9, "Item %d", i);

		push(s1, buf);
	}

	char* peeked = (char*)peek(s1);
	printf("Peeked item: %s\n", peeked);

	printf("s1 is empty: %d\n", is_empty(s1));
	printf("s2 is empty: %d\n", is_empty(s2));

	char* item = (char*)pop(s1);
	while (item) {
		printf("Popped item %s\n", item);

		free(item);

		item = (char*)pop(s1);
	}

	free_stack(s1);
	free_stack(s2);
}

void print_stack(stack *s) {

}


