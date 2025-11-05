/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 20 Nov 2022
 * @brief Archivo: main_p08grammar.cc
 *        Contiene la función main del proyecto
 *        Este programa recibe por línea de comandos lo siguiente:
 *         ./Grammar2CNF input.gra output.gra
 *        Compilación del programa: make
 */

#include <iostream>
#include <string>

#include "P08_tools.h"
#include "file_tools.h"
#include "grammar.h"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kInputFileName = argv[1];
  FileExist(kInputFileName);
  std::string kOutputFileName = argv[2];
  FileExist(kOutputFileName);
  /// Llamamos al programa
  Grammar grammar(kInputFileName);
  grammar.check();
  // std::cout << grammar << std::endl;
  Grammar grammar_CNF = grammar.ConvertToCNF();
  // std::cout << grammar_CNF << std::endl;
  grammar_CNF.write(kOutputFileName);
  return 0;
}