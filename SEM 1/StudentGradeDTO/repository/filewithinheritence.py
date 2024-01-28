'''
Created on Nov 28, 2014

@author: istvan
'''
from repository.inmemory import StudentRepository
class StudentFile2Repo(StudentRepository):
    def __init__(self,nF):
        StudentRepository.__init__(self)
        self.__nFis = nF
    
    def __storeALL(self):
        f = open(self.__nFis,"w")
        all= StudentRepository.getAll(self)
        for st in all:
            f.write(st.getId()+""+st.getName())
            f.write("\n")
        f.close()
        
    def store(self, st):
        StudentRepository.store(self, st)
        self.__storeALL()