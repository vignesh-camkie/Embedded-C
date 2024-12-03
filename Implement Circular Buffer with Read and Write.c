#include <stdio.h>
#define BUFFER_SIZE 5
int main() {
    int buffer[BUFFER_SIZE];
    int head = 0, tail = 0;  
    int size = 0;         

    for (int i = 1; i <= 7; i++) {
        if (size == BUFFER_SIZE) {
            printf("Buffer is full, overwriting data at position %d\n", head);
            tail = (tail + 1) % BUFFER_SIZE; 
        }
        buffer[head] = i;   
        printf("Added: %d at position %d\n", i, head);
        head = (head + 1) % BUFFER_SIZE;
        if (size < BUFFER_SIZE) size++;
    }
    while (size > 0) {
        printf("Read: %d from position %d\n", buffer[tail], tail);
        tail = (tail + 1) % BUFFER_SIZE;
        size--;
    }
    return 0;
}
