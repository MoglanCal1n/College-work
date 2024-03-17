

#ifndef LAB2OOP_INCASE_UI_H
#define LAB2OOP_INCASE_UI_H
#include "service.h"
/**
 functie care ruleaza toate testele
 **/
void testAll();
/**
 * functia de adaugare tranzactie din ui. cere utilizatorului datele de intrare
 *
 *  params: l - lsta de tranzactii in care se adauga
 */
void uiAdd(List *l);
/**
 * functia de stergere a unei tranzactii. cere utilizatorului datele de intrare
 * @param l - lista de tranzactii din care stergem
 */
void uiDelete(List *l);

/**
 * Functia de modificare a unei tranzactii
 * @param l - lista in care modificam o tranzactie
 */
void uiModify(List *l);

/**
 * Functia de filtrare dupa tip
 * @param l - lista in care filtram
 */
void uiTransCritTip(List *l);

/**
 *  Functia de filtrare dupa suma
 * @param l - lista in care filtram
 */
void uiTransCritSuma(List *l);

/**
 *  Functia de sortare a listei
 * @param l - lista pe care o sortam
 */
void uiSort(List *l);

/**
 *
 * functie care afiseaza toate tranzactiile din lista
 * @param l - lista de tranzactii
 */
void getAll(List *l);

/**
 * Functie care afiseaza optiunile pe care le poate alege utilizatorul in aplicatie
 */
void menu();

/**
 * functie care porneste executia aplicatiei
 */
void run();
#endif //LAB2OOP_INCASE_UI_H

