// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Comment.h
//    Declaracion clase "comment"
//

#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Comment {
  private:
    int start_;
    int end_;
    std::string text_;

  public:
    Comment(const int start, const int end, const std::string& text);
    Comment(const int line, const std::string& text);
    Comment() {}; // Por defecto

    // Funciones
    std::string get_lines() const;
    int get_start() const {return start_;};
    int get_end() const {return end_;};
    std::string get_text() const {return text_;};

    // Sobrecarga E/S
    friend std::ostream& operator<<(std::ostream& out, const Comment& comment);
};


#endif
