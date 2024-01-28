from domain.entities import Mobilier
from domain.validators import MobilierValidator
import os
from termcolor import colored

class OperatiiMobilierFile:
    def __init__(self, filename):
        """
        Clasa constructor a Mobilei
        :param filename: fisierul din care citim si scrie
        """

        self.__mobilier = []
        file = os.path.abspath(filename)
        self.__filename = file
        self.__load_from_file()

    def __load_from_file(self):
        with open(self.__filename, "r") as f:
            lines = f.readlines()
            for line in lines:
                if line == "\n":
                    break
                cod, tip, nume, stock, pret = [elem.strip() for elem in line.split(',')]
                mobilier = Mobilier(cod, tip, nume, int(stock), float(pret))
                self.__mobilier.append(mobilier)
        
    def __save_to_file(self):
        with open(self.__filename, "w") as f:
            toate_piesele = self.returneaza_mobilier()
            for piesa in toate_piesele:
                piesa_de_salvat = str(piesa.getCod()) + "," + str(piesa.getTip()) + "," + str(piesa.getNume()) + "," + str(piesa.getStock()) + "," + str(piesa.getPret()) + "\n"
                f.write(piesa_de_salvat)

    def cautare_tip(self, tip):
        """
        Cautam un mobilier dupa tip
        :param tip: tipul mobilierului de cautat
        :param iesire: mobila 
        """
        toate_dupa_tip = []
        for mobilier in self.__mobilier:
            if mobilier.getTip() == tip:
                toate_dupa_tip.append([mobilier.getCod(), mobilier.getTip(), mobilier.getNume(), int(mobilier.getStock()), float(mobilier.getPret())])
        if toate_dupa_tip == []:
            raise ValueError(colored("Nu exista niciun mobilier cu acest tip!", "red"))
        return toate_dupa_tip
    
    def cumparare(self, cod, nr):
        """
        
        """
        mobila = []
        ok = 1
        cnt  = 0
        for mobilier in self.__mobilier:
            if mobilier.getCod() == cod and mobilier.getStock() >= nr:
                ok = 0
                mobila.append(mobilier.getNume())
                mobila.append(int(mobilier.getPret()) * nr)
                mobila.append(int(mobilier.getStock()) - nr)
                self.__mobilier[cnt].setStock(int(mobilier.getStock()) - nr)
                break
            cnt += 1
        if ok == 1:
            raise ValueError(colored("Nu exista acest cod in lista de mobiliere!", "red"))
        self.__save_to_file()
        return mobila
        
    
    def returneaza_mobilier(self):
        return self.__mobilier
        
#test

def test_cautare():
    repo = OperatiiMobilierFile("test_repo.txt")

    assert repo.cautare_tip("corp iluminat") == [["CI10", "corp iluminat", "Lampa Venetia", 12, 500], ["CI11", "corp iluminat", "Lampa Roma", 11, 450]]
    assert repo.cautare_tip("dulap") == [["CI12", "dulap", "Dulap Maro", 10, 230]]

def test_cumparare():
    repo = OperatiiMobilierFile("test_repo.txt")

    assert repo.cumparare("CI10", 10) == ["Lampa Venetia", 5000, 2]
    assert repo.cumparare("CI12", 4) == ["Dulap Maro", 920, 6]

test_cautare()
test_cumparare()