// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 04/10/2025
// Archivo Counter.h
//    Declaracion clase "counter"
//

class Counter {
  private:
    int for_loops_;
    int while_loops_;
    int multi_comments_;
    int normal_comments_;
    int int_variables_;
    int double_variables_;

  public:
    // Constructor
    Counter();
    // Getters
    int get_for_count() const {return for_loops_;};
    int get_while_count() const {return while_loops_;};
    int get_multi_comments_count() const {return multi_comments_;};
    int get_normal_comments_count() const {return normal_comments_;};
    int get_int_count() const {return int_variables_;};
    int get_double_count() const {return double_variables_;};
    // Funciones
    void add_for() {++for_loops_;};
    void add_while() {++while_loops_;};
    void add_multi_comment() {++multi_comments_;};
    void add_normal_comment() {++normal_comments_;};
    void add_int() {++int_variables_;};
    void add_double() {++double_variables_;};
};