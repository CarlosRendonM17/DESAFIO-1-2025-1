// Leemos la primera línea: la semilla
archivo >> seed;

// Vamos a contar cuántos píxeles (tripletas RGB) tiene el archivo
int r, g, b;
n_pixels = 0;
while (archivo >> r >> g >> b) {
    n_pixels = n_pixels + 1;
}
archivo.close();

// Reabrimos el archivo para leer los valores ahora que ya sabemos cuántos hay
archivo.open(nombreArchivo);
if (!archivo.is_open()) {
    cout << "Error al reabrir el archivo de máscara." << endl;
    return nullptr;
}

// Leemos otra vez la semilla (porque tocaba abrirlo desde cero)
archivo >> seed;

// Creamos el arreglo para guardar los datos RGB
unsigned int* data = new unsigned int[n_pixels * 3];

// Leemos todos los valores RGB
for (int i = 0; i < n_pixels * 3; i = i + 3) {
    archivo >> r >> g >> b;
    data[i] = r;
    data[i + 1] = g;
    data[i + 2] = b;
}

archivo.close();
return data;
