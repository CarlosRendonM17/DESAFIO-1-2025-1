#include "funciones.h"


void aplicarXOR(unsigned char* data, unsigned char* mascara, int size) {
    for (int i = 0; i < size; i = i + 1) {
        data[i] = data[i] ^ mascara[i];
    }
}


void rotarDerecha(unsigned char* data, int size, int bits) {
    for (int i = 0; i < size; i = i + 1) {
        data[i] = (data[i] >> bits) | (data[i] << (8 - bits));
    }
}


void desplazar(unsigned char* data, int size, int offset) {
  
    for (int i = size - 1; i >= offset; i = i - 1) {
        data[i] = data[i - offset];
    }

 
    for (int i = 0; i < offset; i = i + 1) {
        data[i] = 0;
    }
}
