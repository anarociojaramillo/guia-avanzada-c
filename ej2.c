#include <stdio.h>

/*defino la estructura */
typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

monstruo_t evolution(monstruo_t m) {
    m.ataque += 10.0;
    m.defensa += 10.0;

    return m;
}

int main(){

    monstruo_t monstruo1 = {"monstruo1", 9, 3.5, 6.7};
    printf("antes del incremento:\n");
    printf("nombre: %s\n", monstruo1.nombre);
    printf("vida: %d\n", monstruo1.vida);
    printf("ataque: %f\n", monstruo1.ataque);
    printf("defensa: %f\n", monstruo1.defensa);

    /*incremento*/
    monstruo1 = evolution(monstruo1);

    printf("despues del incremento:\n");
    printf("nombre: %s\n", monstruo1.nombre);
    printf("vida: %d\n", monstruo1.vida);
    printf("ataque: %f\n", monstruo1.ataque);
    printf("defensa: %f\n", monstruo1.defensa);

    return 0;
}
