GPP=g++
GPPOPT=-std=c++11

OBJ= blackjack

all: classes
	$(GPP) $(GPPOPT) blackjack.cpp Kort.o Kortstokk.o Spiller.o -o blackjack

classes:
	$(GPP) $(GPPOPT) -c Kort.cpp Kortstokk.cpp Spiller.cpp 
