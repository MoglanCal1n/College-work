#include <stdio.h>
#include "ui.h"

/**
5. Gestiune cont bancar

Creati o aplicatie care permite gestiunea tranzactiilor unui cont bancar.
O tranzactie are urmatoarele elemente: ziua (ziua din luna in care s-a efectuat tranzactia),
suma, tip (intrare/iesire), descriere.
Aplicatia permite:
a) adaugare de tranzactii
b) modificare tranzactie existenta
c) stergere  tranzactie existenta
d) Vizualizare tranzactii dupa un criteriu (tranzactii de un anumit tip, tranzactii cu suma mai mare/mai mica decat o suma data)
e) Vizualizare tranzactii ordonat dupa suma sau zi (crescator/descrescator)
 */
int main() {
    testAll();
    run();
    return 0;
}
