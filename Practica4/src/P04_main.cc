// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo P04_main.cc
//
//
//
//

#include "P04_tools.h"

int main(int argc, char *argv[]) {
  // Comprobar parametros
  if (argc == 1) { Error(); }
  Usage(argc,argv);
  // Ficheros de salida
  std::string InputFile = argv[1];
  std::string OuputFile = argv[2];
  // Comprobamos si el fichero de salida existe
  if (!is_open(InputFile)) {
    std::cerr << "No existe archivo " << InputFile << std::endl;
    exit(1);
  }
  // Ejecutamos el programa
  // Guardamos el análisis

  return 0;
}