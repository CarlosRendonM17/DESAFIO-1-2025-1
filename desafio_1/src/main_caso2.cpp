#include <QString>
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    // Imagen distorsionada final (la que queremos reconstruir)
    QString imagenEntrada = "DesafíoI/Caso 2/I_D.bmp";

    // Imagen que se usó para aplicar la transformación (XOR)
    QString imagenXOR = "DesafíoI/Caso 2/I_M.bmp";

    // Estas son las combinaciones de transformaciones que vamos a probar
    QString ordenes[] = {"xor-rotar", "rotar-xor", "desplazar-xor"};

    bool encontrado = false;  // Esto nos dice si alguna combinación funcionó

    // Vamos a probar todas las máscaras desde M0.txt hasta M6.txt
    for (int i = 0; i <= 6 && encontrado == false; i = i + 1) {
        // Cargamos el nombre del archivo de máscara actual
        QString archivoMascara = QString("DesafíoI/Caso 2/M%1.txt").arg(i);

        // Probamos con cada orden de transformación posible
        for (int j = 0; j < 3 && encontrado == false; j = j + 1) {
            QString orden = ordenes[j];

            // Esta función aplica la transformación y verifica con la máscara
            if (probarOrdenTransformaciones(imagenEntrada, imagenXOR, archivoMascara.toStdString().c_str(), orden)) {
                cout << "Transformación correcta con orden: " << orden.toStdString()
                     << " y máscara: " << archivoMascara.toStdString() << endl;
                encontrado = true;
            }
        }
    }

    // Si no funcionó ninguna combinación, se avisa por consola
    if (encontrado == false) {
        cout << "Ninguna combinación fue válida para Caso 2." << endl;
    }

    return 0;
}
