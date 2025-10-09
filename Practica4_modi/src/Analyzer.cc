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

// MODI
const std::regex rInclude("#include \"(.+).(.+)\"|(<.+>)");
const std::regex rDefine("#define [a-zA-Z]+ [0-9]+");
const std::regex rPragma("#pragma [a-z]*");
// const std::regex rIfNdef();

void Analyzer::PrecomAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, rInclude)) {
    counter_.add_include();
  } else if (regex_search(line, rDefine)) {
    counter_.add_define();
  } else if (regex_search(line, rPragma)) {
    counter_.add_pragmat();
  }
}

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
  counter_.set_include(0);
  // Abrir fichero
  std::ifstream input_file{the_filename, std::ios_base::in};
  filename_ = the_filename;
  std::string line;
  // Valores por defecto
  main_ = false;
  brief_ = Comment(0, "Not found.");
  // Check si en estamos en un bucle
  int loop_depth = 0;
  bool pending_loop_open = false;
  // Recorremos los documentos
  while (getline(input_file, line)) {
    CommentAnalyzer(input_file, line);
    StatementAnalyzer(input_file, line);
    MainAnalyzer(input_file, line);
    PrecomAnalyzer(input_file, line);
    // ---- Actualizar estado del bucle ----
    bool is_loop = std::regex_search(line, rStatement); // detecta for o while
    if (is_loop) {
      // hemos encontrado un bucle; si no tiene { en la misma línea,
      // esperamos que aparezca en una posterior
      if (line.find('{') != std::string::npos) {
        ++loop_depth; // ya estamos dentro del cuerpo
      } else {
        pending_loop_open = true;
      }
    }
    // contar llaves en la línea
    int opens  = std::count(line.begin(), line.end(), '{');
    int closes = std::count(line.begin(), line.end(), '}');
    // si estamos esperando la '{' del bucle y aparece aquí:
    if (pending_loop_open && opens > 0) {
      ++loop_depth;
      pending_loop_open = false;
      --opens; // consumimos la primera '{' que abre el bucle
    }
    // Ajustar profundidad actual
    if (loop_depth > 0) {
      loop_depth += opens;
      loop_depth -= std::min(loop_depth, closes);
    }
    // -------------------------------------

    // Solo analizamos variables si NO estamos dentro de un bucle
    if (loop_depth == 0) {
      VariableAnalyzer(input_file, line);
    }
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

  out << "MAIN: \n";
  if (main_) out << "True" << std::endl;
  else out << "False" << std::endl;
  out << "(Line: " << mainline_ << ")" << std::endl;
  out << std::endl;

  out << "COMMENTS: " << std::endl;
  for (const auto& elem : comments_) {
    if (elem.get_text() == brief_.get_text()) {
      out << brief_.get_lines() << " DESCRIPTION" << std::endl;
    } else {
      out << elem << std::endl;
    }
  }


  out << std::endl;
  out << "####################\nCOUNTER: " << std::endl;
  out << "#include: " << counter_.get_include() << std::endl;
  out << "#define: " << counter_.get_define() << std::endl;
  out << "#pragma " << counter_.get_pragmat() << std::endl;
  // out << "#ifNdef...#endif " << counter_.get_ifNdef() << std::endl;
  out << "####################" << std::endl;
}

