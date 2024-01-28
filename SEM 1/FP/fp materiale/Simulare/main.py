from domain.entities import Mobilier
from domain.validators import MobilierValidator
from repository.repo import OperatiiMobilierFile
from service.service import MobilierService
from ui.console import Console

Mobila = MobilierService(OperatiiMobilierFile("mobilier.txt"), MobilierValidator())

ui = Console(Mobila)

ui.show_ui()