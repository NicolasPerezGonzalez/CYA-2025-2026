// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Cadena.h
//      Contiene las declaraciones de la clase usada para representar las cadenas y sus operaciones
// 

#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include <string>
#include <iostream>

class Cadena {
  public:
    Cadena() {}
    Cadena(const std::string&);
    Cadena(const std::vector<char>&);
    ~Cadena() {}

    std::string get_cadena() const;
    unsigned get_length() const;
    Cadena reverse() const;
    void print(std::ostream& os = std::cout);
    void print_pre(std::ostream& os = std::cout);
    void print_suf(std::ostream& os = std::cout);
    void add_element_back(const char& simbol);
    void add_element_front(const char& simbol);

    // Sobrecarga E/S
    friend std::ostream& operator<<(std::ostream&, const Cadena&);
    char& operator[](std::size_t);
    const char& operator[](std::size_t) const;

  private:
    std::vector<char> secuence_;
};

#endif
