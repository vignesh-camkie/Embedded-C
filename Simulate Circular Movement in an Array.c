#include<stdio.h>
#define BUFFER_SIZE 5
int main(){
    int buffer[BUFFER_SIZE];
    int head = 0;
    for (int i=0;i<7;i++){
        buffer[head]=i+1;
        printf("Value %d added at position %d \n", buffer[head],head);
        head = (head+1)%BUFFER_SIZE;
    }
    return 0;
} 