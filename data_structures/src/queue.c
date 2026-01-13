/*
 * queue.c
 *
 *  Created on: Jan 5, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

void* drain_queue(void *arg);

/***********************************************************************
 * NAME:		create_queue(void (*)(queue_t*, queue_node_t*))
 *
 * DESCRIPTION:	Creates a new FIFO queue.
 *
 * RETURNS:		Returns the newly created FIFO queue or NULL if memory could
 * 				not be allocated.
 */
queue_t* create_queue(void (handler)(queue_t*, void*)) {

	queue_t *queue = malloc(sizeof(queue_t));
	if (queue == NULL) {
		fprintf(stderr, "Unable to allocate memory for queue!");
		return NULL;
	}

	linked_list_t *nodes = create_linked_list();
	if (nodes == NULL) {
		free(queue);
		return NULL;
	}

	(*queue).nodes = nodes;
	(*queue).handler = handler;
	(*queue).thread_running = FALSE;

	pthread_mutex_init(&(*queue).mutex, NULL);

	return queue;
}

/***********************************************************************
 * NAME:		free_queue(queue_t*)
 *
 * DESCRIPTION:	Frees a FIFO queue's memory.  NOTE: This will NOT free
 * 				any memory for each node's data.
 *
 * PARAMETERS:	queue The queue to free.
 *
 */
void free_queue(queue_t *queue) {

	if (queue != NULL) {
		pthread_mutex_destroy(&(*queue).mutex);

		free_linked_list((*queue).nodes);

		free(queue);
	}
}

/***********************************************************************
 * NAME:		enqueue(queue_t*, void*)
 *
 * DESCRIPTION:	Creates a new queue item, adds it to the back of the queue.
 *
 * PARAMETERS:	data The data to put into the queue node.
 *
 * RETURN:		Returns TRUE if the item was queued, FALSE if not.
 */
BOOL enqueue(queue_t *queue, void *data) {

	if (push_head((*queue).nodes, data) == NULL) {
		return FALSE;
	}

	if ((*queue).handler != NULL) {
		pthread_mutex_lock(&(*queue).mutex);

		// If there is already a thread running, just queue the data.
		// If not we have to spawn a thread.
		if (!(*queue).thread_running) {
			pthread_create(&(*queue).thread, NULL, drain_queue, queue);

			(*queue).thread_running = TRUE;

			printf("Created new thread.\n");
		}

		pthread_mutex_unlock(&(*queue).mutex);
	}

	return TRUE;
}

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
queue_node_t* peek_queue(queue_t *queue) {
	return peek_linked_list((*queue).nodes);
}

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
BOOL is_queue_empty(queue_t *queue) {
	return is_list_empty((*queue).nodes);
}

/***********************************************************************
 * NAME:		drain_queue(void*)
 *
 * DESCRIPTION:	Loops till all items are drained from the linked list.
 *
 * PARAMETERS:	arg The queue_t to drain.
 *
 * RETURNS:		Returns NULL, required by pthread_create.
 */
void* drain_queue(void *arg) {

	queue_t *queue = (queue_t*)arg;

	pthread_mutex_lock(&(*queue).mutex);

	void *data = remove_end((*queue).nodes);

	pthread_mutex_unlock(&(*queue).mutex);

	while (data != NULL) {
		(*queue).handler(queue, data);

		pthread_mutex_lock(&(*queue).mutex);

		data = remove_end((*queue).nodes);

		printf("Removed end: %p\n", data);

		pthread_mutex_unlock(&(*queue).mutex);
	}

	(*queue).thread_running = FALSE;

	printf("Thread is done draining queue.\n");

	return NULL;
}


