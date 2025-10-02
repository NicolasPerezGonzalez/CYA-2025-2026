# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Autor: Nicolas Perez Gonzalez
# Correo: alu0101558219@ull.edu.es
# 
# Archivo: Makefile (programa compilación)
# 


###############
#  VARIABLES  #
###############

# Nombre del proyecto
NAMEPRAC 	= P2_CyA
NAMEEXEC	=	P2_CyAEX

# Shell a usar
SHELL		=	/bin/sh

# Variable de posición del directorio src
SRCDIR 		= 	src
BINDIR 		= 	bin
ARCDIR		= 	$(SRCDIR)/archivos
OBJDIR 		= 	$(SRCDIR)/obj

# Elección de compilador
CXX 		= 	g++

# -g para depurar. -Wall para avisos
CXXFLAGS 	= 	-std=c++2b -Wall
O		=	-o

MD 		= 	mkdir -p
RM 		= 	rm -rf


SRC =	$(patsubst $(SRCDIR)/%.cc, $(OBJDIR)/%.o,\
			$(wildcard $(SRCDIR)/*.cc))

all: $(NAMEPRAC)

$(NAMEPRAC): $(SRC)
	@$(MD) $(BINDIR) 
	@echo $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) $O $(BINDIR)/$(NAMEEXEC)
	@echo "Ejecutable completado!" 
  
$(OBJDIR)/%.o: $(SRCDIR)/%.cc 
	@$(MD) $(OBJDIR) 
	@echo $< $@ 
	@$(CXX) $(CXXFLAGS) -g -c $< $O $@ 

# Make clean para eliminar los binarios y los objetos
clean:
	@echo "Eliminando carpetas OBJ y BIN"
	$(RM) $(OBJDIR)
	$(RM) $(BINDIR)
	@echo "Eliminación completada"

# Crea una estructura básica con los archivos 
init:
	@echo "Creando directorios bases y archivos (src, main, tools...)"
	
	$(MD) ./$(NAMEPRAC)/src
	
	@cd ./$(SRCDIR); echo $(CABECERA) > "$(NAMEEXEC).cc"
	@cd ./$(SRCDIR); echo $(CABECERA) > "tools.cc"
	@cd ./$(SRCDIR); echo $(CABECERA) > "tools.h"

	@touch ./$(NAMEPRAC)/README.md
	@cp Makefile ./$(NAMEPRAC)

	@echo "\nFinalizada la creación de archivos"

# Make run intenta ejecutar el programa, pero no logro que funcione
run:
	./$(BINDIR)/turingmachine $(ARCDIR)/input.tm $(ARCDIR)/input.tape

# Elimina todo el programa 
clean_all:
	@echo "Eliminando todos los archivos de $(NAMEPRAC)"
	rm -rf $(NAMEPRAC)
	@echo "Eliminación completada"

# Cabecera para los programas 
CABECERA	= "/**\n\
 * @file $(NAMEEXEC).cc\n\
 * @author Nicolas Perez Gonzalez (alu0101558219)\n\
 * @brief\n\
 * @version 0.1\n\
 * @date\n\
 */\n"