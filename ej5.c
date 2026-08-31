#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t *x = (uint8_t*) 0xF0;
    int8_t *y = (int8_t*) 0xF6;

    printf("Direccion de x: %p \n Valor de x: %d \n", (void*) x, *x);
    printf("Direccion de y: %p \n Valor de y: %d \n", (void*) y, *y);

    return 0;
}