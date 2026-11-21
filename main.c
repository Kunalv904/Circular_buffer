#include <stdio.h>
#include "ring_buffer.h"

int main(){
    buffer buf1, buf2;
    int popped_data;

    initialise(&buf1);
    initialise(&buf2);

    if(is_empty(&buf1)){
        printf("Buf1 is empty\n");
        push(&buf1, 50);
        push(&buf1, 100);
        push(&buf1, 150);
        push(&buf1, 200);
        push(&buf1, 250);
        push(&buf1, 300);
    }

    list(&buf1);

    if(is_full(&buf2)){                     // To test the is_full() on empty buffer
        printf("isfull() worked on empty buffer----- ERROR\n");
    }
    else{
        printf("is_full() worked correctly!!\n");
    }

    if(is_empty(&buf2)){
        pop(&buf2,&popped_data);            // To test the pop() on empty buffer
    }

    pop(&buf1,&popped_data);
    printf("Popped data is %d\n", popped_data);
    pop(&buf1,&popped_data);
    printf("Popped data is %d\n", popped_data);
    pop(&buf1,&popped_data);
    printf("Popped data is %d\n", popped_data);

    push(&buf1, 300);
    push(&buf1, 350);
    push(&buf1, 400);

    list(&buf1);

    int c = capacity(&buf1);
    printf("capacity of buf1 = %d\n",c);

    int a = size(&buf2);
    printf("size of buf2 = %d\n",a);

    clear(&buf1);
    a = size(&buf1);
    printf("size of buf1 after clearing = %d\n",a);
    
    return 0;
}