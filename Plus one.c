#include <stdint.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 100 * 9 = 900 -> 16 bits = 2 bytes
// 100 -> 8 bits = 1 byte


bool nueve(int* digits, int digitsSize){
    bool status = false;
    for(int i = 0; i < digitsSize; i++){
        if(digits[i] != 9){
            status = false;
            return false;
        }else{
            status = true;
        }
    }
    return status;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int *arr;
    int c;
    bool bandera;
    int acarreo;
    int n_datos;
    
    bandera = true; 
    c = digitsSize;
    acarreo = 1;
    n_datos = 0; 
    
    arr = calloc(digitsSize, sizeof(int)); //arr es un arreglo de 1 elemento con valor de 0 arr = [0];
    if (arr == NULL)  printf("Ha ocurrido un error al momento de reservar el espacio de memoria");
    
    
    while(c > 0){
        c--;
       
        if(nueve(digits,digitsSize) && bandera){
            arr = realloc(arr,(digitsSize+1)*sizeof(int));
            c++;
        
            for(int i = c; i>=0; i--){
                arr[c] = 0;
                n_datos++;
            }
            *returnSize = n_datos;
            arr[0] = 1;    
            return arr; 
            
        }else if(bandera){
            
            for(int i = c; i >= 0; i--){
                arr[i] = digits[i] + acarreo;
                if (arr[i] == 10){
                    arr[i] = 0;
                    acarreo = 1;
                }else{
                    arr[i] = digits[i]+acarreo;  
                    acarreo = 0;
                }
                
                n_datos++;
            }
            bandera = false;
            *returnSize = n_datos;
            return arr; 
            
        }
    }
    return arr; 
    free(arr);
    
}
