#include "LocatarRepo.h"

string RepoException:: get_msg(){
    return msg;
}

void LocatarRepo::storeLocatar(const Locatar &l) {
    for (const Locatar& lc: Locatari ){
        if (lc.get_apartament() == l.get_apartament()){
            throw RepoException("--------------------------------------------\nUn apartament nu poate avea mai mult de un proprietar!\n--------------------------------------------\n");
        }
    }
    Locatari.push_back(l);
}

vector<Locatar> LocatarRepo::getAll() {
    return Locatari;
}

void LocatarRepo::modifyLocatar(const Locatar &l, int apartament) {
    int ok = 0, poz = 0;
    vector<Locatar> L = getAll();
    for (Locatar& loc: L){
        if (loc.get_apartament() == apartament){
            this -> Locatari[poz] = l;
            ok = 1;
            break;
        }
        poz++;
    }
    if (!ok)
        throw RepoException("--------------------------------------------\nDatele nu au putut fi modificate!\nApartamentul nu este inregistrat in program!\n--------------------------------------------\n");
}

void LocatarRepo::deleteLocatar(int apartament) {
    int ok = 0, poz = 0;
    vector<Locatar> L = getAll();
    for (Locatar& loc : L){
        if (loc.get_apartament() == apartament){
            this -> Locatari.erase(Locatari.begin() + poz);
            ok = 1;
            break;
        }
        poz++;
    }
    if (!ok)
        throw RepoException("--------------------------------------------\nDatele nu au putut fi sterse!\nApartamentul nu este inregistrat in program!\n--------------------------------------------\n");

}

