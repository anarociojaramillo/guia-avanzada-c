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

/*estructuras de la lista*/
typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;

/*funciones dummy para fat32*/
fat32_t* new_fat32() {
    fat32_t* p = malloc(sizeof(fat32_t));
    if (p != NULL) 
        *p = 100;
    return p;
}

fat32_t* copy_fat32(fat32_t* file) {
    if (file == NULL)
        return NULL;
    fat32_t* copia = malloc(sizeof(fat32_t));
    if(copia != NULL)
        *copia = *file;
    return copia;
}

void rm_fat32(fat32_t* file) {
    if (file != NULL) 
        free(file);
}



/*implementacion de la lista*/
list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    if (l == NULL) return NULL;
    l->type = t;
    l->size = 0;
    l->first = NULL;
    return l;
}

void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    if (n == NULL) return;

    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        default:
            n->data = NULL;
            break;
    }
    n->next = l->first;
    l->first = n;
    l->size++;
}

void listDelete(list_t* l) {
    node_t* n = l->first;
    while(n) { //= while (n != NULL)
        node_t* tmp = n;
        n = n->next;
        switch(l->type) {
            case TypeFAT32:
                rm_fat32((fat32_t*) tmp->data);
                break;
            default:
                break;
        }
        free(tmp);
    }
    free(l); //borra toda la  lista, nodo por nodo y al final destruye tambien la estructura principal list_t
}


list_t* intercambiar(list_t* l, node_t* nodo1, node_t* nodo2) {
    if (l == NULL || l->first == NULL || l->first->next == NULL) return l;
    if (nodo1 == NULL || nodo2 == NULL || nodo1 == nodo2) return l;

    //buscar los nodos previos a nodo1 y nodo2
    node_t *prev1 = NULL, *prev2 = NULL;
    node_t *actual = l->first;

    // actual = direccion de memoria
    // *actual = desreferenciacion, el * viaja a esa direccion de memoria y accede al contenido/ valor real de la estructura


    while (actual != NULL) {
        if(actual->next == nodo1)
            prev1 = actual;
        if(actual->next == nodo2)
            prev2 = actual;
        
        actual = actual->next; // para seguir iterando
    }

    // ajustar el puntero del anterior hacia el nuevo nodo


    if (prev1 != NULL) { 
        prev1->next = nodo2; // si había un nodo antes de nodo1, ahora ese nodo previo apunta a nodo2
    } else {
        l->first = nodo2; //nodo1 era el primero
    }

    if (prev2 != NULL) {
        prev2->next = nodo1; //el nodo que estaba antes de nodo2 ahora debe apuntar a nodo1
    } else {
        l->first = nodo1; // nodo2 era el primero
    }

    //intercambiar los punteros de next de ambos

    node_t* temp = nodo1->next;
    nodo1->next = nodo2->next;
    nodo2->next = temp;

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