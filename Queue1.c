#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int*    arr;        //Dirección donde inicia
    int     head;       //índice donde inicia
    int     tail;       //índice donde termina
    uint8_t cap;        //Cuantos caben
    uint8_t location;   //Cuantos elementos hay
}Queue;

void Queue_init(Queue* Queue1, int cap){
    int* aux;
    aux = calloc(cap, sizeof(int));
    if(aux == NULL) return;
    Queue1 -> arr       = aux; 
    Queue1 -> head      = 0;
    Queue1 -> tail      = 0;
    Queue1 -> cap       = cap;
    Queue1 -> location  = 0;
    
}

void Enqueue(Queue* Queue1, int elemento){
    if (Queue1 -> location < Queue1 -> cap){
        Queue1 -> arr[Queue1 -> tail] = elemento;
        Queue1 -> tail++;
        Queue1 -> location++;
    }
}

int Dequeue(Queue* Queue1){
    if(Queue1 -> location > 0){
        Queue1 -> location--;
        return Queue1 -> arr[Queue1 -> head++];
    }
    return -1;
}

int Queue_print(Queue* Queue1){
    if(Queue1 -> location > 0){
        for(int i = Queue1 -> head; i < Queue1 -> tail; i++){
            printf("\n%d",Queue1->arr[i]);
        }
        return 0; 
    }
    return -1;
}

int main(){
    Queue Queue1;
    Queue_init(&Queue1,5);
    Enqueue(&Queue1,1);
    Enqueue(&Queue1,2);
    Enqueue(&Queue1,3);
    Enqueue(&Queue1,4);
    Enqueue(&Queue1,5);
    Queue_print(&Queue1);
    Dequeue(&Queue1);
    Dequeue(&Queue1);
    Queue_print(&Queue1);
}