
archivo >> seed;


int r, g, b;
n_pixels = 0;
while (archivo >> r >> g >> b) {
    n_pixels = n_pixels + 1;
}
archivo.close();


archivo.open(nombreArchivo);
if (!archivo.is_open()) {
    cout << "Error al reabrir el archivo de máscara." << endl;
    return nullptr;
}


archivo >> seed;


unsigned int* data = new unsigned int[n_pixels * 3];


for (int i = 0; i < n_pixels * 3; i = i + 3) {
    archivo >> r >> g >> b;
    data[i] = r;
    data[i + 1] = g;
    data[i + 2] = b;
}

archivo.close();
return data;
