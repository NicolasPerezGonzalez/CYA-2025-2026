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
//    Contiene la función main del programa, este programa recibe por linea de comandos:
//    $ ./P4_CyAEX <Inputfile> <OupuFile>
//    Siendo <Inputfile> un fichero de código en c++
//    Compilacion del programa: make
//

#include "P04_tools.h"
#include "Analyzer.h"

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
  Analyzer analyzed_program(InputFile);
  // Guardamos el análisis
  std::ofstream output_file{OuputFile};
  analyzed_program.Show(output_file);

  return 0;
}