#include <QString>
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    // Imagen distorsionada que queremos reconstruir
    QString ID = "data/ID.bmp";

    // Imagen usada para aplicar la transformación (XOR)
    QString IM = "data/IM.bmp";

    // Archivo que contiene la máscara con la semilla y los valores RGB esperados
    const char* M1 = "data/M1.txt";

    // Órdenes de transformación que vamos a probar
    QString ordenes[] = {"xor-rotar", "rotar-xor", "desplazar-xor"};

    bool encontrado = false; // Bandera para saber si alguna combinación fue válida

    // Recorremos las combinaciones posibles
    for (const QString& orden : ordenes) {
        if (probarOrdenTransformaciones(ID, IM, M1, orden)) {
            cout << "Transformación correcta con orden: " << orden.toStdString() << endl;
            encontrado = true;
            break;
        }
    }

    // Si no funcionó ninguna combinación
    if (encontrado == false) {
        cout << "Ninguna combinación fue válida." << endl;
    }

    return 0;
}
