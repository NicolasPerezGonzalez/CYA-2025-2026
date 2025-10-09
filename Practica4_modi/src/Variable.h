// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Variable.h
//    Declaracion clase "variable"
//

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <regex>

class Variable {
  private:
    int line_;
    std::string type_;
    std::string name_;
    bool with_value_;
    std::string value_;

  public:
  // Constructor
  Variable(int line, std::string& text);
  // Constructor por defecto
  Variable() {}

  // Metodos
  std::string get_value() const;
  std::string get_line() const;
  std::string get_type() const {return type_;};
  std::string get_name() const {return name_;};
  std::string get_variable() const;

  // Sobrecarga E/S
  friend std::ostream& operator<<(std::ostream& out, const Variable& variable);
};

#endif