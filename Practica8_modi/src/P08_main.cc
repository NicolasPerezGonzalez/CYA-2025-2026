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
  /// Avisamos
  std::cout << "AVISO: El resto del main esta comentado para la evaluacion correcta de la practica, ahora el fichero output.gra contendra la gramática sin producciones unitarias,\nes decir, contendra el resultada del metodo realizado sobre input.gra" << std::endl;
  /// Llamamos al programa
  Grammar grammar(kInputFileName);
  /// Llamamos a la modi
  grammar.nonUniqProd();
  grammar.check();
  grammar.write(kOutputFileName);
  // std::cout << grammar << std::endl;
  // Grammar grammar_CNF = grammar.ConvertToCNF();
  // std::cout << grammar_CNF << std::endl;
  // grammar_CNF.write(kOutputFileName);
  return 0;
}