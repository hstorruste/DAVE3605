##4)Kortsvarspørsmål

1.  Når animated har et protected datamedlem vil det si at den er tilgjengelig ikke bare av den klassen,
    men også av de som arver denne klassen.
2. 
3.
4.
5.  Klassen has_color burde nok hatt en virituell destruktor, siden den har en virituell funksjon. Skulle man ønske å bruke en      has_color peker til å holde en et objekt av "My_class" som arver has_color og deretter sletter denne pekeren, så vil            destruktoren i My_class kalles og man vil få memory-leaks hvis man har allokert minne med new i My_class. Det er heller ikke     opplagt at man skal bruke red_, green_ og blue_ til å peke på de tre første bytene i color_. Man kan også løse dette ved å      bruke new og deretter Fl::get_color(Fl_Color i, uchar& red, uchar& green, uchar& blue) for å sette r,g,b. Men dette vil også     kreve at man har en destruktor til å destruere r,g,b.
