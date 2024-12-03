#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 5  

typedef struct {
    int *buffer;
    int head;
    int tail;
    int size;
} CircularBuffer;

void initBuffer(CircularBuffer *cb, int size) {  //buffer is initialized 
    cb->buffer = (int *)malloc(size * sizeof(int));
    cb->head = 0;
    cb->tail = 0;
    cb->size = size;
}

int isFull(CircularBuffer *cb) {
    return (cb->head + 1) % cb->size == cb->tail;
}
int isEmpty(CircularBuffer *cb) {
    return cb->head == cb->tail;
}

void writeBuffer(CircularBuffer *cb, int data) {   
    if (isFull(cb)) {                               // checks if buffer is full
        printf("Buffer is full. Overwriting data.\n");
        cb->tail = (cb->tail + 1) % cb->size;  
    }
    cb->buffer[cb->head] = data;                      // writes data
    cb->head = (cb->head + 1) % cb->size;
}

int readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer is empty.\n");
        return -1;
    }
    int data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->size;
    return data;
}
void freeBuffer(CircularBuffer *cb) {
    free(cb->buffer);
}
int main() {
    CircularBuffer cb;              // CircularBuffer object cb is created
    initBuffer(&cb, BUFFER_SIZE);

    writeBuffer(&cb, 10);           //write data to buffer
    writeBuffer(&cb, 20);
    writeBuffer(&cb, 30);

    printf("Read: %d\n", readBuffer(&cb));
    printf("Read: %d\n", readBuffer(&cb));

    writeBuffer(&cb, 40);
    writeBuffer(&cb, 50);
    writeBuffer(&cb, 60); 
    
    while (!isEmpty(&cb)) {
        printf("Read: %d\n", readBuffer(&cb));
    }
    freeBuffer(&cb);
    return 0;
}
