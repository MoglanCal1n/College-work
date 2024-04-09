#pragma once
#include <string>
#include <iostream>
#include <utility>
using std::cout;
using std::string;

class Locatar{
private:
    string numeProprietar;
    string tipApartament;
    int apartament, suprafata;
public:
    Locatar() =default;
    /**
     * functie care returneaza numele unui proprietar
     * @return string numeProprietar
     */
    [[nodiscard]] string get_numeProprietar() const;

    /**
     * functie care returneaza tipul unui apartament
     * @return string tipApartament
     */
    [[nodiscard]] string get_tipApartament() const;

    /**
     * functie care returneaza numarul unui apartament
     * @return int apartament
     */
    [[nodiscard]] int get_apartament() const;

    /**
     * functie care returneaza suprafata unui apartament
     * @return int suprafata
     */
    [[nodiscard]] int get_suprafata() const;

    /**
     * Constructor pentru apartament
     * @param numeProprietar string
     * @param tipApartament string
     * @param apartament int
     * @param suprafata int
     */
    Locatar(string numeProprietar, string tipApartament, int apartament, int suprafata):
    numeProprietar{std::move(numeProprietar)}, tipApartament{std::move(tipApartament)}, apartament{apartament}, suprafata{suprafata}{}

    Locatar(const Locatar&other){
        if (this != &other){
            this -> numeProprietar = other.numeProprietar;
            this -> tipApartament = other.tipApartament;
            this -> suprafata = other.suprafata;
            this -> apartament = other.apartament;
        }
    }

    ~Locatar(){}

    Locatar& operator=(const Locatar&other){
        if (this != &other){
            this -> numeProprietar = other.numeProprietar;
            this -> tipApartament = other.tipApartament;
            this -> suprafata = other.suprafata;
            this -> apartament = other.apartament;
        }

        return *this;
    }
};