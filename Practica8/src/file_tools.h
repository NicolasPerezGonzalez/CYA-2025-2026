/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Nicolás Pérez González
 * @date 04/11/2025
 * @brief Archivo:file_tools.h
 *        Funciones para facilitar la lectura y el tratamiento de archivos
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

/** 
 *  @brief Muestra el mensaje de error de formato
 *  @return void, pero termina el programa
 */
void ErrorFormato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** 
 *  @brief Comprueba si un fichero existe
 *  @param[in] name_of_file
 *  @return (void) Pero termina el programa si no existe
 */
void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}