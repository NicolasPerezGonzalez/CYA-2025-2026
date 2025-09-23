// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo tools.h
//      Contiene las funciones que van a ser usadas posteriormente en el main
// 

#include "Cadena.cc"
#include "Alfabeto.cc"
#include <fstream>
#include <sstream>

#ifndef TOOLS_H
#define TOOLS_H

bool is_open(const std::string& filename) {
  std::ifstream file(filename);
  return file.is_open();
}

void usage() {
  std::cout << " This program reads a file, and read it line by line,\n";
  std::cout << " identifying the first column as a String (defined as concatenation\n of simbols)";
  std::cout << " and the second as an Alphabet (defined as a set of the simbols that\n can be used to";
  std::cout << " make Strings).\n\n";
  std::cout << " After reading the file, the user have 5 functions:\n";
  std::cout << " 1 - Alfabeto. This one prints the Alphabet of each String\n";
  std::cout << " 2 - Longitud. This one prints the lenght of the String\n";
  std::cout << " 3 - Inversa. This prints the String inverted\n";
  std::cout << " 4 - Prefijos. This one prints the set of prefix of the String\n";
  std::cout << " 5 - Sufijos. This one prints the set of the suffix of the String\n\n";
}

bool valid_option(std::string option) {
  unsigned n = std::stoi(option);
  if (n!=0 && n<6) {
    return 1;
  }
  return 0;
}

std::vector<std::string> store_content(std::string& filename) {
  std::vector<std::string> save;

  std::string linea;                        // Linea getline
  std::ifstream entry;                      // flujo de salida de fichero
  std::string aux1;                         // string designada a almacenar la cadena de cada linea
  std::string aux2;                         // string designada a almacenar el alfabeto de cada linea

  while (std::getline(entry, linea)) {
    std::istringstream stream(linea);
    stream >> aux1 >> aux2;

    save.push_back(aux1);
    save.push_back(aux2);
  }

  return save;
}

void DoAlphabet(std::vector<std::string> data, std::string& fout) {
  std::ofstream output(fout);

  // Recorrer los valores impares es recorrer los alfabetos almacenados
  for (unsigned i{1}; i < data.size(); ++(++i)) { 
    Alfabeto aux = data[i];
    output << aux << std::endl;
  }
}

void DoLength(std::vector<std::string> data, std::string& fout) {
  std::ofstream output(fout);

  for (unsigned i{0}; i < data.size(); ++(++i)) {
    Cadena aux = data[i];
    output << aux.get_length() << std::endl;
  }
}

void DoInverse(std::vector<std::string> data, std::string& fout) {
  std::ofstream output(fout);

  for (unsigned i{0}; i < data.size(); ++(++i)) {
    Cadena aux = data[i];
    output << aux.reverse() << std::endl;
  }
}

void DoPrefix(std::vector<std::string> data, std::string& fout) {
  std::ofstream output(fout);

  for (unsigned i{0}; i < data.size(); ++(++i)) {
    Cadena aux = data[i];
    aux.print_pre(output);
    output << std::endl;
  }
}

void DoSufix(std::vector<std::string> data, std::string& fout) {
  std::ofstream output(fout);

  for (unsigned i{0}; i < data.size(); ++(++i)) {
    Cadena aux = data[i];
    aux.print_suf(output);
    output << std::endl;
  }
}


#endif