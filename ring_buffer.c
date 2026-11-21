#include <stdio.h>
#include "ring_buffer.h"

#define printName(buf) printf("\n"#buf)

void initialise(buffer * b){
    b->head = 0;
    b->tail = 0;
    b->avail = BUFFER_CAPACITY;
    printName(b);
    printf(" is initialized/cleared!!\n");
}

int is_empty(buffer *b){
    if(b->avail==BUFFER_CAPACITY)
    return 1;
    else
    return 0;
}

int is_full(buffer *b){
    if(b->avail==0)
    return 1;
    else
    return 0;
}

void push(buffer *b, int data){
    if(is_full(b)){
        printName(b);
        printf(" is full. Can't push %d.\n", data);
        return;
    }

    b->arr[b->head] = data;
    b->head = (b->head + 1)%BUFFER_CAPACITY;
    b->avail = b->avail -1;
}

void pop(buffer *b, int *data){
    
    if(data==NULL){
        printf("You are trying to have the popped data in a NULL pointer. Not allowed.\n");
        return;
    }
    
    if(is_empty(b)){
        printName(b);
        printf("is empty. Nothing to pop.\n");
        return;
    }

    *data = b->arr[b->tail];
    b->tail = (b->tail +1)%BUFFER_CAPACITY;
    b->avail = b->avail +1;
}

int capacity(buffer *b){
    return BUFFER_CAPACITY;
}

int size(buffer *b){
    return BUFFER_CAPACITY - (b->avail);
}

void clear(buffer *b){
    initialise(b);
}

void list(buffer *b){
    if(is_empty(b)){
        printName(b);
        printf("is empty. Nothing to list.\n");
        return;
    }

    int start, num;
    start = b->tail;
    num = size(b);

    printf("Elements of ");
    printName(b);
    printf(" are: ");

    for(int i = 0;i<num;i++){
        printf("%d ", b->arr[start]);
        start = (start+1)%BUFFER_CAPACITY;
    }
}