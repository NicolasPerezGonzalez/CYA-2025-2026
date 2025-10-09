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

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "Comment.h"
#include "Variable.h"
#include "Statement.h"
#include "Counter.h"


class Analyzer {
  private:
    // Filename
    std::string filename_;
    // Fichero
    std::vector<std::string> lines_;
    // Coments
    Comment brief_;
    std::vector<Comment> comments_;
    // Variables
    std::vector<Variable> variables_;
    // Statements
    std::vector<Statement> statements_;
    // Counters
    Counter counter_;
    // Main
    bool main_;
    int mainline_;    
  public:
    // Constructor (mediante un fichero de entrada)
    Analyzer(std::string& the_filename);
    // Metodos del constructor
    void CommentAnalyzer(std::ifstream& input_file, std::string& line);
    void StatementAnalyzer(std::ifstream& input_file, std::string& line);
    void MainAnalyzer(std::ifstream& input_file, std::string& line);
    void VariableAnalyzer(std::ifstream& input_file, std::string& line);

    // Metodos
    std::string get_variables() const;
    std::string get_statements() const;
    std::string get_comments() const;
    void Show(std::ostream& out = std::cout) const;
};

#endif