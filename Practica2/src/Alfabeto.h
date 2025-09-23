// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Alfabeto.h
//      Contiene la declaración de la clase Alfabeto
//

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <iostream>

class Alfabeto {
  public:
    Alfabeto();
    Alfabeto(const std::string&);

    void insert(char c);
    bool search(char c) const;

    std::size_t size() const;

    Alfabeto unir(const Alfabeto& other) const;
    Alfabeto inter(const Alfabeto& other) const;

    friend std::ostream& operator<<(std::ostream&, const Alfabeto&);

  private:
    std::set<char> simbolos_;
};

#endif