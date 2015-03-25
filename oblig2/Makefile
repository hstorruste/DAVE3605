FLTK := $(shell fltk-config --version )

ifndef FLTK
$(error "Fant ingen versjon av FLTK!")
endif

LDOPTS:=$(shell fltk-config --ldflags)

SRC:=has_color.cpp is_vector.cpp dot.cpp rocket.cpp animation_canvas.cpp fireworks.cpp   #cpp-filer
OBJECTS:=has_color.o is_vector.o dot.o rocket.o animation_canvas.o fireworks.o
BINARY=fireworks

SRC2:=has_color.cpp is_vector.cpp dot.cpp rocket2.cpp
OBJECTS2:=has_color.o is_vector.o dot.o rocket2.o
BINARY2=fireworks2

.PHONY: fireworks fireworks2

fireworks: all1

fireworks2: all2

all1: info classes1
	g++ -std=c++11 main.cpp $(OBJECTS) -o $(BINARY) $(LDOPTS)

all2: info classes2
	g++ -std=c++11 main.cpp $(OBJECTS2) -o $(BINARY2) $(LDOPTS)

# Skriv ut litt info om FLTK lokalt
info:
	@echo "==================== BIULDING FOR FLTK ================================"
	@echo "Found FLTK-version: \t" $(FLTK) 
	@echo "Assumed options: \t" $(LDOPTS)
	@echo ""
	@echo 'Full options from "fltk-config --ldflags:"'
	@echo $(shell fltk-config --ldflags)
	@echo "======================================================================"


# Bygg, med valgte opsjoner
classes1:
	@echo "Building for "$(FLTK)
	g++ -std=c++11 -c $(SRC) $(LDOPTS)
	@echo 
	@echo 'Done. Run with ./'$(BINARY)
	@echo 

classes2:
	@echo "Building for "$(FLTK)
	g++ -std=c++11 -c $(SRC2) $(LDOPTS)
	@echo 
	@echo 'Done. Run with ./'$(BINARY2)
	@echo 

clean:
	$(RM) $(BINARY)
