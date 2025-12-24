/*
 * stack.h
 *
 *  Created on: Dec 24, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

#define MAX_SIZE 100

typedef struct stack_t {

	// The top of the stack.  Which is really just
	// the index into the items array.
	int top;

	// The items on the stack.
	void* items[MAX_SIZE];

} stack;

/***********************************************************************
 * NAME:		create_stack()
 *
 * DESCRIPTION:	Creates a new stack.
 *
 * RETURNS:		Returns the newly created stack or NULL if memory could
 * 				not be allocated.
 */
stack* create_stack();

/***********************************************************************
 * NAME:		free_stack(stack*)
 *
 * DESCRIPTION:	Frees all memory for the stack.  This will NOT cleanup
 * 				any memory allocated for items on the stack.ssword
 *
 * PARAMETERS:	s The stack to clean up.
 */
void free_stack(stack *s);

/***********************************************************************
 * NAME:		push(stack*, void*)
 *
 * DESCRIPTION:	Pushes an item onto the stack.
 *
 * PARAMETERS:	s The stack to push the item onto.
 * 				item The item to push onto the stack.
 *
 * RETURNS:		Returns 0 if the items could not be pushed, 1
 * 				if the item was pushed.
 */
int push(stack *s, void *item);

/***********************************************************************
 * NAME:		pop(stack*)
 *
 * DESCRIPTION:	Pops an item from the stack and returns the item.
 *
 * PARAMETERS:	s The stack to pop the top of the stack.
 *
 * RETURNS:		Returns the last item pushed or NULL if the stack is empty.
 */
void* pop(stack *s);

/***********************************************************************
 * NAME:		peek(stack*)
 *
 * DESCRIPTION:	Returns the current item pointed to on the top of the
 * 				stack without removing it.
 *
 * PARAMETERS:	s The stack to peek the top of the stack.
 *
 * RETURNS:		Returns the last item pushed or NULL if the stack is empty.
 */
void* peek(stack *s);

/***********************************************************************
 * NAME:		is_empty(stack*)
 *
 * DESCRIPTION:	Checks if there are any items on the stack.
 *
 * PARAMETERS:	s The stack to check if it's empty.
 *
 * RETURNS:		Returns 1 if the stack is empty, 0 if not empty.
 */
int is_empty(stack *s);


#endif /* INCLUDE_STACK_H_ */
