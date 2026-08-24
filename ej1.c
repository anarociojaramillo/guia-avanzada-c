#include <stdio.h>


/*defino la estructura */
typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;


int main() {
/*inicialio el array*/

    monstruo_t monstruos[] = {
        {"monstruo1", 9, 3.5, 6.7},
        {"monstruo2", 4, 9.6, 4.2},
        {"monstruo3", 2, 4.5, 8.9} 
    };


/*muestro por pantalla el nombre y vida de cada uno*/
    printf("Nombre monstruo 1: %s. Vida monstruo 1: %d\n", monstruos[0].nombre, monstruos[0].vida );
    printf("Nombre monstruo 2: %s. Vida monstruo 2: %d\n", monstruos[1].nombre, monstruos[1].vida );
    printf("Nombre monstruo 3: %s. Vida monstruo 3: %d\n", monstruos[2].nombre, monstruos[2].vida );


    return 0;

}
