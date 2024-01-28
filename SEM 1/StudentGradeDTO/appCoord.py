from domain.validators import StudentValidator
from domain.validators import GradeValidator
from repository.inmemory import StudentRepository
from repository.inmemory import GradeRepository
from repository.file import StudentFileRepository
from repository.file import GradeFileRepository
from controllers.controllers import StudentController
from controllers.controllers import GradeController

from ui.console import ConsoleUI
from repository.filewithinheritence import StudentFile2Repo

#Application coordinator
#Use dependency injection pattern to asemble the application

#create a validator
val = StudentValidator()

#create repository
# repo = StudentRepository()

# repo = StudentFileRepository("students.txt")
repo = StudentFile2Repo("a.txt")

#create controller and inject dependencies
ctr = StudentController(val, repo)

#create Grade controller
#gradeRepo = GradeRepository()
gradeRepo = GradeFileRepository("grades.txt")

ctrgr =  GradeController(gradeRepo, GradeValidator(), repo)

#create console ui and provide (inject) the controller
ui = ConsoleUI(ctr,ctrgr)
ui.startUI()