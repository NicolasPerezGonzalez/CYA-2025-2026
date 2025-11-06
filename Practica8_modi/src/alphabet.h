/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Nicolás Pérez González
 * @date 04/11/2025
 * @brief Archivo: alphabet.h
 *        Declaracion de la clase alfabeto
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "symbol.h"

extern const std::vector<char> kAlphabet;
extern std::vector<bool> Used;
extern const char SPACE;

class Alphabet {
  private:
    std::set<Symbol> alphabet_;

  public:
    /// Constructores
    Alphabet() {};
    Alphabet(std::string& string);

    /// Getters
    std::set<Symbol> getAlphabet() const { return alphabet_; };
    int getSize() const { return alphabet_.size(); };

    /// Funciones
    bool find(Symbol symbol) const;
    void add(Symbol symbol);

    /// Sobrecargas
    friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
    friend Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2);
};

#endif