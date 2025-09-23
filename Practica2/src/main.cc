// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo main.cc
//      El objetivo de la pr´actica es trabajar conceptos b´asicos sobre s´ımbolos, alfabetos,
//      cadenas y lenguajes, a trav´es del dise˜no de las clases correspondientes en C++. Adem´as
//      de repasar estos conceptos te´oricos, se propone que el alumnado utilice este ejercicio para
//      poner en pr´actica aspectos generales relacionados con el desarrollo de programas en C++.
// 

#include "tools.h"

int main(int argc, char *argv[]) {
  unsigned option{0};
  if (argc == 1) {
    usage();
  } else if (argc == 2 && argv[1] == "--help") {
    usage();
  } else if (argc == 4) {
    std::string filename {argv[1]};
    std::string outfile {argv[2]};
    if (!is_open(filename)) {
      std::cerr << "The file '" << filename << "' doesnt exist\n" << std::endl;
      usage();
      return 1;
    }
    if (valid_option(argv[3])) {
      std::vector<std::string> stored = store_content(filename);

      

    } else {
      std::cerr << "Opcion Incorrecta, use la opción --help para ayuda" << std::endl;
      return 1;
    }
  }
  
  return 0;
}