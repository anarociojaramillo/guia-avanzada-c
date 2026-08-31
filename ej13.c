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
    p->nombre = malloc(strlen(nombre) + 1);
    if (p->nombre == NULL) {
        free(p);
        return NULL;
    }
    strcpy(p->nombre, nombre);
    p->edad = edad;
    return p;
}

void eliminarPersona(persona_t* p){
    if (p != NULL) {
        free(p->nombre);
        free(p);
    }
}

int main() {
    persona_t *result = crearPersona("Rocio", 22);
    if(result == NULL) {
        return 1;
    }
    eliminarPersona(result);
    return 0;
}