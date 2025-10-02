// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Alfabeto.cc
//      Contiene la definicion de la clase Alfabeto
//

#include "Alfabeto.h"

Alfabeto::Alfabeto(const std::string& build) {
  for (unsigned i{0}; i < build.size(); ++i) {
    simbolos_.insert(build[i]);
  }
}

Alfabeto::Alfabeto(const std::set<char>& build) {
  simbolos_=build;
}

void Alfabeto::insert(char c) {
  simbolos_.insert(c);
}

bool Alfabeto::search(char c) const {
  return simbolos_.count(c) > 0;
}

std::size_t Alfabeto::size() const {
  return simbolos_.size();
}

Alfabeto Alfabeto::unir(const Alfabeto& other) const {
  Alfabeto res = *this;
  res.simbolos_.insert(other.simbolos_.begin(), other.simbolos_.end());
  return res;
}


Alfabeto Alfabeto::inter(const Alfabeto& other) const {
  std::set<char> res;
  for (char c : simbolos_) {
      if (other.search(c)) {
          res.insert(c);
      }
  }
  return Alfabeto(res);
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& out) {
  os << "{";
  for (auto it = out.simbolos_.begin(); it != out.simbolos_.end(); ++it) {
    if (it != out.simbolos_.begin()) {
      os << ", ";
    }
    os << *it;
  }
  os << "}";
  return os;
}