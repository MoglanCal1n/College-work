//
// Created by Moglan Calin-Stefan on 3/29/24.
//

#include "LocatarService.h"

#include <utility>

void LocatarService::add(string numeProprietar, string tipApartament, int apartament, int suprafata){
    Locatar l{std::move(numeProprietar), std::move(tipApartament), apartament, suprafata};

    rep.storeLocatar(l);
}

void LocatarService::modify(int apartament_mod, string numeProprietar, string tipApartament, int suprafata) {
    rep.modifyLocatar(Locatar(std::move(numeProprietar), std::move(tipApartament), apartament_mod, suprafata),apartament_mod);
}

void LocatarService::deleteL(int apartament_mod) {
    rep.deleteLocatar(apartament_mod);
}

vector<Locatar> LocatarService ::getAll() {
    return rep.getAll();
}

bool LocatarService::cauta(int apartament_cauta) {
    vector<Locatar> L = getAll();
    for (Locatar& l : L){
        if (l.get_apartament() == apartament_cauta)
            return true;
    }
    return false;
}

vector<Locatar> LocatarService::filterTip(const string& tipApartament) {
    vector<Locatar> L = getAll();
    vector<Locatar> filtru;
    for (Locatar& l : L){
        if (l.get_tipApartament() == tipApartament)
            filtru.push_back(l);
    }

    return filtru;
}

vector<Locatar> LocatarService::filterSuprafata(int suprafata, int mod) {
    vector<Locatar> L = getAll();
    vector<Locatar> filtru;
    if (mod == -1)
        for (Locatar& l : L){
            if (l.get_suprafata() < suprafata)
                filtru.push_back(l);
        }
    else if (mod == 0)
        for (Locatar& l : L){
            if (l.get_suprafata() == suprafata)
                filtru.push_back(l);
        }
    else if (mod == 1)
        for (Locatar& l : L){
            if (l.get_suprafata() > suprafata)
                filtru.push_back(l);
        }

    return filtru;
}
