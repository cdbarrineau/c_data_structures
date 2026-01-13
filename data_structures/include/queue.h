/*
 * queue.h
 *
 *  Created on: Jan 5, 2026
 *  Author: mark2v
 */

#ifndef INCLUDE_QUEUE_H_
#define INCLUDE_QUEUE_H_

#include <pthread.h>

#include "ds_bool.h"
#include "linked_list.h"

typedef struct {

	// The data associated with this node.
	void *data;

} queue_node_t;

typedef struct queue {

	// Current nodes on the queue of type queue_node_t.
	linked_list_t *nodes;

	// When not NULL, will call this function when an item is added.
	void (*handler)(struct queue*, void*);

	// When handler is not NULL, this thread is used to inform the
	// user when a item is added.
	pthread_t thread;

	// Locks access to the thread.
	pthread_mutex_t mutex;

	// TRUE if the thread to drain the queue is running.
	BOOL thread_running;

} queue_t;

/***********************************************************************
 * NAME:		create_queue(void (*)(queue_t*, queue_node_t*))
 *
 * DESCRIPTION:	Creates a new FIFO queue.
 *
 * RETURNS:		Returns the newly created FIFO queue or NULL if memory could
 * 				not be allocated.
 */
queue_t* create_queue(void (*)(queue_t*, void*));

/***********************************************************************
 * NAME:		free_queue(queue_t*)
 *
 * DESCRIPTION:	Frees a FIFO queue's memory.  NOTE: This will NOT free
 * 				any memory for each node's data.
 *
 * PARAMETERS:	queue The queue to free.
 *
 */
void free_queue(queue_t *queue);

/***********************************************************************
 * NAME:		enqueue(queue_t*, void*)
 *
 * DESCRIPTION:	Creates a new queue item, adds it to the back of the queue.
 *
 * PARAMETERS:	data The data to put into the queue node.
 *
 * RETURN:		Returns TRUE if the item was queued, FALSE if not.
 */
BOOL enqueue(queue_t *queue, void *data);

/***********************************************************************
 * NAME:		peek_queue(queue_t*)
 *
 * DESCRIPTION:	Gets the head of the queue without removing it.
 *
 * PARAMETERS:	queue The queue to peek.
 *
 * RETURNS:		Returns the head of the queue or NULL if the queue
 * 				is empty.
 *
 */
queue_node_t* peek_queue(queue_t *queue);

/***********************************************************************
 * NAME:		is_queue_empty(queue_t*)
 *
 * DESCRIPTION:	Determines if the queue is empty or not.
 *
 * PARAMETERS:	queue The queue to check if empty or not.
 *
 * RETURNS:		Returns TRUE if the queue is empty, FALSE if there are
 * 				items on the queue.
 *
 */
BOOL is_queue_empty(queue_t *queue);

#endif /* INCLUDE_QUEUE_H_ */
