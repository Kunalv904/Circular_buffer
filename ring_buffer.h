#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define BUFFER_CAPACITY 5

struct circular_buffer{
    int head;
    int tail;
    int avail;
    int arr[BUFFER_CAPACITY];
};

typedef struct circular_buffer buffer;

void initialise(buffer *);

int is_empty(buffer *);

int is_full(buffer *);

void push(buffer *, int);

void pop(buffer *, int *);

int capacity(buffer *);

int size(buffer *);

void clear(buffer *);

void list(buffer *);

#endif