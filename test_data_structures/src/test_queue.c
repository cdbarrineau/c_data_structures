/*
 * test_queue.c
 *
 *  Created on: Jan 12, 2026
 *  Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>



#include "queue.h"
#include "ds_bool.h"

#include "../include/test_queue.h"

void handle_queue_node(queue_t *queue, void* node);
void print_queue(queue_t *queue);

/***********************************************************************
 * NAME:		test_queue()
 *
 * DESCRIPTION:	Tests the queue implementation.
 *
 */
void test_queue() {

	queue_t *queue = create_queue(handle_queue_node);

	for (int i = 0; i < 10; i++) {
		char *s = (char*)malloc(sizeof(char) * 30);
		snprintf(s, 30, "Test-%d", i);

		printf("Queuing data %s : %p\n", s, &s);

		BOOL success = enqueue(queue, s);
		if (!success) {
			fprintf(stderr, "Unable to push item on queue!");
		}

//		sleep(1);
	}

	pthread_t thread = (*queue).thread;
//	if (thread != NULL) {
		printf("Joining thread.\n");
		pthread_join(thread, NULL);
		printf("Thread joined\n");
//	}

//	BOOL success = enqueue(queue, "Test1");
//	if (success) {
//		printf("Item pushed onto queue.");
//
//		sleep(3);
//
//		pthread_t *thread = (*queue).thread;
//		if (thread != NULL) {
//			printf("Joining thread.\n");
//			pthread_join(*thread, NULL);
//		}
//
//		printf("Done with test_queue.\n");
//	}
//	else {
//		fprintf(stderr, "Unable to push item on queue!");
//	}

	printf("Done with test_queue\n");

	free_queue(queue);
}


void handle_queue_node(queue_t *queue, void* arg) {

	char *data = (char*)arg;

	printf("Handling Queue Node with data: %s\n", data);

	free(data);
}


void print_queue(queue_t *queue) {


}
