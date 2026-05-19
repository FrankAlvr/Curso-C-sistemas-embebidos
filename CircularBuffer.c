#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int*    arr;        // Puntero al arreglo donde se almacenan los datos
    int     head;       //Índice donde se lee (donde inicia el dato más antiguo)
    int     tail;       //Índice donde se escribe el siguiente dato
    uint8_t cap;        //Cuantos elementos caben
    uint8_t size;       //Cantidad de elementos actuales en el buffer

}Buffer;

void Buffer_init(Buffer* Buffer1, int cap){
    int* aux; 
    aux = calloc(cap,sizeof(int));
    if(aux == NULL) return;
    Buffer1 -> arr  = aux;  // Puntero al arreglo donde se almacenan
    Buffer1 -> head = 0;    // Índice 0 donde inicia el dato más antiguo 
    Buffer1 -> tail = 0;    // Índice 0 donde se escribira el siguiente dato
    Buffer1 -> cap = cap;   // la capaciadad esta definida al inializar la función
    Buffer1 -> size = 0;    // tenemos 0 elementos actuales en el buffer
}
//Enqueue -> Poner en cola 
void Buffer_enqueue(Buffer* Buffer1, int elemento){
    if(Buffer1 -> size < Buffer1 -> cap){
        Buffer1 -> arr[Buffer1 -> tail] = elemento;
        Buffer1 -> tail = (Buffer1 -> tail + 1) % (Buffer1->cap);
        Buffer1 -> size++;
    }
}
//Dequeue -> Sacar de cola
int Buffer_dequeue(Buffer* Buffer1){
    if(Buffer1 -> size > 0){
        Buffer1 -> size--;
        int aux;
        aux = Buffer1 -> arr[Buffer1 -> head];
        Buffer1->head = (Buffer1->head+1) % Buffer1->cap;
        return aux;
    }
    return -1;
}



int Buffer_print(Buffer* Buffer1){
    if(Buffer1->size > 0){
        for(int i = 0; i < Buffer1->size; i++){
            int indice = (Buffer1->head + i) % Buffer1->cap;
            printf("\n%d", Buffer1->arr[indice]);
        }
        return 0;
    }
    return -1;
}

int main(){
    Buffer Buffer1;
    Buffer_init(&Buffer1,5);
    Buffer_enqueue(&Buffer1,1);
    Buffer_enqueue(&Buffer1,2);
    Buffer_enqueue(&Buffer1,3);
    Buffer_enqueue(&Buffer1,4);
    Buffer_enqueue(&Buffer1,5);
    Buffer_print(&Buffer1);
    Buffer_dequeue(&Buffer1);
    Buffer_dequeue(&Buffer1);
    Buffer_print(&Buffer1);
    return 0;
}