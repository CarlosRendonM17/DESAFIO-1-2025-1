#include <QString>
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    
    QString imagenEntrada = "DesafíoI/Caso 2/I_D.bmp";

   
    QString imagenXOR = "DesafíoI/Caso 2/I_M.bmp";

 
    QString ordenes[] = {"xor-rotar", "rotar-xor", "desplazar-xor"};

    bool encontrado = false; 

  
    for (int i = 0; i <= 6 && encontrado == false; i = i + 1) {
       
        QString archivoMascara = QString("DesafíoI/Caso 2/M%1.txt").arg(i);

     
        for (int j = 0; j < 3 && encontrado == false; j = j + 1) {
            QString orden = ordenes[j];

           
            if (probarOrdenTransformaciones(imagenEntrada, imagenXOR, archivoMascara.toStdString().c_str(), orden)) {
                cout << "Transformación correcta con orden: " << orden.toStdString()
                     << " y máscara: " << archivoMascara.toStdString() << endl;
                encontrado = true;
            }
        }
    }


    if (encontrado == false) {
        cout << "Ninguna combinación fue válida para Caso 2." << endl;
    }

    return 0;
}
