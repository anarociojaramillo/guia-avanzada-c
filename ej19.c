#include <stdio.h>

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    //p apunta al int en la fila 0 columna 0
    int *p = &matrix[0][0]; //es literalmente el valor

    //¿que es reshape?
    int (*reshape)[2] = (int (*)[2]) p;
    //reshape es un puntero que apunta a un array de 2 enteros
    
    printf("%d\n", p[3]); // ¿que imprime esta linea?


    printf("%d\n", reshape[1][1]); // ¿que imprime esta linea?

}