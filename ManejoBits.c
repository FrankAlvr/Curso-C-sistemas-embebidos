#include <stdint.h>
#include <stdio.h>

void escribir_byte_alto(volatile uint32_t *reg, uint8_t valor) {
    *reg &= ~((uint32_t)0xFF << 8);
    *reg |= ((uint32_t)valor << 8);
}

int main(void) {
    uint32_t registro = 0xFFFFFFFF; // todos los bits en 1

    printf("Antes:  0x%08X\n", registro);
    escribir_byte_alto(&registro, 0xAB);
    printf("Despues: 0x%08X\n", registro);

    return 0;
}