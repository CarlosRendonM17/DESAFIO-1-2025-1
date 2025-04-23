#include <QString>
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
   
    QString ID = "data/ID.bmp";

   
    QString IM = "data/IM.bmp";

   
    const char* M1 = "data/M1.txt";

 
    QString ordenes[] = {"xor-rotar", "rotar-xor", "desplazar-xor"};

    bool encontrado = false; 
    
   
    for (const QString& orden : ordenes) {
        if (probarOrdenTransformaciones(ID, IM, M1, orden)) {
            cout << "Transformación correcta con orden: " << orden.toStdString() << endl;
            encontrado = true;
            break;
        }
    }

   
    if (encontrado == false) {
        cout << "Ninguna combinación fue válida." << endl;
    }

    return 0;
}
