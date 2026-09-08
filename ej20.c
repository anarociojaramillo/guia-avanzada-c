#include <stdio.h>
#include <stdint.h>

#define VIDEO_COLS 80
#define VIDEO_FILS 50

typedef struct ca_s{
    uint8_t c; //caracter
    uint8_t a; //atributos
} ca;
void screen_draw_layout(void) {
    //VIDEO es un puntero a la direccion de memoria del buffer de video
    ca(*p)[VIDEO_COLS] = (ca(*)[VIDEO_COLS]) VIDEO;  
    // define un puntero p a un array de 80 elementos de tipo ca
    //luego, castea la "constante" VIDEO
    //hacemos que p GUARDE la direccion que guarda VIDEO

    uint32_t f,c;
    for(f = 0; f < VIDEO_FILS; f++) {
        for(c = 0; c < VIDEO_COLS; c++) {
            p[f][c].c = ' ';
            p[f][c].a = 0x10; 
        }
    }
}