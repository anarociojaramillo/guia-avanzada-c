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