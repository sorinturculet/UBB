from domain.student import Student
from domain.StudentValidator import *
from repository.StudentRepo import *

class StudentController:
    def __init__(self,repository:StudentRepository,validator:StudentValidator):
        self.__repo=repository
        self.__validator=validator
    def add_student(self,id,name):
        '''
        Adds student after validating it
        :param id: int
        :param name: str
        :return:
        '''
        Student1=Student(id,name)
        self.__validator.StudentValidator(Student1)
        self.__repo.addStudent(Student1)
    def delete_student(self,id):
        '''
        Deletes student if it exists
        :param id: int
        :return:
        '''
        return self.__repo.deleteStudent(id)
    def find_student(self,id):
        '''
        Finds Student by id
        :param id: int
        :return:
        '''
        return self.__repo.find(id)
    def update_student(self,id,newname):
        '''
        updates student after validating data
        :param id:
        :param newname:
        :return:
        '''
        student=Student(id,newname)
        self.__validator.StudentValidator(student)
        self.__repo.update_student(id,newname)
    def print_student(self):
        '''
        returns all the students
        :return:
        '''
        return self.__repo.getAll()
