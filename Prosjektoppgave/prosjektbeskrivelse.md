# Prosjektarbeid i C++ 2015
* **Tittel**: The Writer!
* **Gruppemedlemmer**:  s193370, s193467, s165519

## Prosjektbeskrivelse

Vi skal lage et spill som handler om en forfatter som skal skrive sin neste roman. For å få dette til må ulike behov dekkes. Forfatterens behov kan bestå av mat, søvn, inspirasjon, tjene penger ved å ta betalte skrivejobber etc. 

## Hovedfunksjonalitet i korte trekk

Spillet er en har trekk fra [Sims](http://en.wikipedia.org/wiki/The_Sims/), [Papers Please](http://dukope.com/) og idle games f.eks. [Cookie Clicker](http://orteil.dashnet.org/cookieclicker/). Man skal klikke rundt i rommet og løse oppgaver å dekke behovene til en forfatter så han/hun kan på best måte skrive romanen sin. Når man dekker et behov, slik som å spise eller sove, kan ikke forfatteren skrive men kan få en bonus etterpå. Dersom behovet er lavt vil han/hun skrive saktere. Noen behov påvirker hvor mange ord du klarer å skrive pr tidsenhet mens andre behov påvirker kvaliteten på hvert ord. 

## Designmål: 

Spillet skal ha et enkelt, og pent brukergrensesnitt som virker innbydende for spilleren. Spilleren får informasjon om bokas fremgang, forfatterens behov, tid og hvor mye penger han/hun har. Spilleren skal få klare tilbakemeldinger fra spillet dersom han/hun foretar seg noe.

Spillet skal være utvidbart. Man skal kunne legge til flere minigames, utfordringer og spillmekanikker. Her setter bare fantasien grenser. Derfor ønsker vi å ha et design der man kan legge til flere behov, rom, objekter etc. Vi ønsker også at spillet skal samle inn data og presentere disse til brukeren på ulike måter. Hvordan dette gjøres skal også kunne være utvidbart/utskiftbart.

## Avgrensning:

###Hva vi minst skal oppnå: 
Minimum gameplay; Et rom med en forfatter som skriver en bok. Han/hun har behov som vises som behovsmetere.

Det skal vær klikkbare elementer i rommet, tiden skal gå, en bok skal skrives og fremgangen på den skal vises i form av et meter som fylles opp. Behovene skal påvirke skriveprosessens hastighet og kvalitet. Etter at boken er ferdig vil spilleren få vite hvordan det gikk.

###Hva vi ønsker å oppnå:
Økonomi hvor man kan kjøpe boostere som påvirker behovsmetrene (f.eks. kaffe eller rødvin)
Kortsiktige mål og achievements når man oppfyller visse krav.

Spillet samler statistikk om ulike gameplay elementer og presentere den
Spilleren skal kunne lagre spillet(autosave). Laste et lagret spill og kunne avbryte et spill og begynne på nytt. 
Spillet skal kunne pauses og endre fart.

Vi legger til litt backstory - hvorfor er denne boken så viktig, hva har skjedd tidligere? Et mysterie kan introduseres og gir mere stemning i spillet.

###Hårete mål
*Denne listen består av elementer som vi ser på som ikke elementære for gameplay og/eller spesielt vanskelige*

Et script samler real time informasjon om været fra for eksempel yr.no. Dette vil ha en effekt på spillet i form av været som kan sees ut av vinduet og innspirasjonen til forfatteren. 
Minigames som for eksempel består av å drepe fluer ved å klikke på de. Minigames kan foregå i forskjellige rom eller utendørs.

Økonomi som et enda viktigere gameplayelement. Forfatteren får lønn av forlaget etter å ha sendt inn et vist antall sider, eller ved å gjøre andre skrivejobber. Pengene brukes til å betale regninger og kjøpe varer. Penger kan også brukes til oppdateringer slik som en bedre skrive skrivemaskin. Man kan gå konkurs - game over!

At man ikke bare skriver en bok, men mange bøker og målet blir å skrive bedre og bedre bøker og på den måten gjør det til et endless game.

Animasjoner, musikk og lydeffekter.
