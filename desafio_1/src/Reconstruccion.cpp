#include <iostream>
#include <QString>
#include <cstring>
#include "funciones.h"

using namespace std;

// Esta función verifica si una imagen coincide con los datos de la máscara (colores esperados)
bool verificarEnmascaramiento(unsigned char* imagen, int ancho, int alto, const char* archivoMascara) {
    int seed = 0;
    int totalPixeles = 0;

    // Leemos la máscara: contiene los colores RGB y el punto donde empiezan
    unsigned int* dataRGB = leerMascara(archivoMascara, seed, totalPixeles);
    if (!dataRGB) return false;

    // La comparación empieza desde la semilla
    int inicio = seed;
    bool coincide = true;

    // Recorremos cada valor RGB de la máscara y lo comparamos con los de la imagen
    for (int k = 0; k < totalPixeles * 3; k = k + 1) {
        int posicion = inicio + k;
        if (posicion >= ancho * alto * 3 || imagen[posicion] != dataRGB[k]) {
            coincide = false;
            break;
        }
    }

    // Liberamos memoria
    delete[] dataRGB;
    return coincide;
}

// Esta función aplica una combinación de transformaciones a la imagen base
// y verifica si coincide con la máscara. Si sí, la guarda como "Reconstruida.bmp"
bool probarOrdenTransformaciones(QString imagenBase, QString imagenXOR, const char* archivoMascara, QString orden) {
    int ancho, alto;

    // Cargamos las dos imágenes: la base distorsionada y la imagen XOR (clave)
    unsigned char* base = cargarImagen(imagenBase, ancho, alto);
    unsigned char* xorImg = cargarImagen(imagenXOR, ancho, alto);
    if (!base || !xorImg) return false;

    // Creamos una copia que vamos a modificar
    int totalBytes = ancho * alto * 3;
    unsigned char* copia = new unsigned char[totalBytes];
    memcpy(copia, base, totalBytes);

    // Aplicamos las transformaciones según el orden que se esté probando
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

    // Verificamos si la imagen transformada coincide con la máscara
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
