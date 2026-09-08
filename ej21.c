#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*enum y tipos*/
typedef enum e_type {
    TypeFAT32 = 0,
    TypeEXT4 = 1,
    TypeNTFS = 2,
} type_t;

typedef uint32_t fat32_t;

//punteros a funciones

typedef void* (*funcCopy_t)(void*);
typedef void (*funcRm_t)(void*);


/*funciones dummy para fat32*/
fat32_t* new_fat32() {
    fat32_t* p = malloc(sizeof(fat32_t));
    if (p != NULL) 
        *p = 100;
    return p;
}

fat32_t* copy_fat32(void* file) {
    if (file == NULL)
        return NULL;
    fat32_t* copia = malloc(sizeof(fat32_t));
    if(copia != NULL)
        *copia = *(fat32_t*)file;
    return (void*)copia;
}

void rm_fat32(void* file) {
    if (file != NULL) 
        free(file);
}

/*funciones selectoras*/

funcCopy_t getCopyFunction(type_t t) {
    switch(t) {
        case TypeFAT32: return (funcCopy_t) copy_fat32;
        default: return NULL;
    }
}

funcRm_t getRmFunction(type_t t) {
    switch(t) {
        case TypeFAT32: return rm_fat32;
        default: return NULL;
    }
}

/*estructuras de la lista*/
typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    node_t* last;
} list_t;


/*implementacion de la lista*/
list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    if (l == NULL) return NULL;
    l->type = t;
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void listAddFirst(list_t* l, void* data) {
    if (l == NULL) return;

    node_t* n = malloc(sizeof(node_t));
    if (n == NULL) return;

    funcCopy_t copyFunc = getCopyFunction(l->type);
    n->data = copyFunc ? copyFunc(data) : NULL;

    n->prev = NULL; //como entra primero, no tiene a nadie antes
    n->next = l->first; //su siguiente es el que antes era el primero, si la lista estaba vacia y l->first es null, entonces estamos diciendo que el siguiente es null, lo cual es lo que queremos! :D
    if (l->first != NULL) { 
        l->first->prev = n;
    } else {
        l->last = n; //si la lista estaba vacia, n tambien es el ultimo
    }
    l->first = n;
    l->size++;
}

void listDelete(list_t* l) {
    if (l == NULL) return;
    node_t* n = l->first;
    funcRm_t rmFunc = getRmFunction(l->type);

    while(n) { //= while (n != NULL)
        node_t* tmp = n;
        n = n->next;
        if (rmFunc != NULL) {
            rmFunc(tmp->data);
        }
        free(tmp);
    }
    free(l); //borra toda la  lista, nodo por nodo y al final destruye tambien la estructura principal list_t
}


list_t* intercambiar(list_t* l, node_t* nodo1, node_t* nodo2) {
    if (l == NULL || l->first == NULL || l->first->next == NULL) return l;
    if (nodo1 == NULL || nodo2 == NULL || nodo1 == nodo2) return l;

// Si nodo2 está antes que nodo1, los damos vuelta para tratarlos siempre en orden
    if (nodo1->prev == nodo2) {
        node_t* t = nodo1;
        nodo1 = nodo2;
        nodo2 = t;
    }

    node_t* prev1 = nodo1->prev;
    node_t* next1 = nodo1->next;
    node_t* prev2 = nodo2->prev;
    node_t* next2 = nodo2->next;

    // Son contiguos: nodo1 -> nodo2
    if (next1 == nodo2) {
        if (prev1) prev1->next = nodo2; else l->first = nodo2;
        if (next2) next2->prev = nodo1; else l->last = nodo1;

        nodo2->prev = prev1;
        nodo2->next = nodo1;
        nodo1->prev = nodo2;
        nodo1->next = next2;
    } else { // No son contiguos
        if (prev1) prev1->next = nodo2; else l->first = nodo2;
        if (next1) next1->prev = nodo2;
        if (prev2) prev2->next = nodo1;
        if (next2) next2->prev = nodo1; else l->last = nodo1;

        nodo1->prev = prev2;
        nodo1->next = next2;
        nodo2->prev = prev1;
        nodo2->next = next1;
    }

    return l;
    
}


int main() {
    
    list_t* l = listNew(TypeFAT32);
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    
    listAddFirst(l, f1);
    listAddFirst(l, f2);
    
    listDelete(l);
    
    rm_fat32(f1);
    rm_fat32(f2);
    
    return 0;
}