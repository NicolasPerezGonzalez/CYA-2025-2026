// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Statement.cc
//    Definicion clase "statement"
//

#include "Statement.h"

const std::regex rFor("for\\s*?(.+)");
const std::regex rWhile("while\\s*?(.+)");
/*
const std::regex rIf("if\\s*?(.+)"); /// (No se pide)
const std::regex rReturn("return\\s*?(.+)"); /// (No se pide)
const std::regex rSwitch("switch\\s*?(.+)"); /// (No se pide)
const std::regex rInclude("#include\\s*?(.+)"); /// (No se pide)
*/

Statement::Statement(const int line, const std::string& text) {
  line_ = line;
  if (regex_search(text,rFor)) {type_ = "for";}
  else if(regex_search(text, rWhile)) {type_ = "while";}
  /*
  else if (regex_search(text, kIf)) { type_ = "if"; }
  else if (regex_search(text, kReturn)) { type_ = "return"; }
  else if (regex_search(text, kSwitch)) { type_ = "switch"; }
  else if (regex_search(text, kInclude)) { type_ = "include"; }
  */
  else { type_ = "undefined"; }
}

std::string Statement::get_statement() const {
  /*
  if (type_ == "if") return "[Line " + std::to_string(line_) + "] IF";
  if (type_ == "return") return "[Line " + std::to_string(line_) + "] RETURN";
  if (type_ == "switch") return "[Line " + std::to_string(line_) + "] SWITCH";
  if (type_ == "include") return "[Line " + std::to_string(line_) + "] INCLUDE";
  */
  return "[Line " + std::to_string(line_) + "] LOOP: " + type_;
}

std::ostream& operator<<(std::ostream& os, const Statement& statement) {
  os << statement.get_statement();
  return os;
}