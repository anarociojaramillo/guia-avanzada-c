#include <stdio.h>

void Mayusculas(char palabra[] ) { /*pongo void pq no retorno nada, solo lo modifique en la memoria*/
    for (int i = 0; palabra[i] != '\0' ; i ++) {
        /*solo modifico si es minuscula*/
        if (palabra[i] >= 'a' && palabra[i] <= 'z') {
            palabra[i] = palabra[i] + ('A' - 'a');
            /*la diferencia entre una mayuscula y minuscula es siempre 32 posiciones*/
        }
    }
}


int main() {
    char palabra[] = "Hola mundo!";


    printf("palabra al inicio: %s \n", palabra);

    Mayusculas(palabra);

    printf("palabra en mayusculas: %s \n", palabra);

    return 0;
}