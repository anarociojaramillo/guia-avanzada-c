#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nombre;
    int edad;
} persona_t;

persona_t* crearPersona(char* nombre, int edad) {
    persona_t *p = malloc(sizeof(persona_t));
    if (p == NULL) {
        return NULL;
    }

    p->nombre = malloc(strlen(nombre) + 1); // el +1 es para que me entre el '/0'
    if (p->nombre == NULL) {
        free(p); //si es que falla, tengo que liberar la memoria que me pedi arriba en el primer malloc pq al final no la voy a usar si fallo
        return NULL;
    }
    strcpy(p->nombre, nombre); // malloc solo reserva espacio en blanco pero no escribe nada adentro
    //strcpy es la q hace realmente la copia, va leyendo caracter por caracter y va aescribiendo
    //cada letra dentro de la memoria reservada hasta copiar tmb el byte nulo (/0)

    p->edad = edad;
    return p;

}

int main() {
    persona_t *result = crearPersona("Rocio", 22);
    if(result == NULL) {
        return 1;
    }
    printf("%s\n", result->nombre);
    printf("%d\n", result->edad);

    free(result);
    return 0;
}