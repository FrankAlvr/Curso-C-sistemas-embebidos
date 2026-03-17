#include <math.h>
int reverse(int x){
    
    int64_t invertido = 0;
    int a = 0;

    while (x != 0) {
        int ultimo_digito = x % 10;
        invertido = (invertido * 10) + ultimo_digito;
        x = x / 10;
    }
    a = x;
    
    if((invertido >= pow(2,31)-1) || (invertido <= -pow(2,31))){
        return 0;
    }
    
    return invertido;
}
