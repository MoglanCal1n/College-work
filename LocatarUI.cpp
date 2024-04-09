#include "LocatarUI.h"
#include <iostream>
using std::cin;
using std::cout;

void menu(){
    cout<<"-------Lista optiuni manager locatari-------\n";
    cout<<"0. Exit\n";
    cout<<"1. Add\n";
    cout<<"2. Print\n";
    cout<<"3. Modify\n";
    cout<<"4. Delete\n";
    cout<<"5. Find\n";
    cout<<"6. Filter Type\n";
    cout<<"7. Filter Surface\n";
    cout<<"--------------------------------------------\n";
}

void LocatarUI::uiAdd() {
    string numeProprietar;
    string tipApartament;
    int apartament = 0, suprafata = 0;
    cout << "Introdu numele proprietarului: \n";
    cin >> numeProprietar;
    cout << "Introdu tipul apartamentului: \n";
    cin >> tipApartament;
    cout << "Introdu numarul apartamentului: \n";
    cin >> apartament;
    cout << "Introdu suprafata apartamentului: \n";
    cin >> suprafata;
    try {
        serv.add(numeProprietar, tipApartament, apartament, suprafata);
        cout<<"--------------------------------------------\n";
        cout << "Locatar adaugat cu succes!\n";
        cout<<"--------------------------------------------\n";
    }
    catch (RepoException & ex){
        cout<<ex.get_msg();
    }
}

void LocatarUI::uiModify() {
    int app = 0;

    string numeProprietar;
    string tipApartament;
    int suprafata = 0;


    cout<<"Introduceti numarul apartamentului ai carui date doriti sa le modificati:\n";
    cin>>app;

    cout << "Introdu noul nume al proprietarului: \n";
    cin >> numeProprietar;
    cout << "Introdu noul  tip al apartamentului: \n";
    cin >> tipApartament;
    cout << "Introdu noua suprafata a apartamentului: \n";
    cin >> suprafata;

    try{
        serv.modify(app, numeProprietar, tipApartament, suprafata);
        cout<<"--------------------------------------------\n";
        cout << "Locatar modificat cu succes!\n";
        cout<<"--------------------------------------------\n";
    }catch (RepoException& e){
        cout<<e.get_msg();
    }
}


void LocatarUI::uiDelete() {
    int app = 0;

    cout<<"Introduceti numarul apartamentului ai carui date doriti sa le stergeti:\n";
    cin>>app;

    try {
        serv.deleteL(app);
        cout<<"--------------------------------------------\n";
        cout << "Locatar sters cu succes!\n";
        cout<<"--------------------------------------------\n";
    }catch (RepoException& e){
        cout << e.get_msg();
    }
}

void LocatarUI::uiCauta() {
    int app = 0;

    cout<<"Introduceti numarul apartamentului pe care doriti sa il cautati:\n";
    cin>>app;

    if (serv.cauta(app)) {
        int i = 0;
        vector<Locatar> loc = serv.getAll();

        for (const Locatar &l: loc) {
            i++;
            if (l.get_apartament() == app){
                cout<<"--------------------------------------------\n";
                cout << "Inregistrarea nr: " << i << "\nProprietar apartament " << l.get_numeProprietar()
                     << "\nTip apartament "
                     << l.get_tipApartament() << "\nNumar apartament " << l.get_apartament() << "\nSuprafata apartament "
                     << l.get_suprafata() << "\n\n";
                cout<<"--------------------------------------------\n";
                break;
            }
        }
    }
    else{
        cout<<"--------------------------------------------\n";
        cout << "Apartamentul introdus nu exsta in baza de date!\n";
        cout<<"--------------------------------------------\n";
    }
}

