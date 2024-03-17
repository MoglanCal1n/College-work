#include "domain.h"
#include <string.h>


/**
 Functia creaza un element de tip tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
Trans create_transaction(char *descriere, int suma, char *tip, int zi){
    Trans t;
    t.suma = suma;
    t.zi = zi;
    strcpy(t.descriere, descriere);
    strcpy(t.tip, tip);

    return t;
}


/**
 Functia valideaza un element de tip tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return 0, 1 in functie de validitatea tranzactiei
 **/
int validate(Trans t){
    char tipV[255];
    strcpy(tipV, t.tip);
    if ((strcmp(tipV, "intrare") != 0) && (strcmp(tipV, "iesire") != 0))
        return 0;
    if (t.suma <= 0)
        return 0;
    if (t.zi < 1 || t.zi > 31)
        return 0;

    return 1;
}


/**
 * Functia sterge un element de tip tranzactie
 * params: t - tranzactia de sters
 **/
void delete_transaction(Trans *t){
    t -> zi = 0;
    t -> suma = 0;
    t -> descriere[0] = '\0';
    t -> tip[0] = '\0';
}

/**
 * Functia modifica o tranzactie
 *
 * params: t - tranzactia pe care o modificam
 *         c - tranzactia cu care o inlocui
 **/
void modify_transaction(Trans *t, Trans *c){
    t->zi = c->zi;
    t->suma = c->suma;
    strcpy(t->descriere, c->descriere);
    strcpy(t->tip, c->tip);
}