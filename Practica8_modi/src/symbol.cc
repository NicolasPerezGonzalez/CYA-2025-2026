/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Nicolás Pérez González
 * @date 04/11/2025
 * @brief Archivo: symbol.cc
 *        Definición de la clase simbolo
 */

#include <iostream>
#include "symbol.h"

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] symbol
 */
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.getSymbol();
  return out;
}

/** 
 *  @brief Sobrecarga del operador ==
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator==(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() == symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador !=
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator!=(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() != symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador <
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() < symbol2.getSymbol();
}
