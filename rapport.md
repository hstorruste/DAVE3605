#Oblig 1, Rapport blackjack

##Beskrivelse
Blackjack
Spillet er implementert med enkle spilleregler. Man blir bedt om å velge fra 1-5 spillere. Deretter skal man gi spillerene sine navn. Du velger hvor mye penger hver enkelt spiller skal ha med seg til bordet, og deretter hvor mye de skal satse for hver runde. Hver spiller får vite det ene av dealeren sine kort, men begge sine egne. Etter hver runde oppdateres spillernes saldo.

###Ting å utbedre
- 1-5 spillere. Begrenset for å ha kontroll med input. Forhindrer negative tall og for mange spillere, som kan føre til at kortstokken går tom for kort. Dette kunne jeg ha utbedret med at over et viss antall spillere måtte det brukes flere kortstokker.
- Flere kortstokker.
- Hva når en spiller går tom for penger? Her avsluttes nå spillet for alle som spiller. Det burde her vært mulig å fortsette med de andre spillerne.
- Mye kode på samme sted. Jeg burde ha fått mer av koden ut av main, for å få det ryddigere.
- Benytte K, Q og J isteden for 13 12 og 11. Og ♠ ♥ ♦ ♣ ♤ ♡ ♢ ♧ istedenfor s, h, d, c.
- Legge til split og double mulighet.


###Klassehierarki
	Spillet består av følgene klasser med tilhørende header-filer:
	- Kort
	- Kortstokk
	- Spiller
	
	+--------------------+	+----------------------+  +---------------------------+
	|Kort                |  |Kortstokk             |  |Spiller                    |
	|--------------------|  |----------------------|  |---------------------------|
	|suit_	 char	     |  |stokken  vector<Kort> |  |navn	  string              |
	|value_	 int	     |  |kastet	  vector<Kort> |  |saldo  int                 |
	|                    |  |                      |  |hand	  vector<Kort*>	      |
	|--------------------|  |----------------------|  |---------------------------|
	|getsuit() : char    |  |empty() : bool	       |  |getnavn() : string         |
	|getvalue() : int    |  |stokk() : void	       |  |getsaldo() : int           |
	|toString() : string |  |del() : Kort*	       |  |gethand() : vector<Kort*>* |
	+--------------------+  +----------------------+  |hit(Kort*) : void          |
	                                                  |updateSaldo(int) : int     |
	                                                  |throwhand() : void         |
	                                                  +---------------------------+

	 
##Andre refleksjoner
Det har vært mange utfordringer med denne oppgaven. Etter å ha mest erfaring med java-programmering, så er det her et stort knippe med "uforståelige" feil som oppstår.(de blir heldigvis litt mer forståelige etterhvert).
Jeg ønsket ved et tilfelle å returnere en null-peker, for å gi beskjed om at kortsokken var tom. Der møtte jeg store problemer, da man ikke kan dereference en null-pointer. Jeg unngikk etterpå problemet ved å alltid sjekke om stokken var tom før jeg trakk et nytt kort.
Jeg gjorde meg også mange erfaringer med scope til variabler/verdier. Her var det mye prøving å feiling, men fikk mer dreisen på det etterhvert.
Det som oftest gav meg hodebry var når jeg forsøkte å bruke arrayer. Disse oppførte seg sjelden slik jeg ville, og endte ofte med å finne andre løsninger.
Pass by reference vs pass by value. Det ble jeg etterhvert flinkere på, men jeg er nok ikke konsekvent i hvor jeg bruker det ene eller det andre. Hadde jeg hatt mere tid skulle jeg gjerne gått igjennom å rensket opp mange småe detaljer.


##Oppdatering 04.03
- Jeg fjernet mulighet for å ta 'hit' etter at man har gått over 21. 
- Lagt inn sikring (if-test) slik at kortstokken ikke blir tom, og kaster en 'std::out-of-range'-exception.
- Man ser nå hvor mange poeng man har på hånden.
- Mer flittig bruk av pekere, slik at det ikke lages 'kopier' av kort. Kortene eksisterer bare ett sted i minne. Gjelder spesielt score-metoden i blackjack.cpp. 
