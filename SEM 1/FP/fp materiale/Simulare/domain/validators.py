from domain.entities import Mobilier
from termcolor import colored

class MobilierValidator:
    def valideaza_mobilierul(self, mobila):
        """
        Validam clasa Mobila
        :param mobila: mobilierul de validat
        """
        erori = []
        if mobila.getCod() == "":
            erori.append(colored("Codul mobilei nu poate fi vid!", "red"))
        if mobila.getNume() == "":
            erori.append(colored("Numele mobilei nu poate fi vid!", "red"))
        if mobila.getTip() == "":
            erori.append(colored("Tipul mobilei nu poate fi vid!", "red"))
        if mobila.getStock() < 0:
            erori.append(colored("Stockul mobilei nu poate fi negativ!", "red"))
        if mobila.getPret() < 0:
            erori.append(colored("Pretul mobilei nu poate fi negativ!", "red"))
        
        if len(erori) > 0:
            raise ValueError(erori[0])
        
#teste
def test_validator():
    validator = MobilierValidator()

    mobilier = Mobilier("CI10", "corp iluminat", "Lampa Venetia", 12, 500)
    validator.valideaza_mobilierul(mobilier)

    mobilier = Mobilier("", "corp iluminat", "Lampa Venetia", 12, 500)
    try:
        validator.valideaza_mobilierul(mobilier)
        assert False
    except:
        assert True
    
    mobilier = Mobilier("CI10", "", "Lampa Venetia", 12, 500)
    try:
        validator.valideaza_mobilierul(mobilier)
        assert False
    except:
        assert True
    
    mobilier = Mobilier("CI10", "corp iluminat", "", 12, 500)
    try:
        validator.valideaza_mobilierul(mobilier)
        assert False
    except:
        assert True

    mobilier = Mobilier("CI10", "corp iluminat", "Lampa Venetia", -10, 500)
    try:
        validator.valideaza_mobilierul(mobilier)
        assert False
    except:
        assert True
    
    mobilier = Mobilier("CI10", "corp iluminat", "Lampa Venetia", 12, -100)
    try:
        validator.valideaza_mobilierul(mobilier)
        assert False
    except:
        assert True

test_validator()