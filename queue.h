#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int back;
    int size;
    unsigned int capacity;
    int *array;
};

// Referencing http://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/, http://opendatastructures.org/ods-cpp/2_3_Array_Based_Queue.html

struct Queue* init_queue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0; 
    queue->back = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}
 
// Check if queue hits capacity
int is_full(struct Queue* queue)
{  
    return queue->size == queue->capacity;  
}
 
// Check if queue holds no values
int is_empty(struct Queue* queue)
{  
    return queue->size == 0; 
}
 
// Add item to queue; edit back and size
void enqueue(struct Queue* queue, int item)
{
    if (is_full(queue))
        return;
    // Modulus causes wrap-around effect
    queue->back = (queue->back + 1)%queue->capacity;
    queue->array[queue->back] = item;
    queue->size++;
}
 
// Add item to queue; edit front and size
int dequeue(struct Queue* queue)
{
    // Return negative 1 since pthread_self() > 0
    if (is_empty(queue))
        return -1;
    int item = queue->array[queue->front];
    // Modulus causes wrap-around effect
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size--;
    return item;
}

#endif
