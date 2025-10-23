/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Nicolás Pérez González (alu0101558219)
 * @brief Archivo: sequence.h
 *        Definición de la clase cadena
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Sequence {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> sequence_;
  std::string string_;
 public:
  /// Constructor
  Sequence(std::string& string);
  /// Getters
  Alphabet getAlphabet() const { return alphabet_; };
  std::string getSequence() const;
  std::string getString() const { return string_; };
  /// Funciones
  int length();
  std::string reverse();
  // Sequence reverse();
  std::string prefixes();
  std::string suffixes();
  std::string substrings();
  /// Modificación
  bool is_in(Symbol symbol);
  std::string non_used();
};

#endif