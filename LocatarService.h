#pragma once
#include "Locatar.h"
#include "LocatarRepo.h"
#include <string>
using std::string;

class LocatarService {
private:
    LocatarRepo& rep;
public:
    /**
     * constructor pentru clasa LocatarService
     * @param rep LocatarRep&
     */
    explicit LocatarService(LocatarRepo& rep):rep {rep}{}

    /**
     * Functie care adauga un locatar
     * @param numeProprietar
     * @param tipApartament
     * @param apartament
     * @param suprafata
     */
    void add(string numeProprietar, string tipApartament, int apartament, int suprafata);

    /**
     * Functie care modifica un locatar
     * @param apartament_mod numarul apartamentului
     * @param numeProprietar
     * @param tipApartament
     * @param suprafata
     */
    void modify(int apartament_mod ,string numeProprietar, string tipApartament,  int suprafata);

    /**
     * Functie care sterge un locatar
     * @param apartament_mod numarul apartamentului
     */
    void deleteL(int apartament_mod);

    /**
     * Functie care cauta un locatar
     * @param apartament_cauta numarul apartamentului
     * @return 1 daca a gasit locatarul
     *         0 daca nu l a gasit
     */
    bool cauta(int apartament_cauta);

    /**
     * functie de filtrare dupa tip
     * @param tipApartament
     * @return lista de locatari care respecta filtrul
     */
    vector<Locatar> filterTip(const string& tipApartament);

    /**
     * Functie de filtrare dupa suprafata
     * @param suprafata filtrul de suprafata
     * @param mod -1 daca vrem sa sortam apartamentele cu o suprafata mai mica decat filtrul
     *             0 daca vrem sa sortam apartamentele cu o suprafata egala cu filtrul
     *             1 daca vrem sa sortam apartamentele cu o suprafata mai mare decat filtrul
     * @return lista de locatari care respecta filtrul
     */
    vector<Locatar> filterSuprafata(int suprafata, int mod);

    /**
     * Functie care returneaza toti locatarii
     * @return rep.Locatari
     */
    vector<Locatar> getAll();
};





