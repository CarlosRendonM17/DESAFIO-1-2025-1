#include "funciones.h"

// Aplica XOR entre los datos y la máscara. Ambos deben tener el mismo tamaño.
// Es como "desencriptar" la imagen usando otra imagen como clave.
void aplicarXOR(unsigned char* data, unsigned char* mascara, int size) {
    for (int i = 0; i < size; i = i + 1) {
        data[i] = data[i] ^ mascara[i];
    }
}

// Rota los bits de cada byte hacia la derecha (como un "corrido circular" de bits)
// Ejemplo: si bits = 3 → 10010101 → se vuelve 10110010
void rotarDerecha(unsigned char* data, int size, int bits) {
    for (int i = 0; i < size; i = i + 1) {
        data[i] = (data[i] >> bits) | (data[i] << (8 - bits));
    }
}

// Desplaza los bytes hacia la derecha (se recorre el arreglo y se llena con ceros al inicio)
// Ejemplo: si offset = 5 → los primeros 5 bytes quedan en 0, el resto se corre
void desplazar(unsigned char* data, int size, int offset) {
    // Recorremos de atrás hacia adelante para no pisar los datos al moverlos
    for (int i = size - 1; i >= offset; i = i - 1) {
        data[i] = data[i - offset];
    }

    // Los primeros 'offset' valores se rellenan con 0
    for (int i = 0; i < offset; i = i + 1) {
        data[i] = 0;
    }
}
