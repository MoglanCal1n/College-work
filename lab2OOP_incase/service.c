#include "service.h"
#include <string.h>

/**
 Functia adauga o noua tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
int adaugaTrans(List *l, char *descriere, int suma, char *tip, int zi){
    Trans t = create_transaction(descriere,suma,tip,zi);
    if (validate(t) == 0)
        return 0;
    add(l, t);
    return 1;
}
/**
 Functia sterge o tranzactie
 params:descriere - descrierea tranzactiei
        suma - suma tranzactiei
        tip - tipul tranzactiei, intrare/iesire
        zi - ziua din luna in care s-a efectuat tranzactia
        luna - luna in care s-a efectuat tranzactia
    return tranzactia cu caracteristicile de mai sus
 **/
int stergeTrans(List *l, char *descriere, int suma, char *tip, int zi){
    int poz;
    for (int i = 0; i < size(l); i++)
        if (strcmp(get(l,i).descriere, descriere) == 0 && strcmp(get(l,i).tip, tip) == 0
        && get(l,i).zi == zi && get(l, i).suma == suma){
            poz = i;
            delete(l, poz);
            return 1;
        }
    return 0;
}
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
int modifyTransServ(List *l, char *descriere, int suma, char *tip, int zi, char *new_descriere, int new_suma, char *new_tip, int new_zi){
    Trans c = create_transaction(new_descriere,new_suma,new_tip,new_zi);
    if (validate(c) == 0)
        return 0;

    int poz;
    for (int i = 0; i < size(l); i++)
        if (strcmp(get(l,i).descriere, descriere) == 0 && strcmp(get(l,i).tip, tip) == 0
            && get(l,i).zi == zi && get(l, i).suma == suma){
            poz = i;
            modifyTrans(l, c, poz);
            return 1;
        }
    return 0;
}
/**
 * functia de filtrare dupa tip
 * @param l - lista pe care o filtram
 * @param tip - tipul dupa care filtram
 * @return - lista filtrata
 */
List transCritTip(List *l, char *tip) {
    List lista_filtru = createEmpty();
    for (int i = 0; i < size(l); i++) {
        Trans t = get(l, i);
        if (strcmp(t.tip, tip) == 0)
            add(&lista_filtru, create_transaction(t.descriere, t.suma, t.tip, t.zi));
    }
    return lista_filtru;
}
/**
 * functia de filtrare dupa suma
 * @param l - lista in care filtram
 * @param suma - suma dupa care filtram
 * @param mod - 1 daca filtram sa fie mai mare decat suma ; 2 sa fie mai mic decat suma
 * @return - lista filtrata
 */
List transCritSuma(List *l, int suma, int mod){
    List lista_filtru = createEmpty();
    if (mod == 1)
        for (int i = 0; i < size(l); i++){
            Trans t = get(l, i);
            if (t.suma > suma)
                add(&lista_filtru, create_transaction(t.descriere, t.suma, t.tip, t.zi));
        }
    else if(mod == 2)
        for (int i = 0; i < size(l); i++){
            Trans t = get(l, i);
            if (t.suma < suma)
                add(&lista_filtru, create_transaction(t.descriere, t.suma, t.tip, t.zi));
        }

    return lista_filtru;
}

/**
 * Functia de sortare a listei dupa zi sau suma
 * @param l - lista pe care o sortam
 * @param suma - suma == -1 nu filtram dupa suma ; suma != -1 filtram dupa suma
 * @param zi - zi == -1 nu filtram dupa zi ; zi != -1 filtram dupa zi
 * @param mod - crescator sau descrescator
 */
void sort_zi_suma(List *l, int suma, int zi, int mod){
    int auxS, auxZ;
    char auxD[255], auxT[20];
    if (suma == -1 && mod == 1)
        for (int i = 0; i < size(l) - 1; i++)
            for (int j = i + 1; j < size(l); j++){
                if (l->elem[i].zi > l->elem[j].zi ){
                    auxZ = l->elem[i].zi;
                    auxS = l->elem[i].suma;
                    strcpy(auxD, l->elem[i].descriere);
                    strcpy(auxT, l->elem[i].tip);
                    l->elem[i].zi = l->elem[j].zi;
                    l->elem[i].suma = l->elem[j].suma;
                    strcpy(l->elem[i].tip, l->elem[j].tip);
                    strcpy(l->elem[i].descriere, l->elem[j].descriere);
                    l->elem[j].zi = auxZ;
                    l->elem[j].suma = auxS;
                    strcpy(l->elem[j].descriere, auxD);
                    strcpy(l->elem[j].tip, auxT);
                }
            }
    else if (suma == -1 && mod == 2)
        for (int i = 0; i < size(l) - 1; i++)
            for (int j = i + 1; j < size(l); j++){
                if (l->elem[i].zi < l->elem[j].zi ){
                    auxZ = l->elem[i].zi;
                    auxS = l->elem[i].suma;
                    strcpy(auxD, l->elem[i].descriere);
                    strcpy(auxT, l->elem[i].tip);
                    l->elem[i].zi = l->elem[j].zi;
                    l->elem[i].suma = l->elem[j].suma;
                    strcpy(l->elem[i].tip, l->elem[j].tip);
                    strcpy(l->elem[i].descriere, l->elem[j].descriere);
                    l->elem[j].zi = auxZ;
                    l->elem[j].suma = auxS;
                    strcpy(l->elem[j].descriere, auxD);
                    strcpy(l->elem[j].tip, auxT);
                }
            }
    else if (zi == -1 && mod == 1)
        for (int i = 0; i < size(l) - 1; i++)
            for (int j = i + 1; j < size(l); j++){
                if (l->elem[i].suma > l->elem[j].suma){
                    auxZ = l->elem[i].zi;
                    auxS = l->elem[i].suma;
                    strcpy(auxD, l->elem[i].descriere);
                    strcpy(auxT, l->elem[i].tip);
                    l->elem[i].zi = l->elem[j].zi;
                    l->elem[i].suma = l->elem[j].suma;
                    strcpy(l->elem[i].tip, l->elem[j].tip);
                    strcpy(l->elem[i].descriere, l->elem[j].descriere);
                    l->elem[j].zi = auxZ;
                    l->elem[j].suma = auxS;
                    strcpy(l->elem[j].descriere, auxD);
                    strcpy(l->elem[j].tip, auxT);
                }
            }
    else if (zi == -1 && mod == 2)
        for (int i = 0; i < size(l) - 1; i++)
            for (int j = i + 1; j < size(l); j++){
                if (l->elem[i].suma < l->elem[j].suma){
                    auxZ = l->elem[i].zi;
                    auxS = l->elem[i].suma;
                    strcpy(auxD, l->elem[i].descriere);
                    strcpy(auxT, l->elem[i].tip);
                    l->elem[i].zi = l->elem[j].zi;
                    l->elem[i].suma = l->elem[j].suma;
                    strcpy(l->elem[i].tip, l->elem[j].tip);
                    strcpy(l->elem[i].descriere, l->elem[j].descriere);
                    l->elem[j].zi = auxZ;
                    l->elem[j].suma = auxS;
                    strcpy(l->elem[j].descriere, auxD);
                    strcpy(l->elem[j].tip, auxT);
                }
            }
}
