// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Comment.cc
//    Definicion clase "comment"
//

#include "Comment.h"

// Constructor de varias lineas
Comment::Comment(const int start, const int end, const std::string& text) {
  start_ = start;
  end_ = end;
  text_ = text;
}

// Constructor para el comentario de una linea
Comment::Comment(const int line, const std::string& text) {
  start_ = line;
  start_ = line;
  text_ = text;
}

// Getter Lineas
std::string Comment::get_lines() const {
  std::string lines = "[Line";
  // Si es de una línea
  if (start_ == end_) {lines += " " + std::to_string(end_) + "]";}
  // Si es de varias líneas
  else {lines += "s " + std::to_string(start_) + "-" + std::to_string(end_) + "]";}
  return lines;
}

// Sobrecarga E/S
std::ostream& operator<<(std::ostream& out, const Comment& comment) {
  // Si es de una línea
  if (comment.start_ == comment.end_) { out << "[Line " << comment.start_ << "] " << comment.text_;}
  // Si es de varias líneas
  else {out << "[Lines " << comment.start_ << "-" << comment.end_  << "]: " << comment.text_;}
  return out;
} 