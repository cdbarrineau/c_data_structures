/*
 * queue.c
 *
 *  Created on: Jan 5, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void dequeue(queue_t* queue, queue_node_t node);

/***********************************************************************
 * NAME:		create_queue()
 *
 * DESCRIPTION:	Creates a new FIFO queue.
 *
 * RETURNS:		Returns the newly created FIFO queue or NULL if memory could
 * 				not be allocated.
 */
queue_t* create_queue(void (handler)(queue_t*, queue_node_t)) {

	queue_t *queue = malloc(sizeof(queue_t));
	if (queue == NULL) {
		fprintf(stderr, "Unable to allocate memory for queue!");
		return NULL;
	}

	(*queue).handler = handler;

	return queue;
}


/***********************************************************************
 * NAME:		free_queue()
 *
 * DESCRIPTION:	Frees a FIFO queue's memory.  NOTE: This will NOT free
 * 				any memory for each node's data.
 *
 */
void free_queue(queue_t *queue) {

	if (queue != NULL) {
		free(queue);
	}
}

/***********************************************************************
 * NAME:		enqueue()
 *
 * DESCRIPTION:	Creates a new queue item, adds it to the back of the queue.
 *
 * PARAMETERS:	data The data to put into the queue node.
 *
 */
void enqueue(void *data) {

}

/***********************************************************************
 * NAME:		peek_queue()
 *
 * DESCRIPTION:	Gets the head of the queue without removing it.
 *
 * RETURNS:		Returns the head of the queue or NULL if the queue
 * 				is empty.
 *
 */
queue_node_t peek_queue() {

	queue_node_t node;
	node.data = NULL;

	return node;
}

/***********************************************************************
 * NAME:		is_queue_empty()
 *
 * DESCRIPTION:	Determines if the queue is empty or not.
 *
 * RETURNS:		Returns 0 if the queue is empty, non-zsero if there are
 * 				items on the queue.
 *
 */
int is_queue_empty() {
	return 0;
}

/***********************************************************************
 * NAME:		register_handler(queue_t* queue_node_t)
 *
 * DESCRIPTION:	Registers a new queue handler for when an item is removed
 * 				from the specified queue.
 *
 * PARAMETERS:	The function definition which looks like:
 * 					void handler(queue_t*, queue_node_t) { ... }
 *
 */
//void register_handler(void (handler)(queue_t*, queue_node_t)) {
//
//
//}


void dequeue(queue_t* queue, queue_node_t node) {

}

