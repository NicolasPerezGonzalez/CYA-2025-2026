// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Counter.cc
//    Definición clase "counter"
//

#include "Counter.h"

Counter::Counter() {
  for_loops_ = 0;
  while_loops_ = 0;
  multi_comments_ = 0;
  normal_comments_ = 0;
  int_variables_ = 0;
  double_variables_ = 0;
}