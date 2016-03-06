#ifndef NAMESPACES_HPP
#define NAMESPACES_HPP

/*
namespace writerInit{
    float MAXVALNEEDINIT=110;
    float MINVALNEEDINIT=-10;
}
namespace popUpMgrInit{
    const int MINTIMETONEXTEVENTINIT =1800; //30min
    const int TIMEBETWEENEVENTSSPANWIDTHINIT=12600; // 3.5time
}

namespace timeControllerInit{
    int UPDATEFREQMS=1000; // oppdateringsfrekvens i millisekunder. Hvor ofte skal det "tikkes" i vanlig tid. Senkes denne vil man få hyppigere oppdateringer, høyere FPS, men kan gå treigere
    int PAUSEINIT=0;
    int NORMALINIT=60; // Hvor mange sekunder skal hvert tikk legge til spillklokka
    int FASTERINIT=180;
    int FASTESTINIT=300;
    int ENDGAMEINIT=100; // denne verdien kan endres for å avgjøre etter hvor mange dager spillet skal ende
}
namespace booksettings{
    const int PAGEGOALINIT=350;
    const int WORDSPRPAGEINIT=250;
}
*/
namespace weather{

    enum inGameWeather{

        night, sunny, cloudy, raining
    };

    enum weatherReport{
        sol=1,
        lettskyet=2,
        delvisskyet=3,
        skyet=4,
        letteregnbyger = 40,
        regnbyger = 5,
        kraftigeregnbyger = 41,
        letteregnbygerogtorden = 24,
        regnbygerogtorden = 6,
        kraftigeregnbygerogtorden = 25,
        lettesluddbyger = 42,
        sluddbyger = 7,
        kraftigesluddbyger = 43,
        lettesluddbygerogtorden = 26,
        sluddbygerogtorden = 20,
        kraftigesluddbygerogtorden = 27,
        lettesnobyger = 44,
        snobyger = 8,
        kraftigesnobyger = 45,
        lettesnobygerogtorden = 28,
        snobygerogtorden = 21,
        kraftigesnobygerogtorden = 29,
        lettregn = 46,
        regn = 9,
        kraftigregn = 10,
        lettregnogtorden = 30,
        regnogtorden = 22,
        kraftigregnogtroden = 11,
        lettsludd = 12,
        kraftigsludd = 48,
        lettsluddogtorden =23,
        kraftigsluddogtorde =32,
        lettsno = 49,
        sno =13,
        kraftigsno = 50,
        lettsnoogtoden = 33,
        snoogtoden= 14,
        kraftigsnoogtorden=34,
        toke = 15
    };
}

#endif // NAMESPACES_HPP

