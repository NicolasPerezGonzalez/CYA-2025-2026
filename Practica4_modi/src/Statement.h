// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Statement.h
//    Declaracion clase "statement"
//

#ifndef STATEMENT_H
#define STATEMENT_H

#include <iostream>
#include <string>
#include <regex>

class Statement {
  private:
    std::string type_;
    int line_;
  public:
    // Constructor
    Statement(const int line, const std::string& text);
    Statement() {};

    // Metodos
    int get_line() const {return line_;};
    std::string get_statement() const;

    // Sobrecarga E/S
    friend std::ostream& operator<<(std::ostream& out, const Statement& statement);
};


#endif