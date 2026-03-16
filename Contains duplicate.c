#include <stdint.h>
#include <stdlib.h>

int comparar(const void *a, const void *b){
    int32_t arg1 = *(const int32_t*)a;
    int32_t arg2 = *(const int32_t*)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comparar);
    for(int i = 0; i < numsSize -1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }
    return false;
}
