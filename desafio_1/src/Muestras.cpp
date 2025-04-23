#include <QImage>
#include <iostream>
#include "funciones.h"

using namespace std;


unsigned char* cargarImagen(QString nombreArchivo, int &ancho, int &alto) {
 
    QImage imagen(nombreArchivo);

   
    if (imagen.isNull()) {
        cout << "Error: no se pudo cargar la imagen." << endl;
        return nullptr;
    }

    
    imagen = imagen.convertToFormat(QImage::Format_RGB888);

   
    ancho = imagen.width();
    alto = imagen.height();


    int totalBytes = ancho * alto * 3;

    
    unsigned char* datos = new unsigned char[totalBytes];

 
    for (int y = 0; y < alto; y = y + 1) {
        memcpy(datos + y * ancho * 3, imagen.scanLine(y), ancho * 3);
    }

    return datos;
}


bool exportarImagen(unsigned char* pixelData, int ancho, int alto, QString archivoSalida) {
  
    QImage salida(ancho, alto, QImage::Format_RGB888);


    for (int y = 0; y < alto; y = y + 1) {
        memcpy(salida.scanLine(y), pixelData + y * ancho * 3, ancho * 3);
    }

    // Guardamos la imagen como archivo BMP
    return salida.save(archivoSalida, "BMP");
}
