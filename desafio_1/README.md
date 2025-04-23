 Desafío 1 - 2025-1

Este repositorio contiene la solución al Desafío 1 del curso del semestre 2025-1.

 📁 Estructura del repositorio

Todo el proyecto está dentro de la carpeta desafio_1, que está organizada así:

- 📁 data/ → contiene las imágenes BMP y archivos .txt de máscaras (como M1.txt, etc.)
- 📁 src/ → contiene todo el código fuente del programa
- 📁 video/ → estará el video explicativo del proyecto (cuando esté listo)
- 📄 DESAFÍO 1-2025 1.PDF → es el informe técnico del desafío
- 📄 proyecto.pro → archivo para abrir el proyecto en Qt Creator
- 📄 README.md → este mismo archivo

 🧪 ¿Qué hace este proyecto?

Este programa intenta reconstruir una imagen distorsionada (ID.bmp), aplicando combinaciones de transformaciones bit a bit. Lo que hace es:

- Cargar una imagen distorsionada.
- Probar distintos órdenes de transformación:
  - XOR con otra imagen.
  - Rotación de bits (por ejemplo, rotar cada byte).
  - Desplazamiento de datos (mover los bytes con un offset).
- Comparar el resultado con un archivo .txt (que tiene los valores RGB enmascarados y una semilla).
- Si encuentra la combinación correcta, reconstruye la imagen original y la guarda como Reconstruida.bmp.

Todo esto pasa automáticamente y se muestra en consola si se logró o no.

 🔧 Tecnologías y restricciones

- Lenguaje: C++ con estándar C++17
- Librería: Qt (usamos QImage y QString)
- Memoria dinámica: uso de punteros y new/delete
- Restricciones: no se usan STL, vectores, ni estructuras

 🗂️ Archivos importantes

- DESAFÍO 1-2025 1.PDF → el informe donde explico todo lo que hice
- src/funciones.h → ahí están todas las funciones declaradas
- proyecto.pro → para compilarlo en Qt Creator
- src/main_caso1.cpp → prueba simple con un archivo de máscara (M1.txt)
- src/main_caso2.cpp → prueba más avanzada con múltiples máscaras (M0.txt a M6.txt)

  Video demostrativo

El video se va a guardar en la carpeta video/.  
Y cuando lo tenga, también lo comparto por enlace.

 Autor

- Carlos Mario Rendón Martínez  
- Curso: Informática II  
- Semestre: 2025-1  
- Universidad de Antioquia



