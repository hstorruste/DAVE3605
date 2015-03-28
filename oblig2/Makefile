FLTK := $(shell fltk-config --version )

ifndef FLTK
$(error "Fant ingen versjon av FLTK!")
endif

LDOPTS:=$(shell fltk-config --ldflags)

SRC:=has_color.cpp is_vector.cpp dot.cpp animation_canvas.cpp #Felles cpp-filer
OBJECTS:=has_color.o is_vector.o dot.o animation_canvas.o  #Felles

SRC1:=rocket.cpp fireworks.cpp   #fireworks sine cpp-filer
OBJECTS1:=rocket.o fireworks.o #fireworks
BINARY1=fireworks

#fireworks2 sine filer
SRC2:=blinkingDot.cpp BlinkingDotFactory.cpp NormalDotFactory.cpp tintedDot.cpp MixedDotFactory.cpp rocket2.cpp fireworks2.cpp 
OBJECTS2:=blinkingDot.o BlinkingDotFactory.o NormalDotFactory.o tintedDot.o MixedDotFactory.o rocket2.o fireworks2.o 
BINARY2=fireworks2

.PHONY: fireworks fireworks2

all: all1 all2

fireworks: all1

fireworks2: all2

all1: info classes1
	g++ -std=c++11 main.cpp $(OBJECTS) $(OBJECTS1) -o $(BINARY1) $(LDOPTS)

all2: info classes2
	g++ -std=c++11 main2.cpp $(OBJECTS) $(OBJECTS2) -o $(BINARY2) $(LDOPTS)

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
	g++ -std=c++11 -c $(SRC) $(SRC1) $(LDOPTS)
	@echo 
	@echo 'Done. Run with ./'$(BINARY1)
	@echo 

classes2:
	@echo "Building for "$(FLTK)
	g++ -std=c++11 -c $(SRC) $(SRC2) $(LDOPTS)
	@echo 
	@echo 'Done. Run with ./'$(BINARY2)
	@echo 

#Fjerner kompilerte filer og backupfiler
clean:
	$(RM) $(BINARY1)
	$(RM) $(BINARY2)
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS1)
	$(RM) $(OBJECTS2)
	$(RM) *.*~  


