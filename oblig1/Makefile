GPP=g++
GPPOPT=-std=c++11

OBJ= blackjack

all: classes
	$(GPP) $(GPPOPT) -Wall blackjack.cpp Kort.o Kortstokk.o Spiller.o -o blackjack

classes:
	$(GPP) $(GPPOPT) -Wall -c Kort.cpp Kortstokk.cpp Spiller.cpp 
