// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Lenguaje.h
//      Contiene las declaraciones de la clase Lenguaje.h
// 

#include "Cadena.h"
#include <set>

class Lenguaje {
  public:
    Lenguaje() {}
    Lenguaje(const std::set<Cadena>&);
    ~Lenguaje() {}

    unsigned size();

    bool search(Cadena&) const;
    void insert(const Cadena&);
    
    Lenguaje unir(Lenguaje&);
    Lenguaje inter(Lenguaje&);
    Lenguaje dif(Lenguaje&);

    Lenguaje DoPrefix(const Cadena&);
    Lenguaje DoSufix(const Cadena&);
    Lenguaje DoSubCadenas(const Cadena&);
    Lenguaje DoSubSecuence(const Cadena&);

    const char& operator[](std::size_t) const;
    friend std::ostream& operator<<(std::ostream&, const Lenguaje&);

  private:
    std::set<Cadena> leng_;
};