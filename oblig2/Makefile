FLTK := $(shell fltk-config --version )

ifndef FLTK
$(error "Fant ingen versjon av FLTK!")
endif

LDOPTS:=$(shell fltk-config --ldflags)

SRC:=has_color.cpp is_vector.cpp dot.cpp rocket.cpp    #cpp-filer
OBJECTS:=has_color.o is_vector.o dot.o rocket.o
BINARY=fireworks

all: info classes
	g++ -std=c++11 main.cpp $(OBJECTS) -o $(BINARY) $(LDOPTS)
	
	
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
classes:
	@echo "Building for "$(FLTK)
	g++ -std=c++11 -c $(SRC) $(LDOPTS)
	@echo 
	@echo 'Done. Run with ./'$(BINARY)
	@echo 


clean:
	$(RM) $(BINARY)
