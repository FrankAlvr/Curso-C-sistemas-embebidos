#include <stdlib.h>
#incxlude <stdint.h>  

//Función que te ayuda a acomodar los datos
int ordenar(const void *a, const void *b){
    
    uint16_t vala = *(const uint16_t*)a;
    uint16_t valb = *(const uint16_t*)b;
    
    if (vala > valb) return 1;// arg1 > arg2
    if (vala < valb) return -1;//arg1 < arg2
    
    return 0;//arg1 = arg2
}


//Función que me dice si estan ordenados
bool ordenada(int* nums, int numsSize){
    for(uint16_t i = 0; i < numsSize-1; i = i+2){
        if(nums[i]>nums[i+1]){
      //      printf("false");  
            return false;
        }  
    }
    //printf("true");
    return true;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int *arr;
    int a = 0;
    int j = 0 

    // El tamaño máximo de la intersección es el tamaño del arreglo más pequeño
    int minSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    arr = calloc(minSize, sizeof(int));
    if (arr == NULL)  printf("Ha ocurrido un error al momento de reservar el espacio de memoria");
    
    if (~ordenada(nums1, nums1Size)){
        qsort(nums1,nums1Size,sizeof(int),ordenar);
    }
    if (~ordenada(nums2, nums2Size)){
        qsort(nums2,nums2Size,sizeof(int),ordenar);
    }
    
    while((i < nums1Size) && (j < nums2Size)){
        if(nums1[i] == nums2[j]){
            arr[a] = nums1[i];
            a++;
            i++;
            j++;  
        }else if(nums1[i] < nums2[j]){
            i++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }
    }
    
    *returnSize = a;
    return arr;
    free(arr);
    
}
