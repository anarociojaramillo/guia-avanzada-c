#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum{
    MENTA,
    DDL,
    OREO,
    LIMON
} gustoDeHelado_t;

char* gustoDeHelado[4] = {"MENTA", "DDL", "OREO", "LIMON"};

typedef struct{
    uint32_t precio;
    gustoDeHelado_t gusto;
} helado_t;

helado_t heladoDDL = {.precio = 5, .gusto= DDL};

typedef struct{
    char nombre[5];
    uint8_t habilitado; //bool
    int saldo;
    int gustoDeHeladoFavorito;
} usuario_t;

void habilitarUsuario(usuario_t *usuario){
    usuario->habilitado = 1;
    for (int i = 0; i < 5; i++){
        usuario->nombre[i] = '\0';
    }
    usuario->saldo = 0;
}

void aumentarSaldo(int *saldoDeUsuario, int cantidad){
    *saldoDeUsuario += cantidad; //El * es el operador de desreferenciación. Significa
    //"andá a la dirección de memoria que tengo anotada y escribí/leé en ese casillero real".
}

void comprarHelado(usuario_t *usuario, helado_t* *helado){
    if(usuario->saldo >= 5){
        usuario->saldo -= 5;
        *helado = &heladoDDL; //andá a la dirección de memoria que tengo anotada en helado y
        // escribí en ese casillero real la direccion de memoria exacta donde esta heladoDDL
        //la función modifica la variable del main para que deje de apuntar a NULL y pase a apuntar a heladoDDL
        printf("Helado comprado con exito\n");
    }else{
        printf("El usuario no tiene saldo suficiente\n");
    }
}

int main(void){
    usuario_t *nuevoUsuario = malloc(sizeof(usuario_t));
    habilitarUsuario(nuevoUsuario);

    if(nuevoUsuario->habilitado){
        printf("usuario habilitado con exito\n");
        aumentarSaldo(&(nuevoUsuario->saldo), 10); //& (address-of) extrae la dirección de 
        //memoria exacta del casillero donde está guardado ese número.

        helado_t* helado= NULL;
        comprarHelado(nuevoUsuario, &helado);
        nuevoUsuario->gustoDeHeladoFavorito = helado->gusto;

        printf("usuario creado con exito\n");
        printf("su saldo es de %d pesos y su gusto favorito es %s.\n", 
        nuevoUsuario->saldo, 
        gustoDeHelado[nuevoUsuario->gustoDeHeladoFavorito]);
    } else{
        printf("error al habilitar usuario %d\n", nuevoUsuario->habilitado);
    }

    free(nuevoUsuario);
    return 0;
}


