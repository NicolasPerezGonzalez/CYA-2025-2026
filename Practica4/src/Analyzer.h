// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Analyzer.h
//    Declaración clase "analyzer"
//

#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include <vector>
#include "Comment.cc"

class Analyzer {
  private:
    // Filename
    std::string filename_;
    // Coments
    Comment brief_;
    std::vector<Comment> comments_;
    // Description
    // Variables
    // Statements
    // Main
    bool main_;
    int mainline_;
    
    
  public:

};


#endif