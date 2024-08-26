from domain.subject import *
class SubjectRepository:
    def __init__(self):
        self.__Subjects=[]
    def find(self,id):
        '''
        Searches for a student by id
        :param id:  int
        :return: student or none if it doesnt exist
        '''
        for Subject in self.__Subjects:
            if Subject.getId()==id:
                return Subject
        return None
    def addSubject(self,Subject:Subject):
        '''
        Adds a subject to the list
        :param Subject: Subject
        :return:
        '''
        if self.find(Subject.getId()):
            raise ValueError("A subject with that id already exists")
        self.__Subjects.append(Subject)
    def removeSubject(self,id):
        '''
        Removes a subject by searching it by id
        :param id: int
        :return:
        '''
        SubjectToDelete = self.find(id)
        if SubjectToDelete is None:
            raise ValueError("These isn't a subject with this id")
        self.__Subjects.remove(Subject)
    def getAll(self):
        '''
        returns all subjects
        :return:
        '''
        return self.__Subjects
    def updateSubject(self,id,newName,newProfessor):
        '''
        updates a subject
        :param id: int
        :param newName:str
        :param newProfessor:str
        :return:
        '''
        subject=self.find(id)
        if subject:
            for subject2 in self.__Subjects:
                if subject2==subject:
                    subject2.setName(newName)
                    subject2.setProfessor(newProfessor)
        else:
            raise ValueError('Nu exista materie cu acest id')