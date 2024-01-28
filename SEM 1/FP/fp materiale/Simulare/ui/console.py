from termcolor import colored

def printMeniu():
    """
    Printam meniul
    """
    print("Va rugam sa alegeti o optiune din cele de mai jos:")
    print("   1) cautati mobiliere pe baza unui tip dat;")
    print("   2) cumparari o piesa de mobilier;")
    print("   0) iesiti din aplicatie.")

class Console:
    def __init__(self, srv):
        """
        Initializam consola 
        :param srv: service-ul mobilierului
        """
        self.__srv = srv

    def __search_tip(self):
        """
        Cautam mobilierele dupa tip
        """
        try:
            tip = input("Introduceti tipul piesei de cautat: ")
            lista = self.__srv.search_tip(tip)
            underlined_string = "    " + "\033[4m" + "Mobiliere cu acelasi tip sunt:" + "\033[0m"

            print("\n")
            print(colored(underlined_string, "red"))
            print("\n")

            for elem in lista:
                print(colored("cod: ", "blue"), end = " ")
                print(elem[0], end = "  ")
                print(colored("tip: ", "green"), end = " ")
                print(elem[1], end = "  ")
                print(colored("nume: ", "yellow"), end = " ")
                print(elem[2], end = "  ")
                print(colored("stock: ", "magenta"), end = " ")
                print(elem[3], end = "  ")
                print(colored("pret: ", "cyan"), end = " ")
                print(elem[4])
            print("\n")
        except ValueError as ve:
            print(ve)

    def __buy(self):
        """
        Modificam mobilierele de cumparat
        """
        try:
            cod = input("Introduceti codul mobilierului: ")
            numar = int(input("Introduceti numarul de piese: "))
            print("\n")
            mobilier = self.__srv.buy(cod, numar)
            print("Mobilierul este:\n")
            print(colored("nume: ", "blue"), end = " ")
            print(mobilier[0], end = "  ")
            print(colored("pret total: ", "green"), end = " ")
            print(mobilier[1], end = "  ")
            print(colored("stock ramas: ", "yellow"), end = " ")
            print(mobilier[2], end = "  ")
            print("\n")
        except ValueError as ve:
            print(ve)

    def show_all(self):
        """
        Returnam lista de mobiliere
        """
        return self.__srv.get_all()
    
    def show_ui(self):
        print("Bine ati venit la firma noastra de mobila!\n")

        exit = False
        while not exit:
            print("Lista de mobila: ", self.show_all())
            print("\n")

            printMeniu()
            optiune = input("Introduceti cerinta: ").strip()

            if optiune == '0':
                print("La revedere!\n")
                exit = True
            else:
                if optiune == '1':
                    self.__search_tip()
                elif optiune == '2':
                    self.__buy()
                else:
                    print(colored("Comanda invalida!\n", "red"))