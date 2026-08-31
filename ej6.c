#include <stdio.h>
#include <stdint.h>

int main() {
    int8_t memoria [2] = {(uint8_t) 256, -128};
    
    uint8_t *x = (uint8_t*) &memoria[0];
    int8_t *y = (int8_t*) &memoria[1];


    printf("Direccion de x: %p \n Valor: %d \n", (void*) x, *x); 
    /*printf con el especificador %p exige formalmente recibir un puntero genérico
    void*.
    Si no lo casteas, algunos compiladores lanzan advertencias (warnings*/
    printf("Direccion de y: %p \n Valor: %d \n", (void*) y, *y);

    /*%p para imprimir punteros / direcciones de memoria en formato hexadecimal*/
}
