#include<stdio.h>
#define BUFFER_SIZE 3
int main(){
    int buff[BUFFER_SIZE];
    int count = 0;
    buff[count++] = 1;
    buff[count++] = 2;
    buff[count++] = 3;
    for (int i=0;i<count;i++){
        printf("Data: %d \n",buff[i]);
    }
    return 0;
}