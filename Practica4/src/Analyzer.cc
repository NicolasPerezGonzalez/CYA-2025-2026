// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Analyzer.cc
//    Definición clase "analyzer"
//

#include "Analyzer.h"

const std::regex rComment("//.*");
const std::regex rLongCommentStart("/\\*.*");
const std::regex rLongCommentEnd(".*\\*/");
const std::regex rMain("int main");
const std::regex rStatement("(for|while)\\s*?(.+)");
// const std::regex kStatement("(for|while|if|return|switch)\\s*?(.+)");
const std::regex rVariable("\\s+?(int|double).*");
// const std::regex kVariable("\\s+?(int|double|float|auto|string).*");
// Variable
const std::regex rName("[*a-zA-Z0-9_-]+");
const std::regex rValue("-?[0-9.]+");
const std::string rSpace(" ");
const std::regex rInt("\\s*int.*");
const std::regex rDouble("\\s*double.*");

// Statement
const std::regex rFor("for\\s*?(.+)");
const std::regex rWhile("while\\s*?(.+)");

void Analyzer::CommentAnalyzer(std::ifstream& input_file, std::string& line) {
  lines_.push_back(line);
  // Buscar comentarios de una linea
  if (regex_search(line, rComment)) {
    counter_.add_normal_comment();
    int found = line.find_first_of("//");
    Comment comment(lines_.size(), line.substr(found));
    comments_.push_back(comment);
  // Buscar comentarios multi linea
  } else if (regex_search(line, rLongCommentStart)) {
    counter_.add_multi_comment();
    std::string aux_string;       // Comentario completo
    int start = lines_.size();
    // Buscamos el final del comentario
    while (!regex_search(line,rLongCommentEnd)) {
      aux_string += "\n" + line;  // En el proceso vamos almacenando lineas
      getline(input_file, line);
      lines_.push_back(line);
    }
    aux_string += "\n" + line; // Añadimos la última linea
    int found = aux_string.find("/*");
    aux_string = aux_string.substr(found);
    found = line.find("*/");
    Comment comment(start, lines_.size(), aux_string);
    comments_.push_back(comment);
    if (start == 1) brief_ = comment;
  }
}

void Analyzer::StatementAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, rStatement)) {
    if (regex_search(line, rWhile)) counter_.add_while();
    if (regex_search(line, rFor)) counter_.add_for();
    Statement statement(lines_.size(), line);
    statements_.push_back(statement);
  }
}

void Analyzer::MainAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, rMain)) {
    main_ = true;
    mainline_ = lines_.size();
  }
}

void Analyzer::VariableAnalyzer(std::ifstream& input_file, std::string& line) {
  if(regex_search(line, rVariable)) {
    if (regex_search(line,rInt)) counter_.add_int();
    if (regex_search(line,rDouble)) counter_.add_double();
    Variable variable(lines_.size(),line);
    variables_.push_back(variable);
  }
}

Analyzer::Analyzer(std::string& the_filename) {
  // Abrir fichero
  std::ifstream input_file{the_filename, std::ios_base::in};
  filename_ = the_filename;
  std::string line;
  // Valores por defecto
  main_ = false;
  brief_ = Comment(0, "Not found.");
  // Check si en 
  // Recorremos los documentos
  while (getline(input_file, line)) {
    CommentAnalyzer(input_file, line);
    StatementAnalyzer(input_file, line);
    MainAnalyzer(input_file, line);
    VariableAnalyzer(input_file, line);
  }
}

void Analyzer::Show(std::ostream& out) const {
  out << "PROGRAM: " << filename_ << "\n";
  out << "DESCRIPTION: " << "\n" << brief_.get_text() << std::endl;
  out << std::endl;

  out << "VARIABLES: " << std::endl;
  for (const auto& elem : variables_) out << elem << std::endl;
  out << std::endl;

  out << "STATEMENTS: " << std::endl;
  for (const auto& elem : statements_) out << elem << std::endl;
  out << std::endl;

  out << "MAIN: ";
  if (main_) out << "true" << std::endl;
  else out << "false" << std::endl;
  out << "Line: " << mainline_ << std::endl;
  out << std::endl;

  out << "COMMENTS: " << std::endl;
  for (const auto& elem : comments_) {
    if (elem.get_text() == brief_.get_text()) {
      out << brief_.get_lines() << "DESCRIPTION" << std::endl;
    } else {
      out << elem << std::endl;
    }
  }


  out << std::endl;
  out << "COUNTER: " << std::endl;
  out << "while: " << counter_.get_while_count() << std::endl;
  out << "for: " << counter_.get_for_count() << std::endl;
  out << "int: " << counter_.get_int_count() << std::endl;
  out << "double: " << counter_.get_double_count() << std::endl;

}

