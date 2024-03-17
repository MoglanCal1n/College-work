#ifndef LAB2OOP_INCASE_REPO_H
#define LAB2OOP_INCASE_REPO_H

#include "domain.h"
#include <string.h>

typedef Trans TElem;

typedef struct{
    TElem elem[100];
    int len;
}List;

/**
 * Creem o lista vida pt tranzactii
 *
 * return: List - lista vida
 **/
List createEmpty();


/**
 * Distruge o lista
 *
 * Params: -l: adresa listei de distrus(List*)
 **/
void destroy(List* l);

/**
 * adauga un element la sfarsitul listei
 *
 * params: - l lista in care se adauga elementul
 *         -el elementul care se adauga
 **/
void add(List *l, TElem);

/**
 * adauga un element pe o pozitie in lista
 *
 * params: - l lista in care se adauga elementul
 *         -el elementul care se adauga
 *         -poz pozitia pe care se adauga
 **/
void addTrans(List *l, TElem el, int poz);

/**
 * sterge un element din lista de pe o pozitie specificata
 *
 * params: l lista din care se sterge
 *         poz pozitia de pe care se sterge
 *
 * return TElem - elementul sters
 **/
TElem delete(List *l, int poz);

/**
 * returneaza un element din lista de pe o pozitie specificata
 *
 * params: l lista din care se extrage
 *         poz pozitia de pe care se extrage
 *
 * return TElem - elementul extras
 **/
TElem get(List *l, int poz);

/**
 * returneaza marimea listei
 *
 * params: l - lista careia ii gasim dimensiunea
 *
 * return: int - nr de elem din lista
 **/
int size(List *l);

/**
 * functia modifica o tranzactie cu o alta
 *
 * @param l - lista in care modificam tranzactia
 * @param el - elementul cu care o inlocuim
 * @param new_el - elementul cu care inlocuim
 */
void modifyTrans(List *l, TElem el, int poz);



#endif //LAB2OOP_INCASE_REPO_H

