#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <QString> // Usamos QString porque trabajamos con Qt

// ─── Carga y exportación de imágenes ──────────────────────────────

// Carga una imagen BMP y devuelve sus píxeles (en RGB)
unsigned char* cargarImagen(QString nombreArchivo, int &width, int &height);

// Guarda una imagen BMP a partir de un arreglo de píxeles RGB
bool exportarImagen(unsigned char* pixelData, int width, int height, QString archivoSalida);

// ─── Transformaciones de la imagen ───────────────────────────────

// Aplica XOR entre dos arreglos de la misma longitud
void aplicarXOR(unsigned char* data, unsigned char* mascara, int size);

// Rota los bits de cada byte hacia la derecha
void rotarDerecha(unsigned char* data, int size, int bits);

// Desplaza los bytes hacia la derecha (rellena con ceros al inicio)
void desplazar(unsigned char* data, int size, int offset);

// ─── Lectura de la máscara (archivo .txt) ────────────────────────

// Lee la máscara desde el archivo (semilla + valores RGB esperados)
unsigned int* leerMascara(const char* nombreArchivo, int &seed, int &n_pixels);

// ─── Verificación y reconstrucción ───────────────────────────────

// Compara una imagen con la máscara para verificar si coincide
bool verificarEnmascaramiento(unsigned char* imagen, int width, int height, const char* archivoMascara);

// Prueba una combinación de transformaciones y verifica si es correcta
bool probarOrdenTransformaciones(QString imagenBase, QString imagenXOR, const char* archivoMascara, QString orden);

#endif
