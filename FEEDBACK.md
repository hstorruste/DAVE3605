# Oblig 1

### Resultat: 
Godkjent (v2)


#### Update:

Fint at du rettet opp i alle feilen, bra! Godkjent


### Checklist:
* [x] Begge programmen bygger med `make`.
* [x] Begge programmen starter og kjører under Linux.
* [x] **oppvarming** gir riktig output.
* [/] **blackjack** har det viktigeste funksjonaliteten.
	* [x] En spiller har et saldo og kan satse et beløp.
	* [x] En spiller har valgen "HIT" og "STAND".
	* [x] En spiller kan ikke fortsette når den har gått tom for penger.
	* [x] Dealerns handlinger virker riktige.
	* [/] Spillet følger reglene til BlackJack.
* [] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [x] Ingen minnelekasjer funnet med `valgrind`.
* [x] Repo innholder `RAPPORT.md`.


### Tilbakemelding:

Et stort pluss for at du implementert multiplayer (even om spillet avsluttes for alle, som du skrevet i rapporten)!

Et pluss for implementasjon av klasser! Synes dog din main-funksjon alt for stor (dette har du nevnt i rapporten).

Savner dog hvertfall bokstav for kledde kort og ess, `A J Q K`, hvilket gjør spillet litt vanskelig og spille. Hadde gjerne velet se hvor mye en hånd er verdt, før jeg velger om jeg skal HIT/STAND.

En ting som ikke jeg oppdaget er at du har mulighet å trekke kort, even når spilleren faktisk gått BUST, hvilket resulterer i en ganske kryptisk "kort-string":

	andreas has: s11c4
	Do you HIT(h) or STAY(s)? h 
	andreas has: s11c4c13
	// hit, hit, hit, hit...
	andreas has: s11c4c13s13d5d7s12s3c7
	Do you HIT(h) or STAY(s)? s
	andreas has: 66
	BUST!

Hvis jeg gjør dette nok ganger vil jeg tømme helt kortstokken, og spillet vil krasje:

	terminate called after throwing an instance of 'std::out_of_range'
	  what():  vector::_M_range_check
	h
	Aborted (core dumped)
	

#### Fix:
* Fjerne muligheten til å trekke kort (HIT) når player egentlig har gått bust.
* *Legge inn bokstav for kledde kort og en utskrift av hvor mye hånden er verdt.* (Ikke noe krav..)
* *Bryte ned main i flere funksjoner.* (Ikke noe krav...)
