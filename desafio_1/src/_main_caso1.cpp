
QString IM = "data/Caso1/I_M.bmp";


const char* M1 = "data/Caso1/M1.txt";


QString ordenes[] = {"xor-rotar", "rotar-xor", "desplazar-xor"};


bool encontrado = false;


for (int i = 0; i < 3 && encontrado == false; i = i + 1) {
    QString orden = ordenes[i];

    if (probarOrdenTransformaciones(ID, IM, M1, orden)) {
        cout << "Transformación correcta con orden: " << orden.toStdString() << endl;
        encontrado = true;
    }
}


if (encontrado == false) {
    cout << "Ninguna combinación fue válida." << endl;
}

return 0;
