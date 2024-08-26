from domain.student import *
class StudentRepository:
    def __init__(self):
        self.__students=[]
    def find(self, id):
        """
        Gaseste task-ul cu id dat
        :param id: id-ul cautat
        :type id: int
        :return: task-ul cu id dat
        :rtype: Task
        """
        for Student in self.__students:
            if Student.getId() == id:
                return Student
        return None
    def addStudent(self, Student: Student):
        '''
        Adds a student to the list
        :param Student: Student
        :return:
        '''
        if self.find(Student.getId()):
            raise ValueError('A student with this id already exists.')
        self.__students.append(Student)
    def deleteStudent(self, id):
        '''
        Deletes a student by id
        :param id: int
        :return:
        '''
        StudentToDelete=self.find(id)
        if StudentToDelete is None:
            raise ValueError("These isn't a student with this id")
        self.__students.remove(Student)
    def update_student(self,id,newname):
        '''
        Updates a student
        :param id: int
        :param newname: str
        :return:
        '''
        StudentToUpdate=self.find(id)
        if StudentToUpdate:
            for student in self.__students:
                if student==StudentToUpdate:
                    student.setName(newname)
        else:
            raise ValueError("Nu exista student cu acest id")
    def getAll(self):
        '''
        returns all students
        :return:
        '''
        return self.__students
