// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Perez Gonzalez
// Correo: alu0101558219@ull.edu.es
// Fecha: 21/09/2025
// Archivo Cadena.cc
//      Contiene las definiciones de la clase usada para representar las cadenas y sus operaciones
// 

#include "Cadena.h"

	Cadena::Cadena(const std::string& build) {
		unsigned i{0};
		while (build[i] != '\0') {
			if (build[i] != '&') {
				secuence_.push_back(build[i]);
			}
			++i;
		}
	}

	Cadena::Cadena(const std::vector<char>& build) {
		secuence_=build;
	}

	std::string Cadena::get_cadena() const {
		return std::string (secuence_.begin(), secuence_.end());
	}

	unsigned Cadena::get_length() const {
		return secuence_.size();
	}

	Cadena Cadena::reverse() const {
		std::vector<char> aux;
		for (unsigned i=secuence_.size(); i!=0; --i) {
			aux.push_back(secuence_[i-1]);
		}
		return aux;
	}

	void Cadena::print(std::ostream& os) {
		if (secuence_.size()==0) {
			os << '&';
		} else {
			for (unsigned i{0}; i < secuence_.size(); ++i) {
				os << secuence_[i];
			}
		}
	}

	void Cadena::print_pre(std::ostream& os) {
		os << '{';
		Cadena prefixs;
		for (unsigned i{0}; i < secuence_.size(); ++i) {
			os << prefixs << ', ';
			prefixs.add_element_back(secuence_[i]);			
		}
		os << prefixs << '}';
	}

	void Cadena::print_suf(std::ostream& os) {
		os << '{';
		Cadena sufix;
		for (unsigned i=secuence_.size(); i!=0; --i) {
			os << sufix << ', ';
			sufix.add_element_front(secuence_[i-1]);
		}
		os << sufix << '}';
	}

	void Cadena::add_element_back(const char& simbol) {
		secuence_.push_back(simbol);
	}

	void Cadena::add_element_front(const char& simbol) {
		secuence_.insert(secuence_.begin(), simbol);
	}

	// Sobrecarga E/S
	std::ostream& operator<<(std::ostream& os, const Cadena& chain) {
		if (chain.get_length() == 0) {
			os << '&';
		} else {
			for (unsigned i{0}; i < chain.get_length(); ++i) {
				os << chain[i];
			}
		}

		return os;
	}

	char& Cadena::operator[](std::size_t i) {
		return secuence_[i];
	}

	const char& Cadena::operator[](std::size_t i) const {
		return secuence_[i];
	}
