#pragma once
#include "LocatarService.h"

class LocatarUI {
private:
    LocatarService& serv;
public:
    /**
     * Constructor pentru clasa LocatarUI
     * @param serv LocatarService
     */
    LocatarUI(LocatarService& serv): serv{serv}{}

    /**
     * functie care adauga un nou locatar valid in bloc
     * in cazul in care locatarul nu este valid se afiseaza mesajul de eroare
     */
    void uiAdd();

    /**
     * Functie care afiseaza toti locatarii din bloc
     */
    void uiPrint();

    /**
     * Functie care modifica un locatar
     */
    void uiModify();

    /**
     * Functie care sterge un locatar
     */
    void uiDelete();

    /**
     * Functie care cauta un locatar
     */
    void uiCauta();

    /**
     * Functie care filtreaza locatarii dupa tip
     */
    void uiFilterTip();

    /**
     * Functie care filtreaza locatarii dupa suprafata
     */
    void uiFilterSuprafata();


    /**
     * functia care incepe programul si permite interactiunea intre aplicatie si utilizator
     */
    void run();
};

/**
 * Functie care afiseaza meniul cu optiunile de comenzi pe care le are utilizatorul
 */
void menu();

