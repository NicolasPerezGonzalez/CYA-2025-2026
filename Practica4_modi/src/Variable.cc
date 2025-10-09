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
//    Definición clase "variable"
//
#include "Variable.h"

// Tipos de variable:
const std::regex rInt("\\s*int.*");
const std::regex rDouble("\\s*double.*");
/*
const std::regex rFloat("\\s*float.*");
const std::regex rAuto("\\s*auto.*");
const std::regex rString("\\s*(std::)?string.*");
*/

const std::regex rName("[*a-zA-Z0-9_-]+");
const std::regex rValue("-?[0-9.]+");
const std::string rSpace(" ");

Variable::Variable(int line, std::string& text) {
  line_ = line;
  std::string aux_string = text;
  int found;    // find() devuelve el numero de coincidencias
  // Guardamos el tipo de variable:
  // INT
  if (regex_search(text, rInt)) {
    type_ = "INT";
    // La guardamos
    found = aux_string.find("int");
    aux_string = aux_string.substr(found);
  // DOUBLE
  } else if (regex_search(text, rDouble)) {
    type_ = "DOUBLE";
    // La guardamos
    found = aux_string.find("double");
    aux_string = aux_string.substr(found);
  }

  // Guardamos el nombre de la variable
  std::smatch match;
  found = aux_string.find_first_of(" ");    
  aux_string = aux_string.substr(found + 1);  // Almacenan la cadena despues del primer espacio de la declaracion del tipo de la variable
  // Almacenar nombre variable
  if (regex_search(aux_string, match, rName)) {name_=match.str(0);}
  // Almacenar valor (si tiene)
  found = aux_string.find_last_of("({=;");
  aux_string = aux_string.substr(found);
  with_value_ = false;
  if (regex_search(aux_string, match, rValue)) {
    value_ = match.str(0);
    with_value_ = true;
  }
}

// Metodos
std::string Variable::get_value() const {
  std::string val;
  if (!with_value_) {val = "undefined";}
  else {val = value_;}
  return val;
}

std::string Variable::get_line() const {
  return "[Line " + std::to_string(line_) + "]";
}

std::string Variable::get_variable() const {
  std::string aux_string = get_line() + rSpace;
  aux_string += get_type() + ":" + rSpace + get_name() + rSpace;
  if (with_value_) {aux_string += "=" + rSpace + value_;}
  return aux_string;
}

// Sobrecarga E/S
std::ostream& operator<<(std::ostream& out, const Variable& variable) {
  out << variable.get_variable();
  return out;
}