void LocatarUI::uiFilterTip() {
    string tip;

    cout<<"Introduceti tipul dupa care sortam:\n";
    cin>>tip;

    vector<Locatar> filtru = serv.filterTip(tip);

    if (filtru.empty()){
        cout<<"--------------------------------------------\n";
        cout << "Nu exista inregistrari cu acest tip!\n";
        cout<<"--------------------------------------------\n";
    }
    else{
        int i = 0;
        cout<<"---------------Lista Filtrata---------------\n";
        for (const Locatar& l : filtru) {
            i++;
            cout<<"Inregistrarea filtrata nr: " << i << "\nProprietar apartament " << l.get_numeProprietar() << "\nTip apartament "
                << l.get_tipApartament()<< "\nNumar apartament " << l.get_apartament() << "\nSuprafata apartament " << l.get_suprafata()<< "\n\n";
        }
        cout<<"--------------------------------------------\n";
    }
}

void LocatarUI::uiFilterSuprafata() {
    int suprafata = 0, mod = 0;
    cout<<"--------------------------------------------\n";
    cout << "Introduceti modul dupa care doriti sa facem filtrarea:\n";
    cout << "| -1 | -- | mai mic decat suprafata | --\n";
    cout << "| 0 | -- | egal cu suprafata | --\n";
    cout << "| 1 | -- | mai mare decat suprafata | --\n";
    cout<<"--------------------------------------------\n";
    cin >> mod;

    if (mod != -1 && mod != 0 && mod != 1){
        cout<<"--------------------------------------------\n";
        cout<<"Optiunea introdusa este invalida!\n";
        cout<<"--------------------------------------------\n";
        return;
    }

    cout<<"Introduceti suprafata dupa care sortam:\n";
    cin>>suprafata;

    vector<Locatar> filtru = serv.filterSuprafata(suprafata, mod);

    if (filtru.empty()){
        cout<<"--------------------------------------------\n";
        cout << "Nu exista inregistrari cu acest tip!\n";
        cout<<"--------------------------------------------\n";
    }
    else{
        int i = 0;
        cout<<"---------------Lista Filtrata---------------\n";
        for (const Locatar& l : filtru) {
            i++;
            cout<<"Inregistrarea filtrata nr: " << i << "\nProprietar apartament " << l.get_numeProprietar() << "\nTip apartament "
                << l.get_tipApartament()<< "\nNumar apartament " << l.get_apartament() << "\nSuprafata apartament " << l.get_suprafata()<< "\n\n";
        }
        cout<<"--------------------------------------------\n";
    }


}


void LocatarUI::uiPrint() {
    vector<Locatar> loc = serv.getAll();
    int i = 0;
    if (loc.empty()) {
        cout<<"--------------------------------------------\n";
        cout<<"Nu exista inregistrari in program!\n";
        cout<<"--------------------------------------------\n";
        return;
    }
    cout<<"---------------Lista Locatari---------------\n";
    for (const Locatar& l : loc) {
        i++;
        cout<<"Inregistrarea nr: " << i << "\nProprietar apartament " << l.get_numeProprietar() << "\nTip apartament "
            << l.get_tipApartament()<< "\nNumar apartament " << l.get_apartament() << "\nSuprafata apartament " << l.get_suprafata()<< "\n\n";
    }
    cout<<"--------------------------------------------\n";
}

void LocatarUI::run() {
    int ok = 1;
    while (ok){
        int cmd = 0;
        menu();
        cout<<"Citeste comanda: \n";
        cin>>cmd;

        if (cmd == 0) {
            cout<<"--------------------------------------------\n";
            cout << "Ai iesit din program!\n";
            cout<<"--------------------------------------------\n";
            ok = 0;
        }
        else if (cmd == 1){
            uiAdd();
        }
        else if (cmd == 2){
            uiPrint();
        }
        else if (cmd == 3){
            uiModify();
        }
        else if (cmd == 4){
            uiDelete();
        }
        else if (cmd == 5){
            uiCauta();
        }
        else if (cmd == 6){
            uiFilterTip();
        }
        else if (cmd == 7){
            uiFilterSuprafata();
        }
        else
            cout<<"Optiune invalida!\n";
    }

}



