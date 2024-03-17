//
// Created by Moglan Calin-Stefan on 3/13/24.
//

#ifndef LAB2OOP_INCASE_SERVICE_H
#define LAB2OOP_INCASE_SERVICE_H
#include "domain.h"
#include "repo.h"

/**
 Functia adauga o noua tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
int adaugaTrans(List *l, char *descriere, int suma, char *tip, int zi);

/**
 Functia sterge o tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
int stergeTrans(List *l, char *descriere, int suma, char *tip, int zi);

/**
 * Functia de modificare a unei tranzactii
 * @param l - lista in care modificam
 * @param descriere - descrierea tranzactiei pe care vrem sa o modificam
 * @param suma - suma tranzactiei pe care vrem sa o modificam
 * @param tip - tipul tranzactiei pe care vrem sa o modificam
 * @param zi - ziua tranzactiei pe care vrem sa o modificam
 * @param new_descriere - noua descriere a tranzactie
 * @param new_suma -noua suma a tranzactie
 * @param new_tip - noul tip al tranzactiei
 * @param new_zi - noua zi a tranzactie
 * @return 1 daca trannzactia a fost modificata cu succes ; 0 in caz contrar
 */
int modifyTransServ(List *l, char *descriere, int suma, char *tip, int zi, char *new_descriere, int new_suma, char *new_tip, int new_zi);

/**
 * functia de filtrare dupa tip
 * @param l - lista pe care o filtram
 * @param tip - tipul dupa care filtram
 * @return - lista filtrata
 */
List transCritTip(List *l, char *tip);

/**
 * functia de filtrare dupa suma
 * @param l - lista in care filtram
 * @param suma - suma dupa care filtram
 * @param mod - 1 daca filtram sa fie mai mare decat suma ; 2 sa fie mai mic decat suma
 * @return - lista filtrata
 */
List transCritSuma(List *l, int suma, int mod);

/**
 * Functia de sortare a listei dupa zi sau suma
 * @param l - lista pe care o sortam
 * @param suma - suma == -1 nu filtram dupa suma ; suma != -1 filtram dupa suma
 * @param zi - zi == -1 nu filtram dupa zi ; zi != -1 filtram dupa zi
 * @param mod - crescator sau descrescator
 */
void sort_zi_suma(List *l, int suma, int zi, int mod);

#endif //LAB2OOP_INCASE_SERVICE_H

