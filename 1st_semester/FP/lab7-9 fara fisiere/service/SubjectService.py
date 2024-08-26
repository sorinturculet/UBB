from domain.subject import *
from domain.SubjectValidator import *
from repository.SubjectRepo import *
class SubjectController:
    def __init__(self,repository:SubjectRepository,validator:SubjectValidator):
        self.__repo=repository
        self.__validator=validator
    def add_subject(self,id,name,professor):
        subject=Subject(id,name,professor)
        self.__validator.ValidateSubject(subject)
        self.__repo.addSubject(subject)
    def delete_subject(self,id):
        self.__repo.removeSubject(id)
    def find_subject(self,id):
        return self.__repo.find(id)
    def update_subject(self,id,newName,newProfessor):
        subjectnew=Subject(id,newName,newProfessor)
        self.__validator.ValidateSubject(subjectnew)
        self.__repo.updateSubject(id,newName,newProfessor)
    def get_all(self):
        return self.__repo.getAll()
