from termcolor import colored

class Mobilier:
    def __init__(self, cod, tip, nume, stock, pret):
        """
        Initializam clasa Mobilier
        :param cod: codul piesei de mobilier
        :param tip: tipul piesei de mobilier
        :param nume: numele piesei de mobilier
        :param stock: stockul disponibil
        :param pret: pretul piesei
        """

        self.__cod = cod
        self.__tip = tip
        self.__nume = nume
        self.__stock = stock
        self.__pret = pret

    """
    Getters si setters pentru clasa Mobilier
    """
    def getCod(self):
        return self.__cod
    def getTip(self):
        return self.__tip
    def getNume(self):
        return self.__nume
    def getStock(self):
        return self.__stock
    def getPret(self):
        return self.__pret
    
    def setTip(self, value):
        self.__tip = value
    def setNume(self, value):
        self.__nume = value
    def setStock(self, value):
        self.__stock = value
    def setPret(self, value):
        self.__pret = value

    def __eq__(self, other):
        return self.__cod == other.__cod and self.__tip == other.__tip and self.__nume == other.__nume and self.__stock == other.__stock and self.__pret == other.__pret
    def __str__(self):
        return colored("cod: ", "blue") + str(self.__cod) + "; tip: " + str(self.__tip) + "; nume: " + str(self.__nume) + "; stock: " + str(self.__stock) + "; pret: " + str(self.__pret) + colored("; ", "red")
    def __repr__(self):
        return str(self)
    
#teste
def test_entitate():
    mobilier = Mobilier("CI10", "corp iluminat", "Lampa Venetia", 12, 500)

    assert mobilier.getCod() == "CI10"
    assert mobilier.getTip() == "corp iluminat"
    assert mobilier.getNume() == "Lampa Venetia"
    assert mobilier.getStock() == 12
    assert mobilier.getPret() == 500

test_entitate()