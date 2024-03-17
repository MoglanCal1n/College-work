#include <stdio.h>
#include "ui.h"
#include "tests.h"

/**
 functie care ruleaza toate testele
 **/
void testAll(){
    printf("Incepe rularea testelor...\n");
    test_creazaTrans();

    test_destroyTrans();

    test_valid();

    test_AddGet();

    test_destroy();

    test_add();

    test_addTrans();

    test_addTransService();

    test_deleteTransService();

    test_create_empty();

    test_delete();

    test_size();

    test_modifyDomain();

    test_modifyRepo();

    test_modifyServ();

    test_critTip();

    test_critSuma();

    test_Sort();

    printf("\nTestele au rulat cu succes\n");
}

/**
 * functia de adaugare tranzactie din ui. cere utilizatorului datele de intrare
 *
 *  params: l - lsta de tranzactii in care se adauga
 */
void uiAdd(List *l){
    printf("Adauga tranzactie: \n");
    char descriere[255], tip[255];
    int suma, zi;
    printf("Introduceti ziua: \n");
    scanf("%d", &zi);
    printf("Introduceti suma: \n");
    scanf("%d", &suma);
    printf("Introduceti descrierea: \n");
    scanf("%s", descriere);
    printf("Introduceti tipul: \n");
    scanf("%s", tip);

    int valid = adaugaTrans(l, descriere, suma, tip, zi);
    if (valid == 1)
        printf("Tranzactie adaugata cu succes\n");
    else
        printf("A aparut o eroare. Mai incercati odata\n");
}
/**
 * functia de stergere a unei tranzactii. cere utilizatorului datele de intrare
 * @param l - lista de tranzactii din care stergem
 */
void uiDelete(List *l){
    printf("Adauga tranzactie pentru stergere: \n");
    char descriere[255], tip[255];
    int suma, zi;
    printf("Introduceti ziua: \n");
    scanf("%d", &zi);
    printf("Introduceti suma: \n");
    scanf("%d", &suma);
    printf("Introduceti descrierea: \n");
    scanf("%s", descriere);
    printf("Introduceti tipul: \n");
    scanf("%s", tip);

    int valid = stergeTrans(l, descriere, suma, tip, zi);

    if (valid == 1)
        printf("Tranzactie stearsa cu succes\n");
    else
        printf("A aparut o eroare. Mai incercati odata\n");
}

/**
 * Functia de modificare a unei tranzactii
 * @param l - lista in care modificam o tranzactie
 */
void uiModify(List *l){
    printf("Adauga datele tranzactiei pe care vrei sa o modifici: \n");
    char descriere[255], new_descriere[255], tip[255], new_tip[255];
    int suma, new_suma ,zi, new_zi;
    printf("Introduceti ziua: \n");
    scanf("%d", &zi);
    printf("Introduceti suma: \n");
    scanf("%d", &suma);
    printf("Introduceti descrierea: \n");
    scanf("%s", descriere);
    printf("Introduceti tipul: \n");
    scanf("%s", tip);
    printf("Adauga datele noi ale tranzactiei: \n");
    printf("Introduceti ziua: \n");
    scanf("%d", &new_zi);
    printf("Introduceti suma: \n");
    scanf("%d", &new_suma);
    printf("Introduceti descrierea: \n");
    scanf("%s", new_descriere);
    printf("Introduceti tipul: \n");
    scanf("%s", new_tip);

    int valid = modifyTransServ(l,descriere, suma, tip, zi, new_descriere, new_suma, new_tip, new_zi);

    if (valid == 1)
        printf("Tranzactia a fost modificata cu succes\n");
    else
        printf("A aparut o eroare. Mai incercati odata\n");
}
/**
 * Functia de filtrare dupa tip
 * @param l - lista in care filtram
 */
void uiTransCritTip(List *l){
    char srt[10];
    printf("Introduceti tipul dupa care doriti sa filtram!\n");
    scanf("%s", srt);
    List lista_filtru = transCritTip(l, srt);
    if (size(&lista_filtru) == 0)
        printf("A aparut o eroare!\n");
    else
        getAll(&lista_filtru);
}

/**
 *  Functia de filtrare dupa suma
 * @param l - lista in care filtram
 */
void uiTransCritSuma(List *l){
    int suma, mod;
    printf("Introduceti suma cu care doriti sa comparam: \n");
    scanf("%d", &suma);
    printf("Introduceti 1 pentru mai mare decat suma sau 2 pentru mai mic decat suma: \n");
    scanf("%d", &mod);

    List lista_filtru = transCritSuma(l, suma, mod);

    if (size(&lista_filtru) == 0)
        printf("A aparut o eroare!\n");
    else
        getAll(&lista_filtru);

}

/**
 *  Functia de sortare a listei
 * @param l - lista pe care o sortam
 */
void uiSort(List *l){
    int suma = -1, zi = -1, mod, sort;
    printf("Alege dupa ce se face sortarea: 1 - suma ; 2 - zi\n");
    scanf("%d", &sort);
    printf("Alege cum se face sortarea: 1 - crescator ; 2 - descrescator\n");
    scanf("%d", &mod);
    if (mod < 1 || mod > 2)
        printf("A aparut o eroare!\n");
    else if (sort == 1){
        suma = 1;
        sort_zi_suma(l, suma, zi, mod);
    }
    else if (sort == 2){
        zi = 1;
        sort_zi_suma(l, suma, zi, mod);
    }

    getAll(l);
}
/**
 *
 * functie care afiseaza toate tranzactiile din lista
 * @param l - lista de tranzactii
 */
void getAll(List *l){
    for (int i = 0; i < size(l); i++){
        Trans t = get(l, i);
        printf("Tip %s, Descriere %s, Suma %d, Zi %d\n", t.tip, t.descriere, t.suma,t.zi);
    }
}

/**
 * Functie care afiseaza optiunile pe care le poate alege utilizatorul in aplicatie
 */
void menu(){
    printf("1. Adauga tranzactie\n");
    printf("2. Sterge tranzactie\n");
    printf("3. Afisare tranzactii\n");
    printf("4. Modificare tranzactie\n");
    printf("5. Filtrare dupa tip\n");
    printf("6. Filtrare dupa suma\n");
    printf("7. Sortare\n");
    printf("8. Iesire aplicatie\n");
}

/**
 * functie care porneste executia aplicatiei
 */
void run(){
    List l = createEmpty();
    int option, ok = 1;
    printf("Bine ati venit!\n");

    while(ok){
        menu();
        printf("Alege optiunea: \n");
        scanf("%d", &option);
        switch (option){
            case 1:
                uiAdd(&l);
                break;
            case 2:
                uiDelete(&l);
                break;
            case 3:
                getAll(&l);
                break;
            case 4:
                uiModify(&l);
                break;
            case 5:
                uiTransCritTip(&l);
                break;
            case 6:
                uiTransCritSuma(&l);
                break;
            case 7:
                uiSort(&l);
                break;
            case 8:
                printf("Bye traveler\n");
                ok = 0;
                break;
            default:
                printf("Comanda gresita\n");
                break;

        }
    }
}
