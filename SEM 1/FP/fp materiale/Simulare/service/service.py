from domain.entities import Mobilier
from domain.validators import MobilierValidator
from repository.repo import OperatiiMobilierFile

class MobilierService:
    def __init__(self, repo, validator):
        """
        Initializam service-ul pt a lucra cu controllerul GRASP
        :param repo: repository-ul
        :param validator: validatorul unei piese de mobilier
        """
        self.__repo = repo
        self.__validator = validator

    def search_tip(self, tip):
        """
        Cautam piesele de mobilier
        :param tip: tip-ul pieselor de mobilier de cautat
        """
        return self.__repo.cautare_tip(tip)

    def buy(self, cod, nr):
        """
        Cumparam o piesa de mobilier si modifica
        """
        return self.__repo.cumparare(cod, nr)
    
    def get_all(self):
        return self.__repo.returneaza_mobilier()
    
#teste
def test_search_tip():
    repo = MobilierService(OperatiiMobilierFile("test_srv.txt"), MobilierValidator())

    assert repo.search_tip("corp iluminat") == [["CI10", "corp iluminat", "Lampa Venetia", 12, 500], ["CI11", "corp iluminat", "Lampa Roma", 11, 450]]
    assert repo.search_tip("dulap") == [["CI12", "dulap", "Dulap Maro", 10, 230]]

def test_buy():
    repo = MobilierService(OperatiiMobilierFile("test_srv.txt"), MobilierValidator())

    assert repo.buy("CI10", 10) == ["Lampa Venetia", 5000, 2]
    assert repo.buy("CI12", 4) == ["Dulap Maro", 920, 6]

test_search_tip()
test_buy()