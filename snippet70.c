#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



typedef struct nodo_s {
// hay que definir struct nodo_s* ac´a porque el tipo nodo_t
// no est´a declarado.
struct nodo_s* siguiente;
int valor;
} nodo_t;
typedef struct lista_s {
nodo_t* cabeza;
} lista_t;

lista_t* crear_lista_vacia() {
lista_t* lista_vacia = malloc(sizeof(lista_t));
lista_vacia->cabeza = NULL; // El operador x->y es equivalente a (*x).y
return lista_vacia;
}
nodo_t* crear_nuevo_nodo(int valor) {
nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
nuevo_nodo->siguiente = NULL;
nuevo_nodo->valor = valor;
return nuevo_nodo;
}

void insertar_al_final(lista_t* lista, int valor) {
nodo_t* actual = lista->cabeza;
nodo_t* a_insertar = crear_nuevo_nodo(valor);
// Caso lista vacia.
// Intentar desreferenciar el puntero NULL causa un
// Segmentation Fault (SIGSEGV).
if (actual == NULL) {
lista->cabeza = a_insertar;
return;
}
while (actual->siguiente != NULL)
actual = actual->siguiente;
actual->siguiente = a_insertar;
}

int eliminar_cabeza(lista_t* lista) {
nodo_t* actual = lista->cabeza;
if (actual == NULL)
return -1;
lista->cabeza = actual->siguiente;
free(actual);
return 0;
}

void eliminar_lista(lista_t* lista) {
nodo_t* actual = lista->cabeza;
while (actual != NULL) {
nodo_t* siguiente = actual->siguiente;
free(actual);
actual = siguiente;
}
free(lista);
}


/*FUNCION CRITERIO */

int criterio(int x){
    if (x % 2 == 0){
        return 1;
    } else {
        return 0;
    }
}

/*FUNCION FILTRAR */

void filter(lista_t* lista, int(*criterio)(int)){
    nodo_t** cabeza_actual= &lista->cabeza;
    while(*cabeza_actual != NULL){
        if(!criterio((*cabeza_actual)->valor)) {
            nodo_t* a_borrar= *cabeza_actual;
            *cabeza_actual = (*cabeza_actual)->siguiente;
            free(a_borrar);
        } else{
            cabeza_actual = &(*cabeza_actual)->siguiente;
        }
    }
}


int main() {
lista_t* mi_lista = crear_lista_vacia();
insertar_al_final(mi_lista, 1);
insertar_al_final(mi_lista, 2);
insertar_al_final(mi_lista, 3);
insertar_al_final(mi_lista, 4);
// En este momento mi_lista = [1,2,3,4]
filter(mi_lista, &criterio);
// En este momento mi_lista = [2,4]

nodo_t* actual = mi_lista->cabeza;
    while(actual != NULL) {
        printf("actual: %d\n", actual->valor);
        actual = actual->siguiente;
    }

return 0;
}
