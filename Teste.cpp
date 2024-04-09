//
// Created by Moglan Calin-Stefan on 3/30/24.
//
#include <iostream>
#include <assert.h>
#include "Locatar.h"
#include "LocatarRepo.h"
#include "LocatarService.h"
#include "Teste.h"

using std::cout;

LocatarRepo rep ;
LocatarService serv{ rep };

void test_All(){
    cout<<"-----------------------\n";
    cout<<"Incepe rularea testelor\n";
    test_domain();
    test_repo();
    test_service();
    cout<<"Toate testele au trecut cu succes!\n";
    cout<<"-----------------------\n";
}

void test_domain(){
    vector<Locatar> l;
    auto loc = Locatar{"Moglan", "Garsoniera", 16, 55};
    assert(loc.get_numeProprietar() == "Moglan");
    assert(loc.get_tipApartament() == "Garsoniera");
    assert(loc.get_apartament() == 16);
    assert(loc.get_suprafata() == 55);
}

void test_repo(){
    auto loc = Locatar{"Moglan", "Garsoniera", 16, 55};
    rep.storeLocatar(loc);
    vector<Locatar> l = rep.getAll();
    assert(l.size() == 1);
    try {
        auto loc2 = Locatar{"Moglan", "Garsoniera", 16, 55};
        rep.storeLocatar(loc2);
        assert(false);
    }
    catch(RepoException& e){
        assert(true);
        assert(e.get_msg() == "--------------------------------------------\nUn apartament nu poate avea mai mult de un proprietar!\n--------------------------------------------\n");
    }

    assert(l[0].get_suprafata() == 55);
    auto loc3 = Locatar{"Montana", "Inchisoare", 24, 15};
    rep.modifyLocatar(loc3, 16);
    try{
        rep.modifyLocatar(loc3, 16);
        assert(false);
    }
    catch (RepoException& ex){
        assert(true);
        assert(ex.get_msg() == "--------------------------------------------\nDatele nu au putut fi modificate!\nApartamentul nu este inregistrat in program!\n--------------------------------------------\n");
    }

    try{
        rep.deleteLocatar(7);
        assert(false);
    }
    catch (RepoException& e){
        assert(true);
        assert(e.get_msg() == "--------------------------------------------\nDatele nu au putut fi sterse!\nApartamentul nu este inregistrat in program!\n--------------------------------------------\n");
    }
    auto loc4 = Locatar{"Ghita", "Mare", 20, 30};
    rep.storeLocatar(loc4);
    assert(l.size() == 1);
    rep.deleteLocatar(20);

}

void test_service(){
    serv.add("Motan", "Chifoi", 12, 28);
    vector<Locatar> l = serv.getAll();
    assert(l[1].get_numeProprietar() == "Motan");

    serv.modify(12, "Moglan", "Faiar", 60);
    vector<Locatar> l1 = serv.getAll();
    assert(l1[1].get_numeProprietar() == "Moglan");

    serv.deleteL(12);
    vector<Locatar> l2 = serv.getAll();
    assert(l2.size() == 1);


    bool valid = serv.cauta(69);
    assert(valid == false);

    serv.add("Miau", "Miau", 54, 34);
    valid = serv.cauta(54);
    assert(valid == true);

    vector<Locatar> l3 = serv.filterTip("Miau");
    assert(l3.size() == 1);

    vector<Locatar> l4 = serv.filterSuprafata(50, -1);
    assert(l4.size() == 2);

    vector<Locatar> l5 = serv.filterSuprafata(34, 0);
    assert(l5.size() == 1);

    vector<Locatar> l6 = serv.filterSuprafata(30, 1);
    assert(l6.size() == 1);

}