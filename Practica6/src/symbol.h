/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Nicolás Pérez González (alu0101558219)
 * @brief Archivo: symbol.h
 *        Definición de la clase símbolo
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol {
 private:
  std::string symbol_;

 public:
  /// Constructores
  Symbol() {};
  Symbol(const std::string& symbol) { symbol_ = symbol; };
  Symbol(const char symbol) { symbol_ = symbol; };
  
  /// Getters
  std::string getSymbol() const { return symbol_; };
  int getLength() const { return symbol_.length(); };
  /// Setter
  void setSymbol(std::string& symbol) { symbol_ = symbol; };

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend bool operator==(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator!=(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator<(const Symbol& symbol1, const Symbol& symbol2);
};

#endif