#include "repo.h"

/*
 * Creem o lista vida pt tranzactii
 *
 * return: List - lista vida
 */
List createEmpty(){
    List l;
    l.len = 0;
    return l;
}

/*
 * Distruge o lista
 *
 * Params: -l: adresa listei de distrus(List*)
 */
void destroy(List* l){
    l -> len = 0;
}
/*
 * adauga un element la sfarsitul listei
 *
 * params: - l lista in care se adauga elementul
 *         -el elementul care se adauga
 */
void add(List *l, TElem el){
    l -> elem[l -> len] = el;
    l -> len++;
}
/*
 * adauga un element pe o pozitie in lista
 *
 * params: - l lista in care se adauga elementul
 *         -el elementul care se adauga
 *         -poz pozitia pe care se adauga
 */
void addTrans(List *l, TElem el, int poz){
    l -> elem[poz] = el;
}

/**
* functia modifica o tranzactie cu o alta
*
* @param l - lista in care modificam tranzactia
* @param el - elementul cu care o inlocuim
* @param new_el - elementul cu care inlocuim
**/
void modifyTrans(List *l, TElem el, int poz){
    l -> elem[poz] = el;
}
/*
 * sterge un element din lista de pe o pozitie specificata
 *
 * params: l lista din care se sterge
 *         poz pozitia de pe care se sterge
 *
 * return TElem - elementul sters
 */
TElem delete(List *l, int poz){
    TElem el = l -> elem[poz];
    for (int i = poz; i < l -> len - 1; i++)
        l -> elem[i] = l -> elem[i+1];
    l -> len--;
    return el;
}
/*
 * returneaza un element din lista de pe o pozitie specificata
 *
 * params: l lista din care se extrage
 *         poz pozitia de pe care se extrage
 *
 * return TElem - elementul extras
 */
TElem get(List *l, int poz){
    return l->elem[poz];
}

/*
dz * returneaza marimea listei
 *
 * params: l - lista careia ii gasim dimensiunea
 *
 * return: int - nr de elem din lista
 */
int size(List *l){
    return l -> len;
}