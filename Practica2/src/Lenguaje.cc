// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Lenguaje.cc
//      Contiene las definiciones de la clase Lenguaje.c
// 

#include "Lenguaje.h"


  Lenguaje::Lenguaje(const std::set<Cadena>& build) {
    leng_ = build;
  }

  unsigned Lenguaje::size() {
    return leng_.size();
  }

  bool Lenguaje::search(Cadena& c) const {
    return leng_.count(c) > 0;
  }

  void Lenguaje::insert(const Cadena& chain) {
    leng_.insert(chain);
  }
  
  Lenguaje Lenguaje::unir(Lenguaje& leng2) {
    Lenguaje aux = leng_;
    for (auto it = leng2.leng_.begin(); it != leng2.leng_.end(); ++it) {
      aux.insert(*it);
    }

    return aux;
  }

  Lenguaje Lenguaje::inter(Lenguaje& leng2) {
    std::set<Cadena> aux;
    for (Cadena c : leng_) {
      if (leng2.search(c)) {
          aux.insert(c);
      }
    }
    return Lenguaje(aux);
  }

  Lenguaje Lenguaje::dif(Lenguaje& leng2) {
    std::set<Cadena> aux;
    for (Cadena c: leng_) {
      if (!leng2.search(c)) {
        aux.insert(c);
      }
    }
    return Lenguaje(aux);
  }

  Lenguaje Lenguaje::DoPrefix(const Cadena& chain) {
    Lenguaje result;
    Cadena prefix;
    for (unsigned i{0}; i < chain.get_length(); ++i) {
      result.insert(prefix);
      prefix.add_element_back(chain[i]);
    }
    result.insert(prefix);

    return result;
  }

  Lenguaje Lenguaje::DoSufix(const Cadena& chain) {
    Lenguaje result;
    Cadena sufix;
    for (unsigned i=chain.get_length(); i != 0; --i) {
      result.insert(sufix);
      sufix.add_element_front(chain[i-1]);
    }
    result.insert(sufix);

    return result;
  }

  Lenguaje DoSubCadenas(const Cadena&);
  Lenguaje DoSubSecuence(const Cadena&);

  std::ostream& operator<<(std::ostream& os, const Lenguaje& L) {
    os << "{";
    for (auto it = L.leng_.begin(); it != L.leng_.end(); ++it) {
        os << *it;   // usa el operador<< de Cadena
        if (std::next(it) != L.leng_.end()) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}