from domain.student import Student
from domain.subject import Subject
class event:
    def __init__(self,idstudent:int,idsubject:int,Mark:int):
        self.__idstudent=idstudent
        self.__idsubject=idsubject
        self.__mark=Mark
    def setStudent(self,idstudent:int):
        self.__idstudent=idstudent
    def setSubject(self,idsubject:int):
        self.__idsubject=idsubject
    def setMark(self,mark):
        self.__mark=mark
    def getStudent(self):
        return self.__idstudent
    def getSubject(self):
        return self.__idsubject
    def getMark(self):
        return self.__mark
    def __eq__(self, other):
        return self.getMark()==other.getMark() and self.getSubject()==other.getSubject() and self.getStudent()==other.getStudent()
    def __str__(self):
        return 'Student:'+str(self.getStudent())+"|"+'Subject:'+str(self.getSubject())+"|"+'Mark:'+str(self.getMark())