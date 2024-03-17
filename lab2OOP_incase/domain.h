//
// Created by Moglan Calin-Stefan on 3/13/24.
//

#ifndef LAB2OOP_INCASE_DOMAIN_H
#define LAB2OOP_INCASE_DOMAIN_H

typedef struct{
    int zi, suma;
    char descriere[255], tip[255];
}Trans;

/**
 Functia creaza un element de tip tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
Trans create_transaction(char* descriere, int suma, char* tip, int zi);

/**
 Functia valideaza un element de tip tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return 0, 1 in functie de validitatea tranzactiei
 **/
int validate(Trans t);

/**
 * Functia sterge un element de tip tranzactie
 * params: t - tranzactia de sters
 **/
void delete_transaction(Trans *t);

/**
 * Functia modifica o tranzactie
 *
 * params: t - tranzactia pe care o modificam
 *         c - tranzactia cu care o inlocui
 **/
void modify_transaction(Trans *t, Trans *c);

#endif //LAB2OOP_INCASE_DOMAIN_H
