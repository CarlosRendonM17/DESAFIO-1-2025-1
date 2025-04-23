#include <iostream>
#include <QString>
#include <cstring>
#include "funciones.h"

using namespace std;


bool verificarEnmascaramiento(unsigned char* imagen, int ancho, int alto, const char* archivoMascara) {
    int seed = 0;
    int totalPixeles = 0;

  
    unsigned int* dataRGB = leerMascara(archivoMascara, seed, totalPixeles);
    if (!dataRGB) return false;

   
    int inicio = seed;
    bool coincide = true;

   
    for (int k = 0; k < totalPixeles * 3; k = k + 1) {
        int posicion = inicio + k;
        if (posicion >= ancho * alto * 3 || imagen[posicion] != dataRGB[k]) {
            coincide = false;
            break;
        }
    }

    
    delete[] dataRGB;
    return coincide;
}


bool probarOrdenTransformaciones(QString imagenBase, QString imagenXOR, const char* archivoMascara, QString orden) {
    int ancho, alto;

 
    unsigned char* base = cargarImagen(imagenBase, ancho, alto);
    unsigned char* xorImg = cargarImagen(imagenXOR, ancho, alto);
    if (!base || !xorImg) return false;

   
    int totalBytes = ancho * alto * 3;
    unsigned char* copia = new unsigned char[totalBytes];
    memcpy(copia, base, totalBytes);

 
    if (orden == "xor-rotar") {
        aplicarXOR(copia, xorImg, totalBytes);
        rotarDerecha(copia, totalBytes, 3);
    } else if (orden == "rotar-xor") {
        rotarDerecha(copia, totalBytes, 3);
        aplicarXOR(copia, xorImg, totalBytes);
    } else if (orden == "desplazar-xor") {
        desplazar(copia, totalBytes, 5);
        aplicarXOR(copia, xorImg, totalBytes);
    }

 
    bool exito = verificarEnmascaramiento(copia, ancho, alto, archivoMascara);

    if (exito) {
        cout << "Éxito con orden: " << orden.toStdString() << endl;
        exportarImagen(copia, ancho, alto, "Reconstruida.bmp");
    }

    // Liberamos memoria
    delete[] base;
    delete[] xorImg;
    delete[] copia;

    return exito;
}
