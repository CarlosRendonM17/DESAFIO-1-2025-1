#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <QString> 

unsigned char* cargarImagen(QString nombreArchivo, int &width, int &height);


bool exportarImagen(unsigned char* pixelData, int width, int height, QString archivoSalida);


void aplicarXOR(unsigned char* data, unsigned char* mascara, int size);


void rotarDerecha(unsigned char* data, int size, int bits);


void desplazar(unsigned char* data, int size, int offset);


unsigned int* leerMascara(const char* nombreArchivo, int &seed, int &n_pixels);

bool verificarEnmascaramiento(unsigned char* imagen, int width, int height, const char* archivoMascara);


bool probarOrdenTransformaciones(QString imagenBase, QString imagenXOR, const char* archivoMascara, QString orden);

#endif
