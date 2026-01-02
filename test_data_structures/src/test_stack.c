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

	int s1_empty = is_empty(s1);
	int s2_empty = is_empty(s2);

	printf("s1 is %s\n", s1_empty ? "empty" : "not empty");
	printf("s2 is %s\n", s2_empty ? "empty" : "not empty");

	char* peeked = (char*)peek(s1);
	printf("Peeked item in s1: %s\n\n", peeked);


	char* item = (char*)pop(s1);
	while (item) {
		printf("Popped item in s1: %s\n", item);

		free(item);

		item = (char*)pop(s1);
	}

	free_stack(s1);
	free_stack(s2);
}

void print_stack(stack *s) {

}


