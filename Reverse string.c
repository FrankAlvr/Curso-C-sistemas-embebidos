#include <stdio.h>
#include <stdint.h>
void reverseString(char* s, int sSize) {
    
    char left;
    int i = 0;
    
    while(i < sSize/2){
        left = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = left;
        i++;
    }
    
}
