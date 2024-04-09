#pragma once
#include "Locatar.h"
#include <utility>
#include <vector>
#include "VectorDinamicTemplate.h"
using std::vector;

class RepoException{
    string msg;
public:
    /**
     * constructor pentru clasa de exceptii
     * @param msg - string - mesajul exceptiei
     */
    explicit RepoException(string msg): msg{std::move(msg)}{}

    /**
     * functie care returneaza mesajul exceptiei care a fost aruncata
     * @return string msg
     */
    string get_msg();
};

class LocatarRepo {
private:
    vector<Locatar> Locatari;
public:

    /**
     * Functie care adauga in lista de Locatari un locatar
     * @param l locatarul pe care il adaugam
     */
    void storeLocatar(const Locatar& l);

    /**
     * Functie care modifica in lista de locatari un locatar
     * @param l locatarul cu care inlocuim
     * @param apartament nr apartamentului locatarului pe care il inlocuim
     */
    void modifyLocatar(const Locatar& l, int apartament);

    /**
     *Functie care sterge in lista de locatari un locatar
     * @param apartament nr apartamentului pe care il stergem
     */
    void deleteLocatar(int apartament);

    /**
     *Functie care returneaza toti locatarii din lista de locatari
     * @return
     */
    vector<Locatar> getAll();
};



