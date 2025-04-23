#include <QImage>
#include <iostream>
#include "funciones.h"

using namespace std;

// Función para cargar una imagen BMP y guardar los píxeles como arreglo RGB
unsigned char* cargarImagen(QString nombreArchivo, int &ancho, int &alto) {
    // Usamos QImage para abrir la imagen
    QImage imagen(nombreArchivo);

    // Si no se pudo abrir, mostramos un error
    if (imagen.isNull()) {
        cout << "Error: no se pudo cargar la imagen." << endl;
        return nullptr;
    }

    // Convertimos la imagen a formato RGB888 (o sea, 3 bytes por píxel: R, G, B)
    imagen = imagen.convertToFormat(QImage::Format_RGB888);

    // Guardamos el tamaño de la imagen
    ancho = imagen.width();
    alto = imagen.height();

    // Calculamos el total de bytes que vamos a necesitar
    int totalBytes = ancho * alto * 3;

    // Creamos el arreglo donde van a quedar todos los píxeles
    unsigned char* datos = new unsigned char[totalBytes];

    // Copiamos los píxeles línea por línea desde la imagen hacia nuestro arreglo
    for (int y = 0; y < alto; y = y + 1) {
        memcpy(datos + y * ancho * 3, imagen.scanLine(y), ancho * 3);
    }

    return datos;
}

// Función para guardar una imagen BMP desde un arreglo de píxeles RGB
bool exportarImagen(unsigned char* pixelData, int ancho, int alto, QString archivoSalida) {
    // Creamos una imagen vacía con las dimensiones y el formato correcto
    QImage salida(ancho, alto, QImage::Format_RGB888);

    // Copiamos los datos desde el arreglo hacia la imagen
    for (int y = 0; y < alto; y = y + 1) {
        memcpy(salida.scanLine(y), pixelData + y * ancho * 3, ancho * 3);
    }

    // Guardamos la imagen como archivo BMP
    return salida.save(archivoSalida, "BMP");
}
