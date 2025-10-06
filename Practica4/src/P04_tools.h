// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo P04_tools.cc
//
//
//
//


#include <iostream>
#include <fstream>

void Error() {
  std::cerr << "No se han introducido parámetros\nPruebe --help para más información" << std::endl;
  exit(1);
}

void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cerr << argv[0] << ": Ha introducido más de 2 parámetros.\nPruebe " << argv[0] << " --help para más información." << std::endl;
    exit(1);
  }
  std::string aux=argv[1];
  if (aux == "--help" || aux == "-h") {
    std::cout << "Este es un programa en C++ que analiza el contenido de ficheros de código haciendo uso de expresiones regulares.\nEl programa recibirá por línea de comandos el nombre del fichero de entrada y el nombre del fichero de salida" << std::endl;
    std::cout << "De esta forma: " << argv[0] << " <Inputfile> <Ouputfile>" << std::endl;
    std::cout << "\nSe analizarán concretamente:\n  Variables: tipo INT y DOUBLE\n  Bucles: tipo FOR y WHILE\n  Main: Se detectará si existe o no una función main\n  Comentarios: Se detectarán los comentarios // (una linea) y /**/ (múltiples)\n";
    exit(0);
  }
  if (argc != 3) {
    std::cerr << argv[0] << ": Faltan parámetros.\nPruebe " << argv[0] << "--help para mas información." << std::endl;
    exit(1);
  }
}

bool is_open(const std::string& filename) {
  std::ifstream file(filename);
  return file.is_open();
}