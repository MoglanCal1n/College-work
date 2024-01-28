#include <stdio.h>
#include <string.h>


struct Date { // structura in care memoram datele calendaristice pe  care le vom folosi la tranzactiile noastre
    int day; // ziua de tip int
    int month; // luna  de tip int
    int year; // anul de tip int
};

struct Transaction { // structura pe care o vom folosi pentru a memora datele necesare pentru aplicatia de tip banca
    struct Date date; // structura de date calendaristice
    float amount; // in amount vom retine veniturile si cheltuielile 
    char description[255]; // in description memoram descrierile tranzactiilor
    int type; // cu ajutorul variabilei type ne vom da seama daca o tranzactie este de tip income sau expense
};

FILE *f_input; // cu ajutorul lui f_input vom memora si citi din fisier datele bancare
struct Transaction v[255]; // in "v" vom memora toate datele tranzactiilor
int n, zistart, zistop, lunastart, lunastop, anstart, anstop; 

void clear_input_buffer() { // Această funcție este folosită pentru a asigura că buffer-ul de intrare 
    int c;                 //este gol și nu conține caractere nedorite înainte de a citi inputul utilizatorului
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_new_transaction() {  // aceasta functie adauga o tranzactie noua. in acelasi timp valideaza si datele de intrate
    f_input = fopen("bank.txt", "a"); // deschidem fisierul bank.txt cu functia "a" de append
    struct Transaction trs; // initializam variabila trs de tipul structurei noastre pentru a ne ajuta la citiri

    int ziua_valida;
    do{                                                       // in aceasta parte a codului citim si validam toate datele de intrare ale tranzactiei noastre curente  
    printf("Citeste ziua tranzactiei(1 - 31): ");            // pentru a face asta ne folosim de un do while in care verificam daca variabila noastra este de tipul dorit       
    ziua_valida = scanf("%d", &trs.date.day);               // precum int sau float si mai mult decat atat verificam parametrii in care ar trebui sa se afle
    if(!ziua_valida || trs.date.day < 1 || trs.date.day > 31){  // in exemplul dat daca ziua careia ii dam input este mai mare de 31 sau mai mica decat 1 
        printf("Ziua introdusa nu este valida. Reintroduceti ziua intre 1 si 31.\n");  // codul nostru va afisa un mesaj de eroare punand utilizatorul sa reintroduca
        clear_input_buffer();                                                         // datele. acest lucru se intampla pentru toate datele pe care le   
        }                                                                            // introduce utilizatorul 
    }while(!ziua_valida || trs.date.day < 1 || trs.date.day > 31);
    fprintf(f_input, "%d\n", trs.date.day);

    int luna_valida;
    do{
    printf("Citeste luna tranzactiei(1 - 12): ");
    luna_valida = scanf("%d", &trs.date.month); 
    if(!luna_valida || trs.date.month < 1 || trs.date.month > 12){
        printf("Luna introdusa nu este valida. Reintroduceti luna intre 1 si 12.\n");
        clear_input_buffer();
        }
    }while(!luna_valida || trs.date.month < 1 || trs.date.month > 12);
    fprintf(f_input, "%d\n", trs.date.month);
    
    int an_valid; 
    do{
    printf("Citeste anul tranzactiei(2021 - 2023): ");
    an_valid = scanf("%d", &trs.date.year);
    if(!an_valid || trs.date.year < 2021 || trs.date.year > 2023){
        printf("Anul introdus nu este valid. Reintroduceti anul intre 2021 si 2023\n");
        clear_input_buffer();
    }
    }while(!an_valid || trs.date.year < 2021 || trs.date.year > 2023);
    fprintf(f_input, "%d\n", trs.date.year);

    float suma_valida;                              // aceasta parte a codului citeste si validaza suma tranzactiei
    do {                                            // suma este de tip float pentru tranzactii subunitare
        printf("Citeste suma: ");
        suma_valida = scanf("%f", &trs.amount);
        if (!suma_valida) {
            printf("Suma introdusa nu este valida. Reintroduceti suma.\n");
            clear_input_buffer(); // Consuma caracterele rămase în buffer
        }
    } while (!suma_valida);
    fprintf(f_input,"%.2f\n", trs.amount);

    printf("Citeste descrierea (maxim 255 de caractere): ");  // aceasta parte a codului citeste descrierea tranzactiei
    clear_input_buffer();                                     // se pot citi si propozitii mai lungi nu doar cuvinte
    scanf("%[^\n]%*c", trs.description);
    fprintf(f_input, "%s\n", trs.description);

    int tip_valid;
    do{
    printf("Citeste tipul (0 pentru Income, 1 pentru Expense): "); // aici se citeste si valideaza tipul tranzactiei
    tip_valid = scanf("%d", &trs.type);
    if(!tip_valid || (trs.type != 0 && trs.type != 1)){
            printf("Tipul pe care l-ati introdus nu este valid. Reintroduceti tipul.\n");
            clear_input_buffer();
    }
    }while(!tip_valid || (trs.type != 0 && trs.type != 1));
    fprintf(f_input, "%d\n", trs.type);

    fclose(f_input); // inchidem fisierul nostru 
}

void elem_in_array() { // aceasta functie adauga valorile citite si adaugate in fisierul txt
    int finput;       // in vectorul de tip struct pentru a putea fi folosite pentru functionalitatile noastre ulterior
    char finputs[255] = {};
    f_input = fopen("bank.txt", "r"); // deschidem fisierul in modul "r" - read
    int i = 0;
    while (fscanf(f_input, "%d %d %d %f %[^\n] %d", 
                  &v[i].date.day, &v[i].date.month, &v[i].date.year,
                  &v[i].amount, v[i].description, &v[i].type) != EOF) {
        i++;
    }
    fclose(f_input); // inchidem fisierul
    n = i; // in variabila n pastram si numarul de tranzactii pe care le avem salvate in fisier
}

void display_transactions() { // aceasta functie afiseaza tranzactiile efectuate de utilizator
    for (int i = 0; i < n; i++) {
        printf("Ziua: %d\n", v[i].date.day);
        printf("Luna: %d\n", v[i].date.month);
        printf("Anul: %d\n", v[i].date.year);
        printf("Suma: %.2f\n", v[i].amount);
        printf("Descrierea: %s\n", v[i].description);
        printf("Tipul: %s\n\n", (v[i].type == 0) ? "Income" : "Expense");
    }
}

float calculte_account_balance(int n) // aceasta functie calculeza soldul contului 
{   
    float acc_bal = 0, acc_inc = 0, acc_exp = 0; // am declarat trei variabile de tip float
    for(int i = 0; i < n; i++)                  // in acc_bal calcumal soldul total. in acc_exp calculam soldul cheltuielilor. in acc_inc calculam soldul veniturilor 
        if(v[i].type == 1) // in caz de v[i].type este de tip expense
            acc_exp += v[i].amount; // adunam in acc_exp
        else
            acc_inc += v[i].amount; // in caz contrar adunam la acc_inc
    acc_bal = acc_inc - acc_exp; // la final calculam soldul contului prin a scadea din venituri cheltuielile
    return acc_bal;
}


float summary_income(int n) // aceasta functie calculeaza un rezumat al veniturilor intr-un interval de timp dat
{
    float summary = 0;
    for(int i = 0; i < n; i++)
        if(v[i].type == 0) // se verifica daca elementul de pe pozitia v[i].type este de tim income adica 0
           if (v[i].date.year > anstart && v[i].date.year < anstop) // comparam cu anii de start si stop
                summary += v[i].amount; // daca conditia din if este adevarata adunam la summary valoarea tranzactiei din v[i].amount
            else if (v[i].date.year == anstart && v[i].date.month > lunastart) // daca conditia din if este adevarata adunam la summary valoarea tranzactiei din v[i].amount
                summary += v[i].amount; // daca conditia din if este adevarata adunam la summary valoarea tranzactiei in v[i].amount
            else if (v[i].date.year == anstart && v[i].date.month == lunastart && v[i].date.day > zistart)
                summary += v[i].amount; // daca anii si lunile de start sunt egale cu datele din tranzactie verificam ziua de start
            else if (v[i].date.year == anstop && v[i].date.month < lunastop) // daca anul de stop este egal cu anul tranzactiei comparam cu luna de stop
                summary += v[i].amount;
            else if (v[i].date.year == anstop && v[i].date.month == lunastop && v[i].date.day < zistop) // daca anul si luna de stop sunt egale cu datele tranzactiei comparam cu ziua de stop 
                summary += v[i].amount;

    return summary;
}
float summary_expense(int n) // aceasta functie calculeaza un rezumat al cheltuielilor intr-un interval de timp dat
{
    float summary = 0;   
    for(int i = 0; i < n; i++) 
        if(v[i].type == 1) // se verifica daca elementul de pe pozitia v[i].type este de tip expense adica 1 
            if (v[i].date.year > anstart && v[i].date.year < anstop) // comparam cu anii de start si stop
                summary += v[i].amount; // daca conditia din if este adevarata adunam la summary valoarea tranzactiei din v[i].amount
            else if (v[i].date.year == anstart && v[i].date.month > lunastart) // daca anul de start este egal cu anul tranzactiei comparam cu luna de start 
                summary += v[i].amount; // daca conditia din if este adevarata adunam la summary valoarea tranzactiei in v[i].amount
            else if (v[i].date.year == anstart && v[i].date.month == lunastart && v[i].date.day > zistart) 
                summary += v[i].amount; // daca anii si lunile de start sunt egale cu datele din tranzactie verificam ziua de start
            else if (v[i].date.year == anstop && v[i].date.month < lunastop) // daca anul de stop este egal cu anul tranzactiei comparam cu luna de stop 
                summary += v[i].amount;
            else if (v[i].date.year == anstop && v[i].date.month == lunastop && v[i].date.day < zistop) // daca anul si luna de stop sunt egale cu datele tranzactiei comparam cu ziua de stop 
                summary += v[i].amount;

    return summary;
}

int main(){
    int choose; 
    elem_in_array(); // inainte de a incepe prelucrearea datelor le introducem in vectorul nostru de tip structura cu ajutorul acestei functii

    while (1) {
        printf("WELCOME TO OUR BANKING APP\n"); // aceasta parte contine un UI pentru interactiunea cu uitlizatorul 
        printf("MAIN - MENU\n");                
        printf("Choose an option:\n");  
        printf("1. Adaugare tranzactie noua!\n");
        printf("2. Afiseaza tranzactiile anterioare\n");
        printf("3. Calculeaza soldul contului\n");
        printf("4. Afiseaza raport financiar\n");
        printf("5. Iesire din aplicatie\n");

        do {                   // cu ajutorul lui "choose" utilizatorul alege functionalitatea pe care o alege. aici noi o validam 
            printf("Care este functia pe care doriti sa o folositi? = ");
            if (scanf("%d", &choose) != 1) {
                printf("Functia introdusa nu este valida. Reintroduceti functia.\n");
                clear_input_buffer();
                choose = 0; // in cazul in care choose este invalid il resetam pentru a ramane in bucla while
            }
        } while (choose < 1 || choose > 5); // in cazul in care utilizatorul introduce un numar care nu se afla in lista din meniu
                                           // programul se intoarce la meniul principal
        if (choose == 1) {  // aici apelam funtia de adaugare tranzactie noua
            printf("Ati ales functia de adaugare tranzactie noua!!!\n\n");
            add_new_transaction(); 
            elem_in_array();
        } else if (choose == 2) { // aici se apeleaza functia de afisare a tranzactiilor
            display_transactions();
        }
        else if (choose == 3){ // aici se afiseaza soldul contului
            float afis = calculte_account_balance(n);
            printf("%.2f\n", afis);
        
        } else if (choose == 4) {  // aici se apeleaza functia de rezumat a veniturilor si a cheltuielilor
            int zistart_valida;   // in acelasi timp citim intervalul de timp de unde incepem si pana unde facem rezumatul
            do{                  // mai mult decat atat validam si aceste date 
                printf("Citeste ziua de start(1 - 31): ");
                zistart_valida = scanf("%d", &zistart); 
                if(!zistart_valida || zistart < 1 || zistart > 31){
                    printf("Ziua introdusa nu este valida. Reintroduceti ziua intre 1 si 31.\n");
                    clear_input_buffer();
                }
            }while(!zistart_valida || zistart < 1 || zistart > 31);
            int lunastart_valida; // se citeste si se valideaza luna la care incepe rezumatul
            do{
                printf("Citeste luna de start(1 - 12): ");
                lunastart_valida = scanf("%d", &lunastart); 
                if(!lunastart_valida || lunastart < 1 || lunastart > 12){
                    printf("Luna introdusa nu este valida. Reintroduceti luna.\n");
                    clear_input_buffer();
                }
            }while(!lunastart_valida || lunastart < 1 || lunastart > 12);
            int anstart_valida; // se citeste si se valideaza anul de la care incepe rezumatul  
            do{
                printf("Citeste anul de start(2021 - 2023): ");
                anstart_valida = scanf("%d", &anstart); 
                if(!anstart_valida || anstart < 2021 || anstart > 2023){
                    printf("Anul introdus nu este valid. Reintroduceti anul.\n");
                    clear_input_buffer();
                }
            }while(!anstart_valida || anstart < 2021 || anstart > 2023);
                printf("Start Date: %d-%d-%d\n", zistart, lunastart, anstart);
            printf("Citeste datele de stop\n");    
            int zistop_valida; // se citeste si se valideaza ziua la care se opreste rezumatul
            do{
                printf("Citeste ziua de stop(1 - 31): ");
                zistop_valida = scanf("%d", &zistop); 
                if(!zistop_valida || zistop < 1 || zistop > 31){
                    printf("Ziua introdusa nu este valida. Reintroduceti ziua intre 1 si 31.\n");
                    clear_input_buffer();
                }
            }while(!zistop_valida || zistop < 1 || zistop > 31);
            int lunastop_valida; // se citeste si se valideaza luna la care se opreste rezumatul
            do{
                printf("Citeste luna de stop(1 - 12): ");
                lunastop_valida = scanf("%d", &lunastop); 
                if(!lunastop_valida || lunastop < 1 || lunastop > 12){
                    printf("Luna introdusa nu este valida. Reintroduceti luna.\n");
                    clear_input_buffer();
                }
            }while(!lunastop_valida || lunastop < 1 || lunastop > 12);
            int anstop_valida; // se citeste si se valideaza anul la care se opreste rezumatul 
            do{
                printf("Citeste anul de stop(2021 - 2023): ");
                anstop_valida = scanf("%d", &anstop); 
                if(!anstop_valida || anstop < 2021 || anstop > 2023){
                    printf("Anul introdus nu este valid. Reintroduceti anul.\n");
                    clear_input_buffer();
                }
            }while(!anstop_valida || anstop < 2021 || anstop > 2023);
                printf("Stop Date: %d-%d-%d\n", zistop, lunastop, anstop);
            printf("Rezumatul incasarilor este = \n");
            float afis = summary_income(n);  // afisam rezumatul veniturilor
            printf("%.2f\n", afis);
            printf("Rezumatul cheltuielilor este = \n");
            afis = summary_expense(n); // afisam rezumatul cheltuielilor
            printf("%.2f\n", afis);
        } else if(choose == 5){ // in cazul in care utilizatorul apeleaza functia 5, iesim din while cu break si programul se incheie
             printf("Thank you for using me :)");
             break;
        }
    }

    return 0;
}